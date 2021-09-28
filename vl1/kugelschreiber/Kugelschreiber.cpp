#include <string>
#include <iostream>

class Kugelschreiber {
	private:
		double fuellstand = 1.0;
		bool mineAusgefahren = false;
		double verbrauchProZeichen = 0.05;

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
			double verbrauch = text.length() * this->verbrauchProZeichen;
			if(verbrauch <= this->fuellstand) {
				this->fuellstand -= verbrauch;
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
