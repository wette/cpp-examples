#include <iostream>
class RobotHW {
    public:
        virtual void moveForwards(double meters) {
            std::cout << "RobotHW::moveForwards(" << meters << ")" << std::endl;
        }
};

class Spot: public RobotHW {
    public:
        void moveForwards(double meters) {
            std::cout << "Spot::moveForwards(" << meters << ")" << std::endl;
        }
};

class Atlas: public RobotHW {
    public:
        void moveForwards(double meters) {
            std::cout << "Atlas::moveForwards(" << meters << ")" << std::endl;
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
    
    nav.moveRobot(spot);
    nav.moveRobot(atlas);
    //Was passiert, wenn RobotHW::moveForwards() nicht virtual ist (Zeile 4)?


    // /*  Downcasting - als Referenz der Oberklasse auf die Unterklasse  */
    // std::cout << "Downcasting" << std::endl;
    // RobotHW &robotSpot = dynamic_cast<RobotHW &>(spot);
    // robotSpot.moveForwards(1.0);
    // RobotHW *robotSpotPtr = dynamic_cast<RobotHW *>(&spot);
    // robotSpotPtr->moveForwards(1.0);

    // /* Upcasting - geht NUR über Pointer, nicht über Referenzen */
    // std::cout << "Upcasting" << std::endl;
    // Spot *spotReference = reinterpret_cast<Spot *>(&robotSpot);
    // spotReference->moveForwards(2.0);

    // /* Slicing - Hier wird eine KOPIE von spot angelegt */
    // /* Da in ein Objekt von RobotHW kopiert wird, wird der Spot-Teil "abgeschnitten" */
    // std::cout << "Slicing" << std::endl;
    // RobotHW spotCopy = spot;
    // spotCopy.moveForwards(3.0);

    return 0;
}