#include "funcs.h"
#include <iostream>

int* create_a(int n) {
	int* a = new int[n];

	for (int i = 0; i < n; i++)
		std::cin >> a[i];

	return a;
}

void print_a(int n, int* a) {
	std::cout << "-------------------" << std::endl;
	for (int i = 0; i < n; i++)
		std::cout << a[i] << std::endl;
	std::cout << "-------------------" << std::endl;
}

int count_unique(int n, int* a) {
	int c_u = 0;

	for (int i = 0; i < n; i++) {
		bool flag = false;

		for (int j = 0; j < i; j++) {
			if (a[i] == a[j]) {
				flag = true;
				break;
			}
		}

		if (!flag) c_u++;
	}

	return c_u;
}

int* delete_duplicates(int n, int* a, int& n_unique) {
	n_unique = count_unique(n, a);
	int* unique_a = new int[n_unique];

	int i_unique = 0;
	for (int i = 0; i < n; i++) {
		bool flag = false;

		for (int j = 0; j < i; j++) {
			if (a[i] == a[j]) {
				flag = true;
				break;
			}
		}

		if (!flag) {
			unique_a[i_unique] = a[i];
			i_unique++;
		}
	}

	return unique_a;
}