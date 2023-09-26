#ifndef _STUDENTS_H_
#define _STUDENTS_H_

#include <iostream>

struct Data_t {
	int day;
	int month;
	int year;

	bool operator!= (const Data_t& st) const;
	friend std::istream& operator>> (std::istream& in, Data_t& date) {
		std::cout << "\n\tEnter day of birth: ";
		in >> date.day;

		std::cout << "\tEnter month of birth: ";
		in >> date.month;

		std::cout << "\tEnter year of birth: ";
		in >> date.year;

		return in;
	}
	friend std::ostream& operator<< (std::ostream& out, Data_t& date) {
		std::cout << "\n\t\tDay of birth: ";
		out << date.day;

		std::cout << "\n\t\tMonth of birth: ";
		out << date.month;

		std::cout << "\n\t\tYear of birth: ";
		out << date.year;

		return out;
	}
};

struct Student_t {
	std::string surname;
	Data_t date_of_birth;
	int phone_number;

	bool operator== (const Student_t& st) const;
	friend std::istream& operator>> (std::istream& in, Student_t& st) {
		std::cout << "----------------------------------\n";
		std::cout << "Entering data about a new student:";

		std::cout << "\nEnter student surname: ";
		in >> st.surname;

		std::cout << "\nEnter his date of birth: ";
		in >> st.date_of_birth;

		std::cout << "\nEnter student phone number: ";
		in >> st.phone_number;

		std::cout << "\n----------------------------------\n";

		return in;
	}
	friend std::ostream& operator<< (std::ostream& out, Student_t& st) {
		out << "+++  +++  +++  +++  +++  +++  +++";
		out << "\nStudent info: ";
		out << "\n\tStudent surname: " << st.surname;
		out << "\n\tDate of birth: " << st.date_of_birth;
		out << "\n\tPhone number: " << st.phone_number;
		out << "\n+++  +++  +++  +++  +++  +++  +++\n";

		return out;
	}
};

class StudentsGroup_t {
private:
	int current_size;
	/*int step_of_increasing;*/
	Student_t* group;

	int find_student(const Student_t& st) const;

public:
	StudentsGroup_t();
	StudentsGroup_t(int n);
	StudentsGroup_t(const StudentsGroup_t& st_group);
	~StudentsGroup_t();

	void is_student_in_group(const Student_t& st) const;
	void add_student(const Student_t& st);
	void delete_student(const Student_t& st);

	friend std::ostream& operator<< (std::ostream& out, const StudentsGroup_t& gr) {
		std::cout << "-----------  INFO OF ALL GROUP  -----------";
		for (int i = 0; i < gr.current_size; i++) {
			out << "\n" << i + 1 << ". " << gr.group[i];
		}

		return out;
	}
};

#endif