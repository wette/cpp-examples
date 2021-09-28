#include <string>
#include <iostream>
int main() {
	std::string a = "mein String.";

	a = a + std::string("Hier ist noch etwas");

	std::cout << a << std::endl;
}
