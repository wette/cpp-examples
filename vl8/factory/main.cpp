#include<memory>
#include<iostream>

class Transport {
    public:
        virtual void whoAmI() = 0;
};
class Truck : public Transport{
    public:
        void whoAmI() {
            std::cout << "I am a Truck!" << std::endl;
        }
};
class Ship : public Transport{
    public:
        void whoAmI() {
            std::cout << "I am a Ship!" << std::endl;
        }
};

class LogisticsFactory {
    public: 
        virtual std::shared_ptr<Transport> createTransport() = 0;
};

class TruckFactory: public LogisticsFactory {
    public:
        std::shared_ptr<Transport> createTransport() {
            return std::make_shared<Truck>();
        }
};

class ShipFactory: public LogisticsFactory {
    public:
        std::shared_ptr<Transport> createTransport() {
            return std::make_shared<Ship>();
        }
};

int main() {
    std::shared_ptr<TruckFactory> tf = std::make_shared<TruckFactory>();
    std::shared_ptr<ShipFactory> sf  = std::make_shared<ShipFactory>();
    std::shared_ptr<LogisticsFactory> f = tf;

    std::shared_ptr<Transport> t0 = f->createTransport();
    std::shared_ptr<Transport> t1 = f->createTransport();

    f = sf;

    std::shared_ptr<Transport> t2 = f->createTransport();

    t0->whoAmI();
    t1->whoAmI();
    t2->whoAmI();
}

