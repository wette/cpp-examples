#include "Point2d.hpp"
#include<iostream>

template <class T>
Point2d<T>::Point2d(T x, T y) {
    this->x = x;
    this->y = y;
}

template <class T>
void Point2d<T>::print() {
    std::cout << x << ", " << y  << std::endl;
}