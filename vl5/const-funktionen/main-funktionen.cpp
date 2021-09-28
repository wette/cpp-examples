#include<iostream>


/* funktion verspricht a nicht zu verändern */
void myFunction(const int& a, int &b) {
    //a = b; /*  nicht erlaubt da a const */
    b = a;

    /*
    Die Funktion kann aber auch gemein sein, und sich nicht an das Versprechen halten...
    int &x = const_cast<int&>(a);
    x = 1000;*/
    
}

int main() {
    int a = 1;
    int b = 2;
    myFunction(a, b);

    std::cout << "a: " << a << " b: " << b << std::endl;

    return 0;
}