#include <iostream>
#include "Vector.h"

int main() {

	Vector_t v1, v2, v3;

	std::cin >> v1;
	std::cin >> v2;

	std::cout << v1;
	std::cout << v2;

	v3 = v2 + v1;
	std::cout << v3;
	v3 = v2 - v1;
	std::cout << v3;
	std::cout << v3.vector_len() << std::endl;

	std::cout << v1 * v2 << std::endl;
	std::cout << v1.vector_len() << std::endl;
	std::cout << v2.vector_len() << std::endl;

	std::cout << v1.angle_cos(v2) << std::endl;

	return 0;
}