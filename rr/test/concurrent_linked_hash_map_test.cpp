#define TBB_PREVIEW_CONCURRENT_LRU_CACHE 1
// #define NDEBUG
#include <tbb/concurrent_hash_map.h>
#include <tbb/concurrent_lru_cache.h>
#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include "../include/rr/concurrent_linked_hash_map.h"
#include "../include/rr/profiler.h"
using namespace std;

#include <map>

int global_num_thd = 30;
int global_batch = 100000;

void single_test()
{
    class A {
    public:
        A() { cout << "A()" << endl; }
        A(const A& a) { cout << "const A&" << endl; }
        A(A&& a) { cout << "A&&" << endl; }
        A* operator=(const A& a) { cout << "const A& operator=" << endl; }
        A* operator=(A&& a) { cout << "A&& operator=" << endl; }
    };
    rr::ConcurrentLinkedHashMap<int, A> map(5);
    A res;
    A a;
    map.Put(1, a, res);

    cout << endl << endl;

    A b;
    map.Put(2, std::move(b), res);
}

void multi_thd_read_after_write()
{
    int batch = global_batch;
    int num_thd = global_num_thd;
    rr::ConcurrentLinkedHashMap<int, int>* map = new rr::ConcurrentLinkedHashMap<int, int>(batch * num_thd / 2);
    // rr::ConcurrentLinkedHashMap<int, int> map(batch * num_thd);

    auto Write = [&map, batch](int thd_id) -> void
    {
        bool has_res;
        for (int i = thd_id * batch; i < (thd_id + 1) * batch; i++)
        {
            int res;
            bool is_new = map->Put(i, i, res, 0);
            if (!is_new)
                assert(res >= 0);
            // cout << i << endl;
        }
    };
    auto Read = [&map, num_thd, batch](int thd_id) -> void
    {
        bool has_res;
        for (int i = 0; i < num_thd * batch; i++)
        {
            int res;
            bool find = map->Get(i, res, 0);
            if (find)
                assert(res >= 0);
            // map.getQuietly(i, has_res);
            // cout << i << endl;
        }
    };

    rr::Profiler profiler;
    profiler.Start();
    std::vector<std::thread> v_thread;
    for (auto thd = 0; thd < num_thd; thd++)
    {
        v_thread.emplace_back(Write, thd);
    }
    for (auto thd = 0; thd < num_thd; thd++)
    {
        v_thread[thd].join();
    }
    profiler.End();
    cout << "ConcurrentLinkedHashMap write time: " << profiler.Micros() << endl;
    map->check();
    // for(auto i = 0; i < map.ThreadNum(); i++) {
    //     map.AsyncQueue()[i]->check();
    // }

    v_thread.clear();
    profiler.Clear();
    profiler.Start();
    for (auto thd = 0; thd < num_thd; thd++)
    {
        v_thread.emplace_back(Read, thd);
    }
    for (auto thd = 0; thd < num_thd; thd++)
    {
        v_thread[thd].join();
    }
    profiler.End();
    cout << "ConcurrentLinkedHashMap read  time: " << profiler.Micros() << endl;
    // map->check();
    // for(auto i = 0; i < map.ThreadNum(); i++) {
    //     map.AsyncQueue()[i]->check();
    // }
    // while(1);
    delete map;
}

void multi_thd_read_while_write()
{
    int batch = global_batch;
    int num_thd = global_num_thd;
    rr::ConcurrentLinkedHashMap<int, int>* map = new rr::ConcurrentLinkedHashMap<int, int>(batch * num_thd / 2);

    auto Write = [&map, batch](int thd_id) -> void
    {
        bool has_res;
        for (int i = thd_id * batch; i < (thd_id + 1) * batch; i++)
        {
            int res;
            bool is_new = map->Put(i, i, res, i);
            if (!is_new)
                assert(res >= 0);
            // cout << i << endl;
        }
    };
    auto Read = [&map, num_thd, batch](int thd_id) -> void
    {
        bool has_res;
        for (int i = 0; i < num_thd * batch; i++)
        {
            int res;
            bool find = map->Get(i, res, i);
            if (find)
                assert(res >= 0);
            // map.getQuietly(i, has_res);
            // cout << i << endl;
        }
    };
    auto Delete = [&map, num_thd, batch](int thd_id) -> void
    {
        bool has_res;
        for (int i = 0; i < num_thd * batch; i++)
        {
            int res;
            bool find = map->Remove(i, res, i);
            if (find)
                assert(res >= 0);
            // map.getQuietly(i, has_res);
            // cout << i << endl;
        }
    };

    rr::Profiler profiler;
    profiler.Start();
    std::vector<std::thread> v_thread;

    for (auto thd = 0; thd < num_thd; thd++)
    {
        v_thread.emplace_back(Write, thd);
    }
    for (auto thd = 0; thd < num_thd; thd++)
    {
        v_thread.emplace_back(Read, thd);
    }
    // for(auto thd = 0; thd < num_thd*2; thd++) {
    //     v_thread[thd].join();
    // }
    for (auto thd = 0; thd < num_thd; thd++)
    {
        v_thread.emplace_back(Delete, thd);
    }
    for (auto thd = 0; thd < num_thd * 3; thd++)
    {
        v_thread[thd].join();
    }
    profiler.End();
    cout << "ConcurrentLinkedHashMap total time: " << profiler.Micros() << endl;
    map->check();
    // for(auto i = 0; i < map.ThreadNum(); i++) {
    //     map.AsyncQueue()[i]->check();
    // }
    delete map;
}

void multi_thd_cc_hash_map()
{
    int batch = global_batch;
    int num_thd = global_num_thd;
    tbb::concurrent_hash_map<int, int*> map;

    auto Write = [&map, batch](int thd_id) -> void
    {
        bool has_res;
        for (int i = thd_id * batch; i < (thd_id + 1) * batch; i++)
        {
            tbb::concurrent_hash_map<int, int*>::accessor acc;
            int* a = new int();
            *a = i;
            map.insert(acc, make_pair(i, a));
        }
    };
    auto Read = [&map, num_thd, batch](int thd_id) -> void
    {
        bool has_res;
        for (int i = 0; i < num_thd * batch; i++)
        {
            tbb::concurrent_hash_map<int, int*>::const_accessor acc;
            map.find(acc, i);
        }
    };

    rr::Profiler profiler;
    profiler.Start();
    std::vector<std::thread> v_thread;
    for (auto thd = 0; thd < num_thd; thd++)
    {
        v_thread.emplace_back(Write, thd);
    }
    for (auto thd = 0; thd < num_thd; thd++)
    {
        v_thread[thd].join();
    }
    profiler.End();
    cout << "concurrent_hash_map write time: " << profiler.Micros() << endl;

    v_thread.clear();
    profiler.Clear();
    profiler.Start();
    for (auto thd = 0; thd < num_thd; thd++)
    {
        v_thread.emplace_back(Read, thd);
    }
    for (auto thd = 0; thd < num_thd; thd++)
    {
        v_thread[thd].join();
    }
    profiler.End();
    cout << "concurrent_hash_map read  time: " << profiler.Micros() << endl;
}

void test_concurrent_hash_map()
{
    tbb::concurrent_hash_map<int, int*> map;
    int* v1 = new int(), * v2 = new int();
    *v1 = 1;
    *v2 = 2;
    map.insert(make_pair(1, v1));
    map.insert(make_pair(2, v2));
    int* res = nullptr;
    for (int i = 0; i < 1; i++)
    {
        tbb::concurrent_hash_map<int, int*>::accessor acc;
        bool find = map.find(acc, 1);
        cout << "find: " << find << endl;
        res = acc->second;
        cout << "acc->second: " << *(acc->second) << endl;
        if (find)
        {
            bool deleted = map.erase(acc);
            // cout << "acc->second: " << *(acc->second) << endl;
            cout << "res: " << *res << endl;
        }
    }
    cout << "res: " << *res << endl;

    tbb::concurrent_hash_map<int, int*>::accessor acce;
    int* v3 = new int();
    *v3 = 3;
    bool insert = map.insert(acce, 2);
    cout << "insert 2: " << (insert ? "new" : "old") << ", value: " << *(acce->second) << endl;
}

tbb::concurrent_hash_map<int, int*> globalMap;
std::atomic<bool> flag1;
std::atomic<bool> flag2;
std::atomic<bool> flag3;
std::atomic<bool> flag4;
void fun1()
{
    while (1)
    {
        if (flag2.load())
        {
            tbb::concurrent_hash_map<int, int*>::accessor acce;
            // bool find = globalMap.find(acce, 1);
            // cout << "fun1 find 1: " << find << ", map[1]: " << *(acce->second) << endl;
            bool insert = globalMap.insert(acce, 1);
            cout << "fun1 insert 1: " << insert << endl;
            cout << "fun1 old value: " << *(acce->second) << endl;
            int* v = new int();
            *v = 2;
            acce->second = v;
            cout << "fun1 inserted value: " << *(acce->second) << endl;
            flag3.store(1);
            break;
        }
    }
}

void fun2()
{
    while (1)
    {
        if (flag1.load())
        {
            tbb::concurrent_hash_map<int, int*>::accessor acce;
            bool res = globalMap.insert(acce, 1);
            cout << "fun2 insert 1: " << res << endl;
            int* v = new int();
            *v = 1;
            acce->second = v;
            cout << "fun2 inserted value: " << *(acce->second) << endl;
            flag2.store(true);
            break;
        }
    }

    while (1)
    {
        if (flag3.load())
        {
            tbb::concurrent_hash_map<int, int*>::accessor acce;
            bool find = globalMap.find(acce, 1);
            cout << "fun2 find 1: " << find << ", map[1]: " << *(acce->second) << endl;
            break;
        }
    }
}
int main()
{
    /**
     * @brief fun1 and fun2，测试map的插入删除
     *
     */
     // {
     //     flag1.store(false);
     //     flag2.store(false);
     //     flag3.store(false);
     //     flag4.store(false);

     //     thread t1(fun1);
     //     thread t2(fun2);
     //     flag1.store(1);
     //     t1.join();
     //     t2.join();
     // }

    // {
    //     single_test();
    // }
    {
        multi_thd_read_after_write();
        cout << endl << endl;

        // multi_thd_read_while_write();
        // cout << endl << endl;

        multi_thd_cc_hash_map();
    }
    return 0;
}
// g++ concurrent_linked_hash_map_test.cpp -o concurrent_linked_hash_map_test.exe -ltbb -lpthread -g 
// g++ concurrent_linked_hash_map_test.cpp -o concurrent_linked_hash_map_test.exe -ltbb -lpthread -O3 –DNDEBUG