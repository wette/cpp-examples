#include "Ringspeicher.hpp"
#include <iostream>


int main(){
	Ringspeicher<int, 10> ring;
	for(int i = 0; i < 10; i++) {
		ring.zahlHinzufuegen(i*i);
	}

    ring += 1337;
    ring += 1338;

    std::cout << "an position 0: " << ring[0] << std::endl;

	std::cout << ring.gibDurchschnitt() << std::endl;

	ring.zahlenAusgeben();

	return 0;
}