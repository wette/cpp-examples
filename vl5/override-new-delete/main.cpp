#include<iostream>
#include<memory>

class ClassA {
    std::shared_ptr<ClassA> bud;
    //std::weak_ptr<ClassA> bud;
    public:
        void setBuddy(std::shared_ptr<ClassA> &mybuddy) {
            bud = mybuddy;
        }
};

class MemoryUsage {
    private:
        int allocated = 0;
        int freed = 0;
    public:
        void memoryAllocated() {
            allocated += 1;
        }
        void memoryFreed() {
            freed += 1;
        }
        void print() {
            std::cout << "allocated: " << allocated << " freed: " << freed << " diff: " << allocated-freed << std::endl;
        }
};
MemoryUsage memUsage;

/*override new and delete operator*/
void* operator new(std::size_t count) {
    memUsage.memoryAllocated();
    return malloc(count);
}

void operator delete(void *ptr) noexcept{
    memUsage.memoryFreed();
    return free(ptr);
}

int main() {
    memUsage.print();
    for(int i = 0; i < 1000; i++) {
        std::shared_ptr<ClassA> a1 = std::make_shared<ClassA>();
        std::shared_ptr<ClassA> a2 = std::make_shared<ClassA>();
        a1->setBuddy(a2);
        a2->setBuddy(a1);
    }

    memUsage.print();
}