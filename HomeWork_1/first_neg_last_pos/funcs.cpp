#include "funcs.h"
#include <iostream>

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