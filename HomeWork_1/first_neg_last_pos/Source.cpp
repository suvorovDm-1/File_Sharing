#include "funcs.h"
#include "..\StaticLib\Header.h"
#include <iostream>

int main() {
	int n;
	float l, r;

	std::cin >> n >> l >> r;

	float* a = create_a_range(n, l, r);
	print_a(n, a);

	try {
		change_a(n, a);
		print_a(n, a);
	}
	catch (const char* exp) {
		std::cout << exp;
	}

	delete[] a;

	return 0;
}