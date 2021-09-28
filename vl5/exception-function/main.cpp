#include<iostream>
#include<math.h>
#include<stdexcept>


float areaOfCircle(int radius) {
    if(radius < 0) {
        throw std::runtime_error("Radius must not be negative!");
    }
    return M_PI*radius*radius;
}

int main() {
    int x;
    std::cout << "bitte Radius eingeben" << std::endl;
    while(true) {
        std::cin >> x;
        try{
            //programmlogik hier
            int a = areaOfCircle(x);
            int b = areaOfCircle(12);

            if(b > a) {
                std::cout << b/a << std::endl;
            } else {
                std::cout << a/b << std::endl;
            }

        } catch(std::runtime_error e) {
            //fehlerbehandlung hier
            std::cout << "error: " << e.what() << std::endl;
            std::cout << "bitte erneut Radius eingeben" << std::endl;
        }
    }


}