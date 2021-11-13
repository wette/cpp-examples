#include <iostream>
class A {
    int n;
    public:
        //Standard Konstruktor
        A(int n) {
            std::cout << "Standard-Konstruktor aufgerufen von " << this << std::endl;
            this->n = n;
        }
        //Copy-Konstruktor
        A(A &a){
            std::cout << "Copy-Konstruktor aufgerufen. Kopiere " << &a << " nach " << this << std::endl;
            this->n = a.n;
        }
        //Destruktor
        ~A() {
            std::cout << "Destruktor aufgerufen von " << this << std::endl;
        }
        void setN(int n) {
            this->n = n;
        }
        int getN(){
            return n;
        }
};

class B {
    public:
        void funktionByValue(A a){
            a.setN(9999);
        }
        void funktionByReference(A &a){
            a.setN(9999);
        }
};

int main() {
    A a(10);
    B b;
    std::cout << "a: " << a.getN() << std::endl;

    std::cout << "rufe funktionByValue auf" << std::endl;
    b.funktionByValue(a);
    std::cout << "a nach Aufruf von funktionByValue: " << a.getN() << std::endl; 

    std::cout << "rufe funktionByReference auf" << std::endl;
    b.funktionByReference(a);
    std::cout << "a nach Aufruf von funktionByReference: " << a.getN() << std::endl; 

}