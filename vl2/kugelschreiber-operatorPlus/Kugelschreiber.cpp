#include "Kugelschreiber.hpp"
#include <iostream>

Kugelschreiber::Kugelschreiber() {
    std::cout << "Konstruktor vom Kugelschreiber aufgerufen. Mein Ort im Speicher: " << this << std::endl;
}

Kugelschreiber::Kugelschreiber(double kapazitaet) {
    this->meineMine.setFuellstand(kapazitaet);
}

Kugelschreiber::~Kugelschreiber() {
    std::cout << "Destruktor vom Kugelschreiber aufgerufen. Mein Ort im Speicher: " << this << std::endl;
}

bool Kugelschreiber::knopfDruecken() {
    this->mineAusgefahren = !this->mineAusgefahren;
	return this->mineAusgefahren;
}

bool Kugelschreiber::schreiben(std::string text) {
    if(!this->mineAusgefahren){
        std::cout << "Kann nicht schreiben. Mine nicht ausgefahren" << std::endl;
        return false;
    }
    bool schreibenErfolgreich = this->meineMine.schreiben(text.length());

    if(schreibenErfolgreich) {
        std::cout << "Ich schreibe '" << text << "'" << std::endl;
        return true;
    } else {
        std::cout << "keine Tinte mehr." << std::endl;
        return false;
    }
}

Kugelschreiber Kugelschreiber::operator+(Kugelschreiber &operand){
    std::cout << "+ Operator aufgerufen!" << std::endl;
    return Kugelschreiber( this->meineMine.getFuellstand() + operand.meineMine.getFuellstand() );
}