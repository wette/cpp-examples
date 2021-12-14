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
        virtual std::unique_ptr<Transport> createTransport() = 0;
};

class TruckFactory: public LogisticsFactory {
    public:
        std::unique_ptr<Transport> createTransport() {
            return std::make_unique<Truck>();
        }
};

class ShipFactory: public LogisticsFactory {
    public:
        std::unique_ptr<Transport> createTransport() {
            return std::make_unique<Ship>();
        }
};

int main() {
    std::unique_ptr<TruckFactory> tf = std::make_unique<TruckFactory>();
    std::unique_ptr<ShipFactory> sf  = std::make_unique<ShipFactory>();;
    std::unique_ptr<LogisticsFactory> f = std::move(tf);

    std::unique_ptr<Transport> t0 = f->createTransport();
    std::unique_ptr<Transport> t1 = f->createTransport();

    f = std::move(sf);

    std::unique_ptr<Transport> t2 = f->createTransport();

    t0->whoAmI();
    t1->whoAmI();
    t2->whoAmI();
}