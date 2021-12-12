#include<vector>
#include<memory>
#include<iostream>

class Product {
    protected:          /* wenn die unterklasse auf ein privates Attribut der Oberklasse zugreifen können soll,
                           muss dieses als protected gekennzeichnet sein. */ 
        double price;
    public:
        virtual double getPrice() = 0;
};

class Box : public Product {
    private:
        std::vector<std::shared_ptr<Product>> products;
    public:
        void add(std::shared_ptr<Product> product) {
            products.push_back(product);
        }
        double getPrice() {
            double sum = 0.0;
            for(std::shared_ptr<Product> p : products) {
                sum += p->getPrice();
            }
            return sum;
        }
};

class iPhone : public Product {
    public: 
        iPhone(double p) {
            price = p;      /* dürfen wir, weil price protected ist. */
        }
        double getPrice() {
            return price;
        }
};
class Hammer : public Product {
    public:
        Hammer(double p) {
            price = p;      /* dürfen wir, weil price protected ist. */
        }
        double getPrice() {
            return price;
        }
};

int main() {

    std::shared_ptr<Box> sendung = std::make_shared<Box>();

    std::shared_ptr<Box> iPhoneKiste = std::make_shared<Box>();
    std::shared_ptr<Box> hammerKiste = std::make_shared<Box>();

    for(int i = 0; i < 10; i++) {
        iPhoneKiste->add( std::make_shared<iPhone>(699.99) );
    }

    for(int i = 0; i < 10; i++) {
        hammerKiste->add( std::make_shared<Hammer>(19.99) );
    }

    sendung->add(iPhoneKiste);
    sendung->add(hammerKiste);
    sendung->add( std::make_shared<iPhone>(699.99) );   

    /* die sendung besteht nun aus 11 iPhones und 10 Hämmern. */
    std::cout << "Gesamtpreis: " << sendung->getPrice() << std::endl;

    return 0;
}