/*
    simple buffer overflow demo. 
    compile on a machine that has no advanced stack protection like a raspberryPI
*/

#include <iostream>

/*
    this function is
*/
int myFunction1(int i) {
    std::cout << "this is not supposed to be called but was called with " << i << std::endl;
    return 0;
}

int myFunction2() {
        char c[16];
        int i = 0;
        std::cin >> c;

        if(i != 0) {
            myFunction1(i);
        }

        return 0;
}

int main() {
    myFunction2();

    return 0;
}