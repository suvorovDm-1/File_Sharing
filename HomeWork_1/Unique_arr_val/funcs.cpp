#include "funcs.h"
#include <iostream>

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