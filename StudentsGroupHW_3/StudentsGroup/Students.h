#ifndef _STUDENTS_H_
#define _STUDENTS_H_

#include <iostream>

struct Data_t {
	int day;
	int month;
	int year;

	friend std::istream& operator>> (std::istream& in, Data_t& date) {
		std::cout << "\nEnter day of birth: ";
		in >> date.day;

		std::cout << "\nEnter month of birth: ";
		in >> date.month;

		std::cout << "\nEnter year of birth: ";
		in >> date.year;
	}
};

struct Student_t {
	std::string surname;
	Data_t date_of_birth;
	int phone_number;

	friend std::istream& operator>> (std::istream& in, Student_t& st) {
		std::cout << "Entering data about a new student:";

		std::cout << "\nEnter student surname: ";
		in >> st.surname;

		std::cout << "\nEnter your date of birth: ";
		in >> st.date_of_birth;

		std::cout << "\nEnter student phone number: ";
		in >> st.phone_number;
	}
};

class StudentsGroup_t {
private:
	int current_size;
	/*int step_of_increasing;*/
	Student_t* group;

public:
	StudentsGroup_t();
	StudentsGroup_t(int n);
	StudentsGroup_t(const StudentsGroup_t& st_group);
	~StudentsGroup_t();

	void add_student(const Student_t& st);
	friend std::ostream& operator<< (std::ostream& out, const StudentsGroup_t& gr) {
		for (int i = 0; i < gr.current_size; i++) {
			out << gr.group[i]; // YOU HAVE TO CREATE COUT OVERLOADING!!!!
		}
	}
};

#endif