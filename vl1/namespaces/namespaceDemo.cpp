#include<string>
#include<iostream>

//eigenen Namespace definieren
namespace XYZ {
    //eigene Funktion in eigenem Namespace definieren
    void meineFunktion() {
        std::cout << "Funktion aus Namespace XYZ aufgerufen." << std::endl;
    }
}

//eigene Funktion ohne Namespace definieren (--> lebt im default namespace)
void meineFunktion() {
    std::cout << "Funktion im default Namespace aufgerufen." << std::endl;
}


// es ist auch möglich, Definitionen aus beliebigen Namespaces 
// in den default Namespace zu übernehmen:
//using namespace std;
int main() {
    std::string myString = "lalala";
    myString += "blabla";

    XYZ::meineFunktion();
    meineFunktion();

    std::cout << myString << std::endl;
}