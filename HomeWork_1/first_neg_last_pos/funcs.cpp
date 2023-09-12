#include "funcs.h"
#include <iostream>

float* create_a(int n, int l, int r) {
	float* a = new float[n];
	srand((unsigned int)time(0));

	for (int i = 0; i < n; i++) {
		a[i] = (((r - l) / double(RAND_MAX)) * rand()) + l;
	}

	return a;
}

void print_a(int n, float* a) {
	std::cout << "-------------------" << std::endl;
	for (int i = 0; i < n; i++)
		std::cout << a[i] << std::endl;
	std::cout << "-------------------" << std::endl;
}

void change_a(int n, float* a) {
	int i = 0, j = n - 1, s1 = -1, s2 = -1;

	while (i < n && j > -1) {
		if (a[i] < 0 && s1 == -1) {
			s1 = i;
		}
		if (a[j] > 0 && s2 == -1) {
			s2 = j;
		}

		i++, j--;
	}

	if (s1 == -1)
		throw "no negative";
	if (s2 == -1)
		throw "no positive";
	
	float tmp = a[s1];
	a[s1] = a[s2];
	a[s2] = tmp;
}