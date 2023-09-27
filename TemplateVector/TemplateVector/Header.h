#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <cmath>

template <typename T>
class Vect_t {
private:
	int size;
	T* coords;

public:
	Vect_t(int size);
	Vect_t(const Vect_t& v);
	~Vect_t();

	Vect_t<T> operator+ (const Vect_t<T>& v) const;
	Vect_t<T> operator- (const Vect_t<T>& v) const;
	double operator* (const Vect_t<T>& v) const;

	const Vect_t<T>& operator= (const Vect_t<T>& v);

	bool operator== (const Vect_t<T>& v) const;
	bool operator!= (const Vect_t<T>& v) const;

	friend std::istream& operator>> (std::istream& in, Vect_t<T>& v) {
		std::cout << "\n------- VECTOR CREATING -------";
		
		std::cout << "\nEnter vector's coordinates: \n";
		for (int i = 0; i < v.size; i++) {
			in >> v.coords[i];
		}
		std::cout << "--------------------------------\n\n";

		return in;
	}
	friend std::ostream& operator<< (std::ostream& out, const Vect_t<T>& v) {
		out << "\n+++++++ PRINT VECTOR +++++++\n";
		out << "Vector size: " << v.size << "\n";
		out << "Vector coordinates: \n";

		for (int i = 0; i < v.size; i++) {
			out << v.coords[i] << std::endl;
		}

		out << "++++++++++++++++++++++++++++\n\n";

		return out;
	}

	double len() const;
};

template <typename T>
Vect_t<T>::Vect_t(int size) {
	this->size = size;
	coords = new T[size];
}

template <typename T>
Vect_t<T>::Vect_t(const Vect_t& v) {
	size = v.size;
	coords = new T[size];

	for (int i = 0; i < size; i++) {
		coords[i] = v.coords[i];
	}
}

template <typename T>
Vect_t<T>::~Vect_t() {
	delete[] coords;
}

template <typename T>
Vect_t<T> Vect_t<T>::operator+ (const Vect_t<T>& v) const {
	if (size != v.size) {
		throw "Different sizes!";
	}

	Vect_t<T> res_v(*this);
	for (int i = 0; i < size; i++) {
		res_v.coords[i] += v.coords[i];
	}
	return res_v;
}

template <typename T>
Vect_t<T> Vect_t<T>::operator- (const Vect_t<T>& v) const {
	if (size != v.size) {
		throw "Different sizes!";
	}

	Vect_t<T> res_v(*this);
	for (int i = 0; i < size; i++) {
		res_v.coords[i] -= v.coords[i];
	}
	return res_v;
}

template <typename T>
double Vect_t<T>::operator* (const Vect_t<T>& v) const {
	if (size != v.size) {
		throw "Different sizes!";
	}

	T res = 0;
	for (int i = 0; i < size; i++) {
		res += coords[i] * v.coords[i];
	}

	return res;
}

template <typename T>
const Vect_t<T>& Vect_t<T>::operator= (const Vect_t<T>& v) {
	if (this == &v) {
		return *this;
	}

	if (size != v.size) {
		size = v.size;
		delete[] coords;
		coords = new T[size];
	}

	for (int i = 0; i < size; i++) {
		coords[i] = v.coords[i];
	}

	return *this;
}

template <typename T>
bool Vect_t<T>::operator== (const Vect_t<T>& v) const {
	if (size != v.size)
		return false;

	for (int i = 0; i < size; i++) {
		if (coords[i] != v.coords[i])
			return false;
	}

	return true;
}

template <typename T>
bool Vect_t<T>::operator!= (const Vect_t<T>& v) const {
	return !(*this == v);
}

template <typename T>
double  Vect_t<T>::len() const {
	return sqrt((*this) * (*this));
}

#endif