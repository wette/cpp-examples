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
		
        ~MySingleton() {}
	private:
        int data;
		MySingleton(){  data = 23; }
		MySingleton( const MySingleton& ); /*cpy-constr*/
};

int main() {

    std::cout << MySingleton::getInstance().getData() << std::endl;
    MySingleton::getInstance().setData(100);
    std::cout << MySingleton::getInstance().getData() << std::endl;

    MySingleton &x = MySingleton::getInstance();
    x.setData(1);
    std::cout << MySingleton::getInstance().getData() << std::endl;
    std::cout << x.getData() << std::endl;

    return 0;
}