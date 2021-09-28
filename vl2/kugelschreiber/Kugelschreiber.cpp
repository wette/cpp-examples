#include "Kugelschreiber.hpp"
#include <iostream>

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