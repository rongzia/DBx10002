

#include <sched.h>
#include <thread>
#include <server/manager_server.h>

#include "ycsb_wl.h"

//#include "ycsb_txn.h"
#include "global.h"
#include "helper.h"
#include "buffer.h"
//#include "ycsb.h"
//#include "thread.h"
#include "table.h"
//#include "row.h"
//#include "index_hash.h"
//#include "index_btree.h"
#include "catalog.h"
#include "manager.h"
//#include "row_lock.h"
//#include "row_ts.h"
#include "row_mvcc.h"
//#include "query.h"

#include "leveldb/db.h"
#include "profiler.h"
#include "row_item.h"

std::atomic<int> ycsb_wl::next_tid;

ycsb_wl::ycsb_wl(){
    cout << "ycsb_wl::ycsb_wl()" << endl;
}

ycsb_wl::~ycsb_wl(){
    cout << "ycsb_wl::~ycsb_wl()" << endl;
}

RC ycsb_wl::init() {
	workload::init();
	next_tid = 0;
    init_schema(std::string("/home/zhangrongrong/CLionProjects/DBx1000/server/workload/YCSB_schema.txt"));

    /// init buffer here, because 'the_table' can be use util schema be inititaled
    dbx1000::Buffer* buffer = new dbx1000::Buffer(g_synth_table_size / 10, the_table->get_schema()->get_tuple_size(), "/home/zhangrongrong/dbx1000_leveldb");
    buffer_.reset(buffer);

	init_table();
	return RCOK;
}

RC ycsb_wl::init_schema(string schema_file) {
	workload::init_schema(schema_file);
	the_table = tables["MAIN_TABLE"];
//	the_index = indexes["MAIN_INDEX"];
	return RCOK;
}
//! 数据是分区的，每个区间的 key 都是 0-g_synth_table_size / g_part_cnt，单调增，返回 key 在哪个区间
int
ycsb_wl::key_to_part(uint64_t key) {
	uint64_t rows_per_part = g_synth_table_size / g_part_cnt;
	return key / rows_per_part;
}

RC ycsb_wl::init_table() {
    cout << "table size:" << g_synth_table_size << endl;
    std::unique_ptr<dbx1000::Profiler> profiler(new dbx1000::Profiler());
    profiler->Start();

    init_table_parallel();
    profiler->End();
    std::cout << "workload Init Time : " << profiler->Millis() << " Millis" << std::endl;
    return RCOK;
}

// init table in parallel
void ycsb_wl::init_table_parallel() {
    std::vector<std::thread> v_thread;
    for(int i = 0; i < g_init_parallelism; i++) {
        v_thread.emplace_back(thread(threadInitTable, this));
    }
    for(int i = 0; i < g_init_parallelism; i++) {
        v_thread[i].join();
    }
}
//! 初始化单个区间
void * ycsb_wl::init_table_slice() {
    uint32_t tid = next_tid.fetch_add(1, std::memory_order_consume);

//	cout << tid << endl;
//	set_affinity(tid);      /// 绑定到物理核

	RC rc;
	assert(g_synth_table_size % g_init_parallelism == 0);
	assert(tid < g_init_parallelism);
	uint64_t slice_size = g_synth_table_size / g_init_parallelism;

    uint32_t tuple_size = the_table->get_schema()->get_tuple_size();
    for (uint64_t key = slice_size * tid; key < slice_size * (tid + 1); key++) {
        dbx1000::RowItem *rowItem = new dbx1000::RowItem(key, tuple_size);
//		for (uint32_t fid = 0; fid < the_table->get_schema()->get_field_cnt(); fid ++) {
//		    uint64_t field_size = the_table->get_schema()->get_field_size(fid);
//		    memset((char*) rowItem->row_ + fid*field_size, 'a', field_size);
//		}
        memset((char*) rowItem->row_, 'a', tuple_size);
		buffer_->BufferPut(key, rowItem->row_, tuple_size);

		Row_mvcc *rowMvcc = new Row_mvcc();
		rowMvcc->init(rowItem);
		glob_manager_server->row_mvccs_mutex_.lock();
		glob_manager_server->row_mvccs_.insert(std::pair<uint64_t, Row_mvcc*>(key, rowMvcc));
        glob_manager_server->row_mvccs_mutex_.unlock();

/*
		row_t * new_row = NULL;
		uint64_t row_id;
		int part_id = key_to_part(key);     //! 区间内 index
		rc = the_table->get_new_row(new_row, part_id, row_id);  //! TODO, row_id 到底返回的啥？
		assert(rc == RCOK);
		uint64_t primary_key = key;
		new_row->set_primary_key(primary_key);
//		new_row->set_value(0, &primary_key);    //! 第 0 列是主键

		for (uint32_t fid = 0; fid < the_table->get_schema()->get_field_cnt(); fid ++) {
			char value[11] = "hellohello";
			new_row->set_value(fid, value);
		}

		index_insert(the_index, primary_key, new_row, part_id);
		assert(rc == RCOK);
*/
	}
/*	return NULL; */
}
/*
! h_thd = 0, 1, 2, 3
RC ycsb_wl::get_txn_man(txn_man *& txn_manager, thread_t * h_thd){
    txn_manager = new ycsb_txn_man();
	txn_manager->init(h_thd, this, h_thd->get_thd_id());
	return RCOK;
}
*/
