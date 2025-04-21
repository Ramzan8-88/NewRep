// Copyright 2025 Ramzan Kamaletdinov

#ifndef LIB_TABLE_TUNSORTEDTABLE_H_
#define LIB_TABLE_TUNSORTEDTABLE_H_

#include "../lib_ITable/ITable.h"
#include "../lib_List/List.h"
#include "../lib_pair/pair.h"

template <class TKey, class TVal>
class TUnsortedTable : public ITable<TKey, TVal> {
private:
    TList<TPair<TKey, TVal>> _data;

public:
    TKey insert(TVal val) override {
        static TKey key_counter = 0;
        TKey new_key = ++key_counter;
        insert(new_key, val);
        return new_key;
    }

    void insert(TKey key, TVal val) override {
        TPair<TKey, TVal> new_pair(key, val);
        _data.insertBack(new_pair);
    }

    void erase(TKey key) override {
        TNode<TPair<TKey, TVal>>* current = _data.getHead();
        while (current) {
            if (current->getValue().first() == key) {
                _data.removeNode(current);
                return;
            }
            current = current->getNext();
        }
    }

    TVal find(TKey key) override {
        TNode<TPair<TKey, TVal>>* current = _data.getHead();
        while (current) {
            if (current->getValue().first() == key) {
                return current->getValue().second();
            }
            current = current->getNext();
        }
        throw std::out_of_range("Key not found");
    }

    TVal operator[](TKey key) override {
        TVal val = find(key);
        return val;
    }

    TUnsortedTable& operator=(const TUnsortedTable& other) {
        if (this != &other) {
            _data = other._data;
        }
        return *this;
    }
};

#endif  // LIB_TABLE_TUNSORTEDTABLE_H_