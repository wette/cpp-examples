#include "Kugelschreiber.hpp"

class Mine {
    private:
        double fuellstand = 1.0;
		double verbrauchProZeichen = 0.05;
        Kugelschreiber *meinKS;
    public:
        bool schreiben(int anzahlZeichen);
        void setFuellstand(double kapazitaet);
        double getFuellstand();
};