#include "Students.h"

bool Data_t::operator!= (const Data_t& st) const {
	if (day != st.day)
		return true;
	if (day != st.day)
		return true;
	if (day != st.day)
		return true;

	return false;
}

bool Student_t::operator== (const Student_t& st) const {
	if (surname != st.surname) {
		return false;
	}
	if (date_of_birth != st.date_of_birth) {
		return false;
	}
	if (phone_number != st.phone_number) {
		return false;
	}
	return true;
}

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

int StudentsGroup_t::find_student(const Student_t& st) const {
	for (int i = 0; i < current_size; i++) {
		if (group[i] == st)
			return i;
	}
	return -1;
}

void StudentsGroup_t::is_student_in_group(const Student_t& st) const {
	if (find_student(st) == -1) {
		std::cout << "No such student.\n";
	}
	else {
		std::cout << "This student is already in group.\n";
	}
}

void StudentsGroup_t::delete_student(const Student_t& st) {
	int index_stud = find_student(st);

	if (index_stud == -1) {
		throw "No such student";
	}

	Student_t* newGroup = new Student_t[current_size - 1];

	for (int i = 0; i < current_size; i++) {
		if (i != index_stud)
			newGroup[i] = group[i];
	}

	delete[] group;
	current_size -= 1;
	group = newGroup;
}