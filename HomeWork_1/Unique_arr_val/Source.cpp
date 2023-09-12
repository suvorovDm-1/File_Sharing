#include "funcs.h"
#include <iostream>

int main() {
	int n;
	std::cin >> n;

	int* a = create_a(n);
	print_a(n, a);

	int n_uniq;
	int* a_without_duplicates = delete_duplicates(n, a, n_uniq);

	print_a(n_uniq, a_without_duplicates);

	delete[] a;
	delete[] a_without_duplicates;

	return 0;
}