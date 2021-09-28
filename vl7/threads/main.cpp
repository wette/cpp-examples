#include<iostream>
#include<thread>
#include <chrono>

void func(int threadNo) {
    for(int i = 0; i < 10; i++) {
        std::cout << "Thread " << threadNo << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

class myClass{
    private:
        int iterations = 10;
    public:
        void func(int threadNo) {
            for(int i = 0; i < iterations; i++) {
                std::cout << "Thread " << threadNo << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }       
        }
};


int main() {

    //erstellen eines neuen Threads, der func(2) ausführt.
    std::thread t(func, 2);

    //ausführen von func(1) im "Main Thread"
    func(1);

    //warten, bis t fertig ist ist.
    t.join();

    //ausführen einer Funktion im Objektkontext in einem Thread
    myClass c;
    std::thread t2(&myClass::func, c, 3);   //ruft c.func(3) im Thread auf.

    func(1);
    
    t2.join();

    return 0;
}