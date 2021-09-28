#include "mycontainer.hpp"
#include <iostream>
int main() {
    mycontainer<int> int_cont(1);
    mycontainer<double> double_cont(2.0);
    mycontainer<char> char_cont('x');

    int    i = int_cont.increase();
    double d = double_cont.increase();
    char   c = char_cont.uppercase();

    std::cout << i << ", " << d << ", " << c << std::endl;

    return 0;
}