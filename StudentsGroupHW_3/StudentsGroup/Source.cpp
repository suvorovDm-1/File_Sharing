#include <iostream>
#include "Students.h"

int main() {
	StudentsGroup_t st_gr = StudentsGroup_t();

	Student_t st;
	std::cin >> st;

	st_gr.add_student(st);



	return 0;
}