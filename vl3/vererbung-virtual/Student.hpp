#pragma once
#include "Mensch.hpp"
#include <string>
class Student: public Mensch {
    private:
        int matNr;
    public:
        Student(std::string name, int matNr): Mensch(name) {
            this->matNr = matNr;
        }
        int getMatrikelnummer(){
            return matNr;
        }
        std::string getName() {
            return "Student " + std::to_string(matNr);
        }
};