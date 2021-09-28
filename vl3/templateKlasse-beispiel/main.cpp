#include "Point2d.hpp"
int main() {
    Point2d<int> intp(1,2);
    Point2d<double> doublep(1.3, 2.2);

    intp.print();
    doublep.print();
}