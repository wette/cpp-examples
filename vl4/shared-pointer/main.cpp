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
        std::shared_ptr<myClass> copy_of_o;
        {
            std::shared_ptr<myClass> o = std::make_shared<myClass>();
            o->print();
            
            //das geht mit shared-pointern
            copy_of_o = o;
        }
        //hier lebt das Objekt auf dem Heap immer noch.
        copy_of_o->print();

    }
    //hier lebt das Objekt auf dem Heap nicht mehr, 
    //da keine Instanz des shared_ptrs mehr existiert, die darauf zeigt.


    return 0;
}