#include <iostream>
#include <list>
#include<memory>

typedef struct {
    int x;
    int y; 
    int z;
} Point;

typedef std::list<Point> Weg;

//Oberklasse
class Wegfindung {
    public:
        virtual Weg findeWeg(Point start, Point end) = 0; // =0 bedeutet, für diese Funktion gibt es keine Implementierung
                                                          // hat zur Folge, dass Wegfindung niemals instanziert werden kann!
                                                          // NUR davon abgeleitete Klassen können instanziert werden
};

class WegfindungFrankreich: public Wegfindung {
    public:
        Weg findeWeg(Point start, Point end) { 
            std::cout << "Frankreich-Version" << std::endl; 
            return Weg();
        }
};

class WegfindungEngland: public Wegfindung {
    public:
        Weg findeWeg(Point start, Point end) { 
            std::cout << "England-Version" << std::endl; 
            return Weg();
        }
};

class WegfindungDeutschland: public Wegfindung {
    public:
        Weg findeWeg(Point start, Point end) { 
            std::cout << "Deutschland-Version" << std::endl; 
            return Weg();
        }
};

class Navigation {
    private:
        std::unique_ptr<Wegfindung> wegfindung;    //die strategie, die aktuell verwendet wird
    public:
        void setWegfindung(std::unique_ptr<Wegfindung> w) {
            wegfindung = std::move(w); //wir bewegen den rohen pointer hier von w nach wegfindung, da w sonst das Wegfindungsobjekt zerstören würde
        }
        Weg findeWeg(Point start, Point end) {
            return wegfindung->findeWeg(start, end);
        }
};

int main() {
    Navigation navigation;

    Point s;
    Point e;
    
    //wir sind aktuell in Frankreich:
    navigation.setWegfindung(std::make_unique<WegfindungFrankreich>());
    navigation.findeWeg(s, e);

    //jetzt sind wir in England:
    navigation.setWegfindung(std::make_unique<WegfindungEngland>());
    navigation.findeWeg(s, e);

    //und jetzt in Deutschland:
    navigation.setWegfindung(std::make_unique<WegfindungDeutschland>());
    navigation.findeWeg(s, e);
}