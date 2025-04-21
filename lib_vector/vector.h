// Copyright 2024 Ramzan Kamaletdinov

#ifndef LIB_VECTOR_VECTOR_H_
#define LIB_VECTOR_VECTOR_H_

#include "../lib_DMassive/DMassive.h"

template <typename T>
class Vector {
    DMassive<T> _data;
    size_t _start_index;

public:
    // Конструкторы
    explicit Vector(size_t size = 0, T value = T{});
    Vector(const T* arr, size_t size);  // Вектор из массива
    Vector(const Vector& other);  // Копирующий конструктор

    // Оператор присваивания
    Vector& operator=(const Vector& other);

    // Доступ к элементам
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    // Математические операторы
    Vector& operator+=(const Vector& other);
    Vector& operator-=(const Vector& other);
    Vector& operator*=(const T& scalar);  // Умножение на скаляр
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(const T& scalar) const;

    // Операторы сравнения
    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;

    // Вспомогательные методы
    size_t size() const noexcept;
    void print() const noexcept;

private:
    void check_size_compatibility(const Vector& other) const; // Проверка совместимости размеров векторов
};

// Реализация

template <typename T>
Vector<T>::Vector(size_t size, T value) : _data(size, value), _start_index(0) {}

template <typename T>
Vector<T>::Vector(const T* arr, size_t size)
    : _data(arr, size), _start_index(0) {}

template <typename T>
Vector<T>::Vector(const Vector& other)
    : _data(other._data), _start_index(other._start_index) {}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other) { // Проверка на самоприсваивание
        _data = other._data; // Предполагается, что DMassive имеет оператор присваивания
    }
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
        throw std::invalid_argument("Vector sizes must match for this operation");
    }
}

#endif  // LIB_VECTOR_VECTOR_H_
