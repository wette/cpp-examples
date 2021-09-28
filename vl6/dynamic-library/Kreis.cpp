#include "Kreis.hpp"
#include <cmath>
namespace fhbi
{
Kreis::Kreis(double r) {
    this->radius = r;
}
double Kreis::inhalt() {
    return radius*radius*M_PI;
}
double Kreis::umfang() {
    return 2*M_PI*radius;
}


}