#include<iostream>

class MySingleton {
	public:
		static MySingleton& getInstance(){
            static MySingleton obj; /* static variablen werden _einmal_ initialisiert und leben
                                       über die gesammte Programmlaufzeit! */
			return obj;
		}
        void setData(int d) { data = d; }
        int getData() { return data; }
		
        
	private:
        int data;
		MySingleton(){  data = 23; }
		MySingleton( const MySingleton& ); /*cpy-constr*/
        ~MySingleton() {}
};

int main() {

    /* Zugriff über die statische Methode der Klasse */
    std::cout << MySingleton::getInstance().getData() << std::endl;
    MySingleton::getInstance().setData(100);
    std::cout << MySingleton::getInstance().getData() << std::endl;

    /* oder über eine lokale referenz auf die statische variable der Klasse */
    MySingleton &x = MySingleton::getInstance();
    std::cout << x.getData() << std::endl;
    x.setData(1);
    std::cout << MySingleton::getInstance().getData() << std::endl;
    std::cout << x.getData() << std::endl;


    return 0;
}