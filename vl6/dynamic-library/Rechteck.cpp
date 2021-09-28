#include "Rechteck.hpp"
namespace fhbi
{
Rechteck::Rechteck(double a, double b) {
    this->a = a; 
    this->b = b;
}
double Rechteck::inhalt() {
    return a*b;
}
double Rechteck::umfang() {
    return 2*(a+b);
}

}