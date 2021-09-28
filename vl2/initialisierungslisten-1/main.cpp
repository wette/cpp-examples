#include<iostream>

class Foo {
    private:
        int x;
    public:
        Foo() {
            std::cout << "Standardkonstruktor von Foo" << std::endl;
            x = -1;
        }
        Foo(int x) {
            std::cout << "Konstruktor Foo(int x)" << std::endl;
            this->x = x;
        }
};

class Bar {
    private: 
        Foo f;
        int x;
    public: 
        Bar(int x) {
            this->x = x;
            f = Foo(x);
        }

};

int main() {
    Bar b(100);
}