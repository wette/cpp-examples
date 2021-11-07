#include "Mensch.hpp"
#include "Student.hpp"
#include <iostream>
int main() {
    Mensch max("Max Mustermann");
    Student moritz("Moritz Mustermann", 12345678);

    std::cout << max.getName() << std::endl;
    std::cout << moritz.getName() << " matNr: " << moritz.getMatrikelnummer() << std::endl;

    /*
    std::cout << "Typumwandlung von Moritz nach Mensch " << std::endl;
    Mensch &m2 = dynamic_cast<Mensch&>(moritz);
    std::cout << m2.getName() << " matNr: " << m2.getMatrikelnummer() << std::endl; 
    */
    

    return 0;
}