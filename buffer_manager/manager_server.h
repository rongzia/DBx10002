//
// Created by rrzhang on 2020/6/3.
//

#ifndef DBX1000_MANAGER_SERVER_H
#define DBX1000_MANAGER_SERVER_H

#include <cstdint>
#include <string>
#include <map>

class workload;

namespace dbx1000 {

    class Buffer;
    class Index;
    class Page;
    class TableSpace;
    class ServerLockTable;
//    class Stats;
    class BufferManagerClient;


    class ManagerServer {
    public:
        ManagerServer();
        ~ManagerServer();
        ManagerServer(const ManagerServer&) = delete;
        ManagerServer &operator=(const ManagerServer&) = delete;

        struct InstanceInfo {
            uint16_t instance_id;
            std::string host;
            bool init_done;
            BufferManagerClient* buffer_manager_client;
        };

        /// getter and setter
        InstanceInfo* instances();
        ServerLockTable* lock_table();

    private:
        bool init_done_;
        std::map<int, std::string> hosts_map_;
        InstanceInfo* instances_;

        workload* m_workload_;
        Buffer * buffer_;
        TableSpace* table_space_;
        Index* index_;
        ServerLockTable* lock_table_;
//        Stats* stats_;
    };
}


#endif //DBX1000_MANAGER_SERVER_H