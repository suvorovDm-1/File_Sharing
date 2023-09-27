#include "Header.h"
#include <iostream>

int main() {
	int n;
	std::cin >> n;

	Vect_t<int> v1(n);
	Vect_t<int> v2(n);
	Vect_t<int> v3(n + 1);

	std::cin >> v1;
	std::cin >> v2;
	std::cin >> v3;

	try {
		std::cout << v1 + v2;
		std::cout << v2 - v1;
		std::cout << v2 - v3;
	}
	catch (const char* exp) {
		std::cout << "\n" << exp << "\n";
	}

	try {
		std::cout << v1 * v2 << "\n";
		v3 = v1 + v2;
		std::cout << v2 - v3;

		bool res = ((v1 + v2) == v3);
		std::cout << res << "\n";

		res = (v1 != v2);
		std::cout << res << "\n";

		std::cout << v1.len() << "\n";
		std::cout << v2.len() << "\n";
		std::cout << v3.len() << "\n";
	}
	catch (const char* exp) {
		std::cout << "\n" << exp << "\n";
	}

	return 0;
}