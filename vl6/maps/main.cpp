#include<map>
#include<unordered_map>
#include<chrono>
#include<iostream>
#include<iterator>
#include<vector>


template<typename T>
long long insert(T &map) {
    auto start_time = std::chrono::steady_clock::now();

    for(int i = 0; i < 10000; i++) {
        map[i] = i;
    }

    auto end_time = std::chrono::steady_clock::now();
    std::chrono::nanoseconds duration = end_time-start_time;
    
    return duration.count();
}

template<typename T>
long long iterate(T &map) {
    auto start_time = std::chrono::steady_clock::now();

    long long sum = 0;
    for(auto& element : map) {
        sum += element.first;
    }

    auto end_time = std::chrono::steady_clock::now();
    std::chrono::nanoseconds duration = end_time-start_time;
    
    return duration.count();
}

long long sorted_unordered_map_iterate(std::unordered_map<int, int> &map) {
    auto start_time = std::chrono::steady_clock::now();

    std::vector<int> keys;
    keys.reserve (map.size());
    for (auto& element : map) {
        keys.push_back(element.first);
    }
    std::sort (keys.begin(), keys.end());

    long long sum = 0;
    for (auto& element : keys) {
        sum += map[element];
    }

    auto end_time = std::chrono::steady_clock::now();
    std::chrono::nanoseconds duration = end_time-start_time;
    
    return duration.count();
}

int main() {

    std::map<int, int> map;
    std::unordered_map<int, int> unordered_map;

    std::cout << "insert into map took                     " << insert(map) << " nanoseconds" << std::endl;
    std::cout << "insert into unordered_map took           " << insert(unordered_map) << " nanoseconds" << std::endl;

    std::cout << "iterate over map took                    " << iterate(map) << " nanoseconds" << std::endl;
    std::cout << "iterate over unordered_map took          " << iterate(unordered_map) << " nanoseconds" << std::endl;
    
    std::cout << "oredered iterate over map took           " << iterate(map) << " nanoseconds" << std::endl;
    std::cout << "ordered iterate over unordered_map took  " << sorted_unordered_map_iterate(unordered_map) << " nanoseconds" << std::endl;

    return 0;
}