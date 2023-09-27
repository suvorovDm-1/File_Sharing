#include "Students.h"

StudentsGroup_t::StudentsGroup_t() {
	current_size = 0;
	group = NULL;
}
StudentsGroup_t::StudentsGroup_t(int n) {
	current_size = n;
	group = new Student_t[n];
}
StudentsGroup_t::StudentsGroup_t(const StudentsGroup_t& st_group) {
	current_size = st_group.current_size;
	group = new Student_t[current_size];

	for (int i = 0; i < current_size; i++) {
		group[i] = st_group.group[i];
	}
}
StudentsGroup_t::~StudentsGroup_t() {
	delete[] group;
}

void StudentsGroup_t::add_student(const Student_t& st) {
	Student_t* newGroup = new Student_t[current_size + 1];
	
	for (int i = 0; i < current_size; i++) {
		newGroup[i] = group[i];
	}
	newGroup[current_size] = st;

	delete[] group;
	current_size += 1;
	group = newGroup;
}

int StudentsGroup_t::find_student(const std::string surname) const {
	for (int i = 0; i < current_size; i++) {
		if (group[i].surname == surname)
			return i;
	}
	return -1;
}

void StudentsGroup_t::is_student_in_group(const std::string surname) const {
	if (find_student(surname) == -1) {
		std::cout << "No such student.\n";
	}
	else {
		std::cout << "This student is already in group.\n";
	}
}

void StudentsGroup_t::delete_student(const std::string surname) {
	int index_stud = find_student(surname);

	if (index_stud == -1) {
		throw "No such student";
	}

	Student_t* newGroup = new Student_t[current_size - 1];

	for (int i = 0; i < index_stud; i++) {
		newGroup[i] = group[i];
	}

	for (int i = index_stud + 1; i < current_size; i++) {
		newGroup[i - 1] = group[i];
	}

	delete[] group;
	current_size -= 1;
	group = newGroup;
}