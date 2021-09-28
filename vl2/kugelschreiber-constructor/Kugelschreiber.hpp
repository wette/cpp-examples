#pragma once

#include <string>
#include "Mine.hpp"

class Kugelschreiber {
	private:
		bool mineAusgefahren = false;
		Mine meineMine;

	public:
		Kugelschreiber();
		Kugelschreiber(double kapazitaet);
		~Kugelschreiber();
		bool knopfDruecken();
		bool schreiben(std::string text);
};