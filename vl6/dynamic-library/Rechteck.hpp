#pragma once
#include "Geometrie.hpp"
namespace fhbi {
class Rechteck : public Geometrie {
    private:
        double a,b;
    public:
        Rechteck(double a, double b);
        double umfang();
        double inhalt();

};
}