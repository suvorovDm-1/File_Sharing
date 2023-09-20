#include "Students.h"

StudentsGroup_t::StudentsGroup_t() {
	current_size = 0;
	group = NULL;
}
StudentsGroup_t::StudentsGroup_t(int n) {
	this->current_size = n;
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