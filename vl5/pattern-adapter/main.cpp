#include <iostream>
#include <list>
#include<memory>
#include<array>

#include <chrono>
#include <thread>

typedef std::array<char, 10> Signal;

class Verarbeiter{
    public:
        virtual void verarbeiten(const Signal &s) = 0;
};

/*  Diese Klasse empfängt externe Signale und leitet diese an einen Verarbeiter weiter
    Wir nehmen für dieses Beispiel an, dass diese Klasse nicht unsere eigene ist, und wir diese
    daher nicht verändern können (kommt z.B. aus einer externen Library)
 */
class SignalEmpfaenger {
    private:
        std::unique_ptr<Verarbeiter> v;
    public:
        void setVerarbeiter(std::unique_ptr<Verarbeiter> v) {
            this->v = std::move(v);
        }
        void listenForExternalSignal(){
            for(int i = 0; i < 10; i++) {   //hier würde wohl while(true) o.ä. stehen
                Signal s;   //hier würde nun ein externer Sensor ausgelesen werden
                v->verarbeiten(s);

                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
        }
};

/*  Diese Klasse verarbeitet externe Signale.
    Wir nehmen für dieses Beispiel an, dass diese Klasse nicht unsere eigene ist, und wir diese
    daher nicht verändern können (kommt z.B. aus einer externen Library)
 */
class X {
    private:
        Signal s;
    public: 
        void setData(Signal &s) { this->s = s; }
        void preprocessData()   { std::cout << "hier findet das preprocessing statt" << std::endl; };
        int analyzeData()       { std::cout << "hier findet die eigentliche Analyse statt" << std::endl; return 23; };
        void cleanupData()      { std::cout << "hier findet das postprocessing statt" << std::endl; };
};

/*
    wir schreiben diese Klasse als Adapter, damit die beiden externen Klassen zusammenpassen.
*/
class WrapperX : public Verarbeiter {
    private:
        X x;
    public:
        void verarbeiten(const Signal &s) {
            Signal sx = s;
            x.setData(sx);  // x möchte keine const daten; Achtung: hier brechen wir das const-versprechen!
            x.preprocessData();
            x.analyzeData();
            x.cleanupData();
        }
};

int main() {
    SignalEmpfaenger receiver;
    receiver.setVerarbeiter(std::make_unique<WrapperX>());

    receiver.listenForExternalSignal();

}