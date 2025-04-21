// Copyright 2025 Ramzan Kamaletdinov

#ifndef LIB_UNSORTED_TABLE_UNSORTED_TABLE_H_
#define LIB_UNSORTED_TABLE_UNSORTED_TABLE_H_

#include "../lib_ITable/ITable.h"
#include "../lib_pair/pair.h"
#include "../lib_DMassive/DMassive.h"
#include <iostream>

template <class TKey, class TVal>
class UnsortedTable : public ITable<TKey, TVal> {
private:
    DMassive<TPair<TKey, TVal>> _data;

public:
    UnsortedTable() = default;

    TKey generate_key(TVal val) {
        static int current_key = 0;
        return current_key++;
    }

    TKey insert(TVal val) override {
        TKey key = generate_key(val);
        TPair<TKey, TVal> pair(key, val);
        _data.push_back(pair);
        return key;
    }

    void insert(TKey key, TVal val) override {
        TPair<TKey, TVal> pair(key, val);
        _data.push_back(pair);
    }

    void erase(TKey key) override {
        for (size_t i = 0; i < _data.size(); ++i) {
            if (_data[i].first() == key) {
                _data.remove_by_index(i);
                return;
            }
        }
    }

    TVal find(TKey key) override {
        for (size_t i = 0; i < _data.size(); ++i) {
            if (_data[i].first() == key) {
                return _data[i].second();
            }
        }
        throw std::out_of_range("Key not found");
    }

    TVal operator[](TKey key) override {
        return find(key);
    }

    UnsortedTable& operator=(const UnsortedTable& other) {
        if (this != &other) {
            _data.assign(other._data);
        }
        return *this;
    }
};

#endif  // LIB_UNSORTED_TABLE_UNSORTED_TABLE_H_