#include "Kugelschreiber.hpp"
#include <string>

int main() {
	Kugelschreiber meinKulli(2.0);
	meinKulli.schreiben("");
	meinKulli.knopfDruecken();
	meinKulli.schreiben("Ich schreibe etwas.");
	meinKulli.schreiben("Tinte leer?");
	meinKulli.knopfDruecken();

}