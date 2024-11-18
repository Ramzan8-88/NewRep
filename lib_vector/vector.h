// Copyright 2024 Ramzan Kamaletdinov

#ifndef LIB_VECTOR_VECTOR_H_
#define LIB_VECTOR_VECTOR_H_

#include "../lib_DMassive/DMassive.h"

template <typename T>
class Vector {
    DMassive<T> _data;
    size_t _start_index;

public:
    // конструкторы
    explicit Vector(size_t size = 0, T value = T{});
    // вектор с заданным размером и значением по умолчанию
    Vector(const T* arr, size_t size);  // вектор из массива
    Vector(const Vector& other);  // копирующий конструктор

    // оператор присваивания
    Vector& operator=(const Vector& other);

    // доступ к элементам
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    // математические операторы
    Vector& operator+=(const Vector& other);
    Vector& operator-=(const Vector& other);
    Vector& operator*=(const T& scalar);  // умножение на скаляр
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(const T& scalar) const;

    // операторы сравнения
    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;

    // вспомогательные методы
    size_t size() const noexcept;
    void print() const noexcept;

private:
    void check_size_compatibility(const Vector& other) const;
    // проверка совместимости размеров векторов
};

// реализация

template <typename T>
Vector<T>::Vector(size_t size, T value) : _data(size, value), _start_index(0) {}

template <typename T>
Vector<T>::Vector(const T* arr, size_t size)
    : _data(arr, size),
    _start_index(0) {}

template <typename T>
Vector<T>::Vector(const Vector& other)
    : _data(other._data),
    _start_index(other._start_index) {}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    _data.assign(other._data);
    return *this;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    return _data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    return _data[index];
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector& other) {
    check_size_compatibility(other);
    for (size_t i = 0; i < size(); ++i) {
        _data[i] += other._data[i];
    }
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator-=(const Vector& other) {
    check_size_compatibility(other);
    for (size_t i = 0; i < size(); ++i) {
        _data[i] -= other._data[i];
    }
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator*=(const T& scalar) {
    for (size_t i = 0; i < size(); ++i) {
        _data[i] *= scalar;
    }
    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector& other) const {
    Vector result(*this);
    result += other;
    return result;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector& other) const {
    Vector result(*this);
    result -= other;
    return result;
}

template <typename T>
Vector<T> Vector<T>::operator*(const T& scalar) const {
    Vector result(*this);
    result *= scalar;
    return result;
}

template <typename T>
bool Vector<T>::operator==(const Vector& other) const {
    if (size() != other.size()) return false;
    for (size_t i = 0; i < size(); ++i) {
        if (_data[i] != other._data[i]) return false;
    }
    return true;
}

template <typename T>
bool Vector<T>::operator!=(const Vector& other) const {
    return !(*this == other);
}

template <typename T>
size_t Vector<T>::size() const noexcept {
    return _data.size();
}

template <typename T>
void Vector<T>::print() const noexcept {
    _data.print();
}

template <typename T>
void Vector<T>::check_size_compatibility(const Vector& other) const {
    if (size() != other.size()) {
        throw std::invalid_argument(
            "Vector sizes must match for this operation");
    }
}

#endif  // LIB_VECTOR_VECTOR_H_
