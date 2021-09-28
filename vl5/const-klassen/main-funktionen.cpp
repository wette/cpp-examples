#include<iostream>

class myClass {
    private:
        int x;
    public:
        myClass(int x) {
            this->x = x;
        }
        int getX() const {
            return x;
        }
        void setX(int x) {
            this->x = x;
        }
};


int main() {
    const myClass c(100);
    //c.setX(10);       /* nicht erlaubt, da die Funktion setX nicht als const markiert ist */

    std::cout << "c.getX(): " << c.getX() << std::endl;

    return 0;
}