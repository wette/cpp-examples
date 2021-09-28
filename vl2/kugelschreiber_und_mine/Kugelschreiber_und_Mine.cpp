#include <string>
#include <iostream>

class Mine {
	private:
		Kugelschreiber &meinKS;
		double fuellstand = 1.0;
		double verbrauchProZeichen = 0.05;

	public:
		bool schreiben(int anzahlZeichen) {
			bool erfolgreich =  this->fuellstand >= anzahlZeichen * this->verbrauchProZeichen;
			if(erfolgreich){
				this->fuellstand -= anzahlZeichen * this->verbrauchProZeichen;
			}
			return erfolgreich;
		}
		double getFuellstand(){
			return this->fuellstand;
		}
};

class Kugelschreiber {
	private:
		bool mineAusgefahren = false;
		Mine meineMine = Mine();

	public:
		bool knopfDruecken() {
			this->mineAusgefahren = !this->mineAusgefahren;
			return this->mineAusgefahren;
		}
		bool schreiben(std::string text) {
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
};

int main() {
	Kugelschreiber meinKulli;
	meinKulli.schreiben("");
	meinKulli.knopfDruecken();
	meinKulli.schreiben("Ich schreibe etwas.");
	meinKulli.schreiben("Tinte leer?");
	meinKulli.knopfDruecken();
	
}
