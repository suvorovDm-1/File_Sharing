#include <cmath>
#include <iostream>
#include "Vector.h"

Vector_t::Vector_t() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector_t::Vector_t(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector_t Vector_t::operator + (const Vector_t& v) const {
	return Vector_t(x + v.x, y + v.y, z + v.z);
}

Vector_t Vector_t::operator - (const Vector_t& v) const {
	return Vector_t(x - v.x, y - v.y, z - v.z);
}

double Vector_t::operator * (const Vector_t& v) const {
	return x * v.x + y * v.y + z * v.z;
}

const Vector_t& Vector_t::operator = (const Vector_t& v) {
	x = v.x;
	y = v.y;
	z = v.z;

	return *this;
}

double Vector_t::vector_len() const {
	return sqrt((*this) * (*this));
}

double Vector_t::angle_cos(const Vector_t& v) const {
	return ((*this) * v) / (this->vector_len() * v.vector_len());
}