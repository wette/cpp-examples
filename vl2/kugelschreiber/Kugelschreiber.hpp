#include <string>
#include "Mine.hpp"

class Kugelschreiber {
	private:
		bool mineAusgefahren = false;
		Mine meineMine;

	public:
		bool knopfDruecken();
		bool schreiben(std::string text);
};