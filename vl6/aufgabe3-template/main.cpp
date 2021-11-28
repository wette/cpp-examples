#include<vector>
#include<memory>
#include<iostream>
#include <algorithm>
#include <random>
#include <functional>

template <typename T>
class SortAlgorithm{
    protected:
        std::function<bool(T, T)> less;
    public:
        virtual void sort(std::vector<T> &v) = 0;
        virtual void setCompareFunction(std::function<bool(T, T)> f) {
            less = f;
        };
};

template <typename T>
class BubbleSort: public SortAlgorithm<T> {
    public: 
        void sort(std::vector<T> &v){
            for(int i = 0; i < v.size(); i++){
                for(int j = 0; j < v.size(); j++){
                    if(SortAlgorithm<T>::less(v[i], v[j])) {
                        int temp = v[i];
                        v[i] = v[j];
                        v[j] = temp;
                    }
                }
            }
        }
};

template <typename T>
class QuickSort: public SortAlgorithm<T>{
    public: 
        void sort(std::vector<T> &v){
            quicksort(0, v.size()-1, v);
        }
    private:
        void quicksort(int left, int right, std::vector<T> &v){
            if(left < right) {
                int divider = divide(left, right, v);
                quicksort(left, divider-1, v);
                quicksort(divider+1, right, v);
            }
        } 
        int divide(int left, int right, std::vector<T> &v){
            int i = left;
            int j = right -1;
            T pivot = v[right];

            while(i < j) {
                while(i < right && SortAlgorithm<T>::less(v[i], pivot)){
                    i++;
                }
                while(j > left && !SortAlgorithm<T>::less(v[i], pivot)){
                    j--;
                }
                if(i < j) {
                    int temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            }

            if(!SortAlgorithm<T>::less(v[i], pivot)) {
                int temp = v[i];
                v[i] = v[right];
                v[right] = temp;
            }

            return i;
        }
};

class Sorter{
    private:
        std::shared_ptr<SortAlgorithm<int>> algo;

    public:
        void setAlgo(std::shared_ptr<SortAlgorithm<int>> a) {
            algo = a;
        }
        void sort(std::vector<int> &v) {
            auto start_time = std::chrono::steady_clock::now();
            algo->sort(v);
            auto end_time = std::chrono::steady_clock::now();

            std::chrono::nanoseconds duration_nano = end_time-start_time;
            std::chrono::milliseconds duration_milli = std::chrono::duration_cast<std::chrono::milliseconds>(duration_nano);
            std::cout << "Sorting took " << duration_milli.count() << " milliseconds" << std::endl;
        }
};


int main() {
    Sorter sorter;
    BubbleSort<int> bubble;
    QuickSort<int> quick;

    std::function<bool(int, int)> cmpFunc = [](int a, int b) { return a < b; };

    bubble.setCompareFunction(cmpFunc);
    quick.setCompareFunction(cmpFunc);

    /* seed des Zufallszahlengenerators setzen */
    std::srand(std::time(nullptr));

    /* daten generieren */
    std::vector<int> v;
    for(int i = 0; i < 10000; i++){
        v.push_back(i);
    }

    /* daten randomisieren */
    std::shuffle(v.begin(), v.end(), std::default_random_engine()); /*mischen*/

    /* strategie setzen und sortieren */
    sorter.setAlgo(std::make_shared<BubbleSort<int>>(bubble));
    sorter.sort(v);

    /* daten randomisieren */
    std::shuffle(v.begin(), v.end(), std::default_random_engine()); /*mischen*/

    /* strategie setzen und sortieren */
    sorter.setAlgo(std::make_shared<QuickSort<int>>(quick));
    sorter.sort(v);




    return 0;
}