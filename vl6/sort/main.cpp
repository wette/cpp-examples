#include<algorithm>
#include<vector>
#include<iostream>
#include<chrono>
#include <thread>

class myClass{
    private:
        double d;
        std::chrono::time_point<std::chrono::system_clock> t;
    public:
        myClass(double d) { this->d = d; this->t = std::chrono::system_clock::now(); };
        double getD(){ return d; }
        std::chrono::time_point<std::chrono::system_clock> getT() { return t; };
};

struct {
    bool operator()(myClass a, myClass b) const { 
        return a.getD() < b.getD();
    }
} myCompareOperator;


int main(){
    int n = 100;
    std::vector<myClass> v;

    for(int i = 0; i < n; i++) {
        if( i % 2 == 0) { //i gerade --> positiv
            v.push_back( myClass(i) );
        }else{ //i ungerade --> negativ
            v.push_back( myClass(-i) );
        }
        /* schlafen, damit wir nachher nach Zeit sortieren können*/
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); 
    }

    std::cout << "Unsortierte Daten:" << std::endl;
    for(auto x : v) {
        std::cout << x.getD() << ", ";
    }
    std::cout << std::endl << std::endl;

    /* hier passiert das eigentliche sortieren */
    std::sort(v.begin(), v.end(), myCompareOperator);

    std::cout << "Aufsteigend sortierte Daten:" << std::endl;
    for(auto x : v) {
        std::cout << x.getD() << ", ";
    }
    std::cout << std::endl << std::endl;

    //alternative: sortieren mit einer Lambda-Funktion (absteigend!)
    std::sort(v.begin(), v.end(), [](myClass a, myClass b) {
                                        return a.getD() > b.getD();
                                    }
    );

    std::cout << "Absteigend sortierte Daten mit Lambda Funktion:" << std::endl;
    for(auto x : v) {
        std::cout << x.getD() << ", ";
    }
    std::cout << std::endl << std::endl;

    //sortieren nach Zeitpunkt - std::chrono überläd hierfür den operator > bereits schon für uns
    std::sort(v.begin(), v.end(), [](myClass a, myClass b) {
                                        return a.getT() > b.getT();
                                    }
    );

    std::cout << "Nach Zeit sortierte Daten:" << std::endl;
    for(auto x : v) {
        std::cout << x.getD() << ", ";
    }
    std::cout << std::endl << std::endl;


    return 0;
}