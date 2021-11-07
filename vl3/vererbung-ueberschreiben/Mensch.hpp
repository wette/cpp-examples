#pragma once
#include <string>
class Mensch {
    private:
        std::string name;
    public:
        Mensch(std::string name){
            this->name = name;
        }
        std::string getName(){
            return name;
        }
};