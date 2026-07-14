#pragma once
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <utility> // For std::swap
 
template <typename T>
class Vector {
private:
    T* arr; // указатель на динамический массив элементов
    size_t sz;
    size_t cap;
public:
    Vector(); // конструктор по умолчанию
    Vector(const Vector& v); // конструктор копировани€
    Vector(T* arr, size_t size); //  ќ––≈ ÷»я: int -> size_t
    explicit Vector(size_t size); //  ќ––≈ ÷»я: int -> size_t
    ~Vector(); // деструктор

    void reserve(size_t new_cap);
    void push_back(const T& val);

    friend std::ostream& operator<< (std::ostream& out, const Vector<T>& v) {
        for (size_t i = 0; i < v.sz; i++) {
            out << v.arr[i] << ' ';
        }
        return out;
    }

    friend std::istream& operator>> (std::istream& in, Vector<T>& v) {
        for (size_t i = 0; i < v.sz; i++) {
            in >> v.arr[i];
        }
        return in;
    }

    T& operator[] (size_t s); // доступ по индексу
    const T& operator[](size_t s) const;
    Vector operator+ (const Vector& v) const; // сложение векторов
    Vector operator- (const Vector& v) const;
    T operator* (const Vector& v) const;
    Vector& operator= (Vector v); //  ќ––≈ ÷»я: передача по значению дл€ copy-and-swap
    Vector& operator+= (const Vector& v); // сложение с присваиванием

    size_t size() const; // получить размер
    const T* begin() const; // итератор на начало
    const T* end() const; // итератор на конец
    T* begin() { return arr; }
    T* end() { return arr + sz; }
};

template <typename T>
void Vector<T>::reserve(size_t new_cap) {
    if (new_cap <= cap) return;
    T* new_arr = new T[new_cap];
    for (size_t i = 0; i < sz; i++) {
        new_arr[i] = arr[i];
    }
    delete[] arr;

    arr = new_arr;
    cap = new_cap;
}

template <typename T>
void Vector<T>::push_back(const T& val) {
    if (sz == cap) reserve(cap == 0 ? 1 : cap * 2);
    arr[sz] = val;
    sz++;
}

template <typename T>
Vector<T>::Vector() {
    sz = 0;
    cap = 0;
    arr = nullptr;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& v) {
    cap = v.cap;
    sz = v.sz;
    arr = new T[cap];
    for (size_t i = 0; i < sz; i++) {
        arr[i] = v.arr[i];
    }
}

template <typename T>
Vector<T>::Vector(T* a, size_t size) {
    sz = size;
    cap = size;
    arr = new T[cap];
    for (size_t i = 0; i < sz; i++) {
        arr[i] = a[i];
    }
}

template <typename T>
Vector<T>::Vector(size_t size) {
    sz = size;
    cap = size;
    arr = new T[cap]();
}

template <typename T>
Vector<T>::~Vector() {
    delete[] arr;
    arr = nullptr;
}

template <typename T>
T& Vector<T>::operator[] (size_t i) {
    return arr[i];
}

template <typename T>
const T& Vector<T>::operator[] (size_t i) const { 
    return arr[i];
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const {
    if (sz != other.sz) throw std::invalid_argument("Vectors must have the same size");
    Vector<T> result(sz);
    for (size_t i = 0; i < sz; i++) {
        result.arr[i] = arr[i] + other.arr[i];
    }
    return result;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T>& other) const {
    if (sz != other.sz) throw std::invalid_argument("Vectors must have the same size");
    Vector<T> result(sz);
    for (size_t i = 0; i < sz; i++) {
        result.arr[i] = arr[i] - other.arr[i];
    }
    return result;
}

template <typename T>
T Vector<T>::operator*(const Vector<T>& other) const {
    if (sz != other.sz) throw std::invalid_argument("Vectors must have the same size");
    T result = T();
    for (size_t i = 0; i < sz; i++) {
        result += arr[i] * other.arr[i];
    }
    return result;
}

template <typename T>
Vector<T>& Vector<T>::operator= (Vector<T> v) {
    std::swap(arr, v.arr); 
    std::swap(sz, v.sz);
    std::swap(cap, v.cap);
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator+= (const Vector& v) {
    if (sz != v.sz) throw std::invalid_argument("Vectors must have the same size");
    for (size_t i = 0; i < sz; i++) {
        arr[i] += v.arr[i];
    }
    return *this;
}

template <typename T>
size_t Vector<T>::size() const {
    return sz;
}

template <typename T>
const T* Vector<T>::begin() const {
    return arr;
}

template <typename T>
const T* Vector<T>::end() const {
    return arr + sz;
}

