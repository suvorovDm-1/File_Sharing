#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>

class Vector_t {
private:
	double x;
	double y;
	double z;

public:
	Vector_t();
	Vector_t(double x, double y, double z);

	Vector_t operator + (const Vector_t& v) const;

	Vector_t operator - (const Vector_t& v) const;

	double operator * (const Vector_t& v) const;

	const Vector_t& operator = (const Vector_t& v);

	double vector_len() const;

	double angle_cos(const Vector_t& v) const;

	friend std::istream& operator>> (std::istream& in, Vector_t& v) {
		double v_x, v_y, v_z;

		in >> v_x;
		in >> v_y;
		in >> v_z;

		v = Vector_t(v_x, v_y, v_z);

		return in;
	}
	friend std::ostream& operator<< (std::ostream& out, Vector_t& v) {
		out << "(" << v.x << ", " << v.y << ", " << v.z << ")\n";

		return out;
	}
};

#endif