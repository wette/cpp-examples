#include <iostream>
#include <memory>

/*forward declaration damit wir die beiden Klassen Sohn und Tochter in Klasse Mutter nutzen können.*/
class Sohn;
class Tochter;

class Mutter{
    public:
        ~Mutter(){
            std::cout << "Destruktor der Mutter aufgerufen" << std::endl;
        }
        void setSohn(std::shared_ptr<Sohn> s ){
            mySohn=s;
        }
        std::shared_ptr<Sohn> getSohn() {
            return mySohn;
        }
        void setTochter(std::shared_ptr<Tochter> t ){
            myTochter=t;
        }
        std::shared_ptr<Tochter> getTochter() {
            return myTochter;
        }

    private:
    std::shared_ptr<Sohn> mySohn;
    std::shared_ptr<Tochter> myTochter;
};

class Sohn{
    public:
        Sohn(std::shared_ptr<Mutter> m):myMutter(m){}
        ~Sohn(){
            std::cout << "Destruktor des Sohns aufgerufen" << std::endl;
        }
        void print(){ std::cout << "Speicheradresse Sohn: " << this << std::endl;  }
    private:
        std::shared_ptr<Mutter> myMutter;
};

class Tochter{
    public:
        Tochter(std::shared_ptr<Mutter> m):myMutter(m){}
        ~Tochter(){
            std::cout << "Destruktor der Tochter aufgerufen" << std::endl;
        }
        void print(){ std::cout << "Speicheradresse Tochter: " << this << std::endl;  }
    private:
      std::shared_ptr<Mutter> myMutter;
};

int main(){
  std::cout << "Start" << std::endl;

    {
        std::shared_ptr<Mutter> mutter = std::shared_ptr<Mutter>( new Mutter());
        {
            std::shared_ptr<Sohn> sohn = std::shared_ptr<Sohn>( new Sohn(mutter) );
            std::shared_ptr<Tochter> tochter = std::shared_ptr<Tochter>( new Tochter(mutter) );
            mutter->setSohn(sohn);
            mutter->setTochter(tochter);
        }
        std::cout << "Inner Scope verlassen. Stack wurde abgebaut." << std::endl;
        
    }
    std::cout << "Outer Scope verlassen. Stack wurde abgebaut." << std::endl;
    std::cout << "Ende" << std::endl;
}