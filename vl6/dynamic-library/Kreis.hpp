#pragma once
#include "Geometrie.hpp"
namespace fhbi {
class Kreis : public Geometrie {
    private:
        double radius;
    public:
        Kreis(double radius);
        double umfang();
        double inhalt();

};
}