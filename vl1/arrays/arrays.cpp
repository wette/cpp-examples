#include <iostream>
#include <array>

int main() {
	const int n = 20;
	std::array<int, n> arr;
	arr[0] = 1;
	arr[1] = 1;
	for(int i = 2; i < n; i++) {
		arr[i] = arr[i-2] + arr[i-1];
	}
	for(auto x: arr) {
		std::cout << x << std::endl;
	}
	return 0;
}
