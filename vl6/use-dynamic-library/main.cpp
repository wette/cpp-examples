#include "../dynamic-library/Kreis.hpp"
#include<iostream>

/*
    compile as: g++ main.cpp -L../dynamic-library -l geo -v
    Anleitung für Visual Studio: https://docs.microsoft.com/de-de/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-160
*/

int main(){
    fhbi::Kreis k(14);
    std::cout << k.umfang() << std::endl;
    return 0;
}