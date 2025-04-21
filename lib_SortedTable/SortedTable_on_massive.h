// Copyright 2025 Ramzan Kamaletdinov

#ifndef LIB_SORTED_TABLE_SORTED_TABLE_H_
#define LIB_SORTED_TABLE_SORTED_TABLE_H_

#include "../lib_ITable/ITable.h"
#include "../lib_pair/pair.h"
#include "../lib_DMassive/DMassive.h"
#include <iostream>

template <class TKey, class TVal>
class SortedTable : public ITable<TKey, TVal> {
private:
    DMassive<TPair<TKey, TVal>> _data;

    size_t binary_search(const TKey& key) const {
        size_t left = 0;
        size_t right = _data.size() - 1;
        while (left <= right) {
            size_t mid = left + (right - left) / 2;
            if (_data[mid].first() == key)
                return mid;
            if (_data[mid].first() < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return static_cast<size_t>(-1);
    }

public:
    SortedTable() = default;

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

        size_t left = 0;
        size_t right = _data.size();
        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (_data[mid].first() < key) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        _data.insert(pair, left);
    }

    void erase(TKey key) override {
        size_t pos = binary_search(key);
        if (pos != static_cast<size_t>(-1)) {
            _data.remove_by_index(pos);
        }
    }

    TVal find(TKey key) override {
        size_t pos = binary_search(key);
        if (pos == static_cast<size_t>(-1)) {
            throw std::out_of_range("Key not found");
        }
        return _data[pos].second();
    }

    TVal operator[](TKey key) override {
        return find(key);
    }

    SortedTable& operator=(const SortedTable& other) {
        if (this != &other) {
            _data.assign(other._data);
        }
        return *this;
    }
};

#endif  // LIB_SORTED_TABLE_SORTED_TABLE_H_