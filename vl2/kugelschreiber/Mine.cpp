#include "Mine.hpp"

bool Mine::schreiben(int anzahlZeichen) {
    bool erfolgreich =  this->fuellstand >= anzahlZeichen * this->verbrauchProZeichen;
    if(erfolgreich){
        this->fuellstand -= anzahlZeichen * this->verbrauchProZeichen;
    }
    return erfolgreich;
}

double Mine::getFuellstand() {
    return this->fuellstand;
}

void Mine::setFuellstand(double f) {
    this->fuellstand = f;
}