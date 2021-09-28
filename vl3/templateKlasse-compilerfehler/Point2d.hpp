#pragma once

template <class T>
class Point2d {
    private:
        T x;
        T y;
    public:
        Point2d(T x, T y);
        void print();
};