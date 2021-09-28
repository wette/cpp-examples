#include "Point2d.hpp"

int main() {
    Point2d<int> intpoint(1,2);
    Point2d<double> doupoint(1.0, 2.0);

    intpoint.print();
    doupoint.print();

}