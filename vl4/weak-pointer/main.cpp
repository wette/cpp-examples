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
        std::weak_ptr<myClass> copy_of_o;
        {
            std::shared_ptr<myClass> o = std::make_shared<myClass>();
            o->print();
            
            //das geht mit shared-pointern
            copy_of_o = o;
        }
        //hier lebt das Objekt auf dem Heap nicht mehr, denn auf weak_ptr wird keine Rücksicht genommen

        //weak_ptr benutzen
        if(std::shared_ptr<myClass> o = copy_of_o.lock()) {
            //wird nur ausgeführt, wenn das Objekt auf dem heap noch existiert!
            o->print();
        } else {
            std::cout << "Object no longer alive." << std::endl;
        }
    }
    return 0;
}