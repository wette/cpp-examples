#include<algorithm>
#include<vector>
#include<iostream>
#include<chrono>

class myClass{
    private:
        double d;
        std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> t;
    public:
        myClass(double d) { this->d = d; };
        double getD(){ return d; }
        std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> getT() { return t; };
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
    }
    for(auto x : v) {
        std::cout << x.getD() << ", ";
    }
    std::cout << std::endl << std::endl;

    std::sort(v.begin(), v.end(), myCompareOperator);

    //alternative: sortieren mit einer Lambda-Funktion
    std::sort(v.begin(), v.end(), [](myClass a, myClass b) {
                                        return a.getD() > b.getD();
                                    }
    );

    //sortieren nach Zeitpunkt - std::chrono überläd hierfür den operator>
    std::sort(v.begin(), v.end(), [](myClass a, myClass b) {
                                        return a.getT() > b.getT();
                                    }
    );

    for(auto x : v) {
        std::cout << x.getD() << ", ";
    }
    std::cout << std::endl;

    return 0;
}