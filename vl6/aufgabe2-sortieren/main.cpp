#include<vector>
#include<memory>
#include<iostream>
#include <algorithm>
#include <random>

class SortAlgorithm{
    public:
        virtual void sort(std::vector<int> &v) = 0;
};

class BubbleSort: public SortAlgorithm {
    public: 
        void sort(std::vector<int> &v){
            for(int i = 0; i < v.size(); i++){
                for(int j = 0; j < v.size(); j++){
                    if(v[i] < v[j]) {
                        int temp = v[i];
                        v[i] = v[j];
                        v[j] = temp;
                    }
                }
            }
        }
};

class QuickSort: public SortAlgorithm{
    public: 
        void sort(std::vector<int> &v){
            quicksort(0, v.size()-1, v);
        }
    private:
        void quicksort(int left, int right, std::vector<int> &v){
            if(left < right) {
                int divider = divide(left, right, v);
                quicksort(left, divider-1, v);
                quicksort(divider+1, right, v);
            }
        } 
        int divide(int left, int right, std::vector<int> &v){
            int i = left;
            int j = right -1;
            int pivot = v[right];

            while(i < j) {
                while(i < right && v[i] < pivot){
                    i++;
                }
                while(j > left && v[i] >= pivot){
                    j--;
                }
                if(i < j) {
                    int temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            }

            if(v[i] > pivot) {
                int temp = v[i];
                v[i] = v[right];
                v[right] = temp;
            }

            return i;
        }
};

class Sorter{
    private:
        std::shared_ptr<SortAlgorithm> algo;

    public:
        void setAlgo(std::shared_ptr<SortAlgorithm> a) {
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
    BubbleSort bubble;
    QuickSort quick;

    /* seed des Zufallszahlengenerators setzen */
    std::srand(std::time(nullptr));

    /* daten generieren */
    std::vector<int> v;
    for(int i = 0; i < 100000; i++){
        v.push_back(i);
    }

    /* daten randomisieren */
    std::shuffle(v.begin(), v.end(), std::default_random_engine()); /*mischen*/

    /* strategie setzen und sortieren */
    sorter.setAlgo(std::make_shared<QuickSort>(quick));
    sorter.sort(v);

    /* daten randomisieren */
    std::shuffle(v.begin(), v.end(), std::default_random_engine()); /*mischen*/

    /* strategie setzen und sortieren */
    sorter.setAlgo(std::make_shared<BubbleSort>(bubble));
    sorter.sort(v);


    return 0;
}