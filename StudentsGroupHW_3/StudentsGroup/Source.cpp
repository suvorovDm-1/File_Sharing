#include <iostream>
#include "Students.h"

int main() {
	StudentsGroup_t st_gr;


	// Adding students
	int num_stud;
	std::cout << "Enter number of students: ";
	std::cin >> num_stud;
	std::cout << std::endl;

	for (int i = 0; i < num_stud; i++) {
		Student_t st;
		std::cout << i + 1 << ". ";
		
		std::cin >> st;

		st_gr.add_student(st);
	}

	std::cout << st_gr;

	std::cout << "\n\n**************************************************\n";
	

	std::string surname;

	// Check existing
	std::cin >> surname;
	st_gr.is_student_in_group(surname);

	std::cout << "\n\n**************************************************\n";

	// Deleting sone student
	std::cin >> surname;
	try {
		st_gr.delete_student(surname);
		std::cout << st_gr;
	}
	catch (const char* exp) {
		std::cout << "\n" << exp << "\n";
	}

	return 0;
}