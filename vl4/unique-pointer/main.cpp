#include<iostream>
#include<memory>
#include<list>
class myClass {
    public:
        myClass() { std::cout << "Constructor of myClass called." << std::endl; }
        ~myClass() { std::cout << "Destructor of myClass called." << std::endl; }
        void print() { std::cout << "I live at memory address " << this << std::endl; }
};
int main() {

    {
        std::unique_ptr<myClass> o = std::make_unique<myClass>();
        o->print();
        
        //das geht nicht mit unique-pointern!
        //std::unique_ptr<myClass> copy_of_o = o;
    }

    return 0;
}