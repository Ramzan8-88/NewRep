// Copyright 2025 Ramzan Kamaletdinov

#ifndef LIB_ITABLE_LIB_ITABLE_HEDER_H_
#define LIB_ITABLE_LIB_ITABLE_HEDER_H_

template <class TKey, class TVal>
class ITable {
public:
    virtual TKey insert(TVal val) = 0;
    virtual void insert(TKey key, TVal val) = 0;
    virtual void erase(TKey key) = 0;
    virtual TVal find(TKey key) = 0;
    virtual TVal operator[](TKey key) = 0;
};

#endif  // LIB_ITABLE_LIB_ITABLE_HEDER_H_