#include<string>
#include<iostream>

//eigenen Namespace definieren
namespace XYZ {
    void meineFunktion() {
        //tut nichts.
    }
}

//using namespace std;
int main() {
    std::string myString = "lalala";
    myString += "blabla";

    XYZ::meineFunktion();

    std::cout << myString << std::endl;
}