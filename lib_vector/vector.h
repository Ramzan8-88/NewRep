// Copyright 2024 Ramzan Kamaletdinov

#ifndef LIB_VECTOR_VECTOR_H_
#define LIB_VECTOR_VECTOR_H_

#include "../lib_DMassive/DMassive.h"
#include <stdexcept>
#include <initializer_list>

template<typename T>
class Vector {
private:
    DMassive<T> _data;
    size_t _start_index;

    void check_size_compatibility(const Vector& other) const {
        if (_data.size() != other._data.size()) {
            throw std::invalid_argument("Vector sizes must match for this operation");
        }
    }

public:
    explicit Vector(size_t size = 0, T value = T{})
        : _data(size, value), _start_index(0) {}

    Vector(const T* arr, size_t size)
        : _data(arr, size), _start_index(0) {}

    Vector(std::initializer_list<T> list)
        : _data(list), _start_index(0) {}

    Vector(const Vector& other)
        : _data(other._data), _start_index(other._start_index) {}

    // Оператор присваивания
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            _data = other._data;
            _start_index = other._start_index;
        }
        return *this;
    }

    T& operator[](size_t index) {
        return _data[index + _start_index];
    }

    const T& operator[](size_t index) const {
        return _data[index + _start_index];
    }

    Vector operator+(const Vector& other) const {
        check_size_compatibility(other);
        Vector result(_data.size());
        for (size_t i = 0; i < _data.size(); ++i) {
            result[i] = (*this)[i] + other[i];
        }
        return result;
    }

    Vector operator-(const Vector& other) const {
        check_size_compatibility(other);
        Vector result(_data.size());
        for (size_t i = 0; i < _data.size(); ++i) {
            result[i] = (*this)[i] - other[i];
        }
        return result;
    }

    Vector operator*(const T& scalar) const {
        Vector result(_data.size());
        for (size_t i = 0; i < _data.size(); ++i) {
            result[i] = (*this)[i] * scalar;
        }
        return result;
    }

    Vector& operator+=(const Vector& other) {
        check_size_compatibility(other);
        for (size_t i = 0; i < _data.size(); ++i) {
            (*this)[i] += other[i];
        }
        return *this;
    }

    Vector& operator-=(const Vector& other) {
        check_size_compatibility(other);
        for (size_t i = 0; i < _data.size(); ++i) {
            (*this)[i] -= other[i];
        }
        return *this;
    }

    bool operator==(const Vector& other) const {
        if (_data.size() != other._data.size()) return false;
        for (size_t i = 0; i < _data.size(); ++i) {
            if ((*this)[i] != other[i]) return false;
        }
        return true;
    }

    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }

    size_t size() const {
        return _data.size();
    }

    void print() const {
        for (size_t i = 0; i < _data.size(); ++i) {
            std::cout << (*this)[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif  // LIB_VECTOR_VECTOR_H_