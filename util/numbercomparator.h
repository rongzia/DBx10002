//
// Created by rrzhang on 2020/4/5.
//

#ifndef DBX1000_NUMBERCOMPARATOR_H
#define DBX1000_NUMBERCOMPARATOR_H

#include "leveldb/comparator.h"

namespace dbx1000 {
    class Slice;

    class NumberComparatorImpl : public leveldb::Comparator {
    public:
//        NumberComparatorImpl();
//        ~NumberComparatorImpl();

        virtual const char *Name() const;

        virtual int Compare(const leveldb::Slice &a, const leveldb::Slice &b) const;

        virtual void FindShortestSeparator(std::string *start, const leveldb::Slice &limit) const;

        virtual void FindShortSuccessor(std::string *key) const;
    };

    const leveldb::Comparator *NumberComparator();
}

#endif //DBX1000_NUMBERCOMPARATOR_H
