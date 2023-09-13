#include "header.h"
#include <iostream>

int* create_a(int n) {
	int* a = new int[n];

	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	return a;
}

void print_a(int n, float* a) {
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << std::endl;
	}
	std::cout << "\n";
}

void print_a(int n, int* a) {
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << std::endl;
	}
	std::cout << "\n";
}

float* create_a_range(int n, int l, int r) {
	float* a = new float[n];
	srand((unsigned int)time(0));

	for (int i = 0; i < n; i++) {
		a[i] = (((r - l) / double(RAND_MAX)) * rand()) + l;
	}

	return a;
}