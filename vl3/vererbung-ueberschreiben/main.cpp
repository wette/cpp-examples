#include <iostream>
class RobotHW {
    public:
        /*virtual*/ void moveForwards(double meters) {
            std::cout << "RobotHW::moveForwards()" << std::endl;
        }
};

class Spot: public RobotHW {
    public:
        void moveForwards(double meters) {
            std::cout << "Spot::moveForwards()" << std::endl;
        }
};

class Atlas: public RobotHW {
    public:
        void moveForwards(double meters) {
            std::cout << "Atlas::moveForwards()" << std::endl;
        }
};

class Navigation {
    public: 
        void moveRobot(RobotHW &robot) {    //wichtig: call-by-reference damit nicht kopiert wird!
            robot.moveForwards(5.0);
        }
};

int main() {
    Navigation nav;

    Spot spot;
    Atlas atlas;

    //Hier wird RobotHW::moveForwards() aufgerufen, wenn RobotHW::moveForwards() nicht virtual ist
    nav.moveRobot(spot);
    nav.moveRobot(atlas);

    return 0;
}