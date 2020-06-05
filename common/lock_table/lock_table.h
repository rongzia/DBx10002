//
// Created by rrzhang on 2020/6/2.
//

#ifndef STORAGE_LOCK_TABLE_H
#define STORAGE_LOCK_TABLE_H

#include <unordered_map>
#include <atomic>
#include <mutex>
#include <condition_variable>
namespace dbx1000 {
    enum class LockMode{
        X,  /// 写锁
        S,  /// 读锁
        N,  /// 无锁
    };

    struct LockNode {
        LockNode(uint16_t nodeid, bool val = false, LockMode mode = LockMode::N, uint16_t count = 0);
        uint16_t node_id;
        uint16_t count;
        bool valid;
        LockMode lock_mode;
        std::atomic_flag lock;
        std::mutex mtx;
        std::condition_variable cv;
    };

    class LockTable {
    public:
        void Init(uint64_t start_page, uint64_t end_page);
        bool Lock(uint64_t page_id, LockMode mode);
        bool UnLock(uint64_t page_id);
        bool LockGet(uint64_t page_id, uint16_t node_i, LockMode mode);
        bool LockRelease(uint64_t page_id, uint16_t node_i, LockMode mode);
        bool LockGetBatch(uint64_t start, uint64_t end, uint16_t node_i, LockMode mode);
        bool LockReleaseBatch(uint64_t start, uint64_t end, uint16_t node_i, LockMode mode);

        /// getter and setter
        std::unordered_map<uint64_t, LockNode*> lock_table();

//    private:
        std::unordered_map<uint64_t, LockNode*> lock_table_;
    };
}


#endif //STORAGE_LOCK_TABLE_H
