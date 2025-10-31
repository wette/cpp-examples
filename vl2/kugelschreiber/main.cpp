#include "Kugelschreiber.hpp"
#include <string>

int main() {
	Kugelschreiber meinKulli;
	meinKulli.schreiben("");
	meinKulli.knopfDruecken();
	meinKulli.schreiben("Ich schreibe etwas.");
	meinKulli.schreiben("Tinte leer?");
	meinKulli.knopfDruecken();
	
	return 0;
}
