#include "Mensch.hpp"
#include "Student.hpp"
#include <iostream>
int main() {
    Mensch max("Max Mustermann");
    Student moritz("Moritz Mustermann", 12345678);

    std::cout << max.getName() << std::endl;
    
    //studenten sind nur nummern (sorry... ;) 
    //daher hat der Student Moritz den namen "Student 12345678"
    std::cout << moritz.getName() << std::endl;

    //betrachten wir den Mensch hinter dem Studenten, 
    //so hat dieser den Namen "Moritz Mustermann"
    Mensch &m2 = dynamic_cast<Mensch&>(moritz);
    std::cout << m2.getName() << std::endl;
    

    return 0;
}