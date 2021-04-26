//----------------------------------------------------------------
// File name: Vec3.cpp
// Date: 4/26/2021
// Program Purpose: Header file for the Vec3 class that represents
//					a generic vector with three components that
//					can be repurposed as an RGB color or a point
//					within the 3D space.
//					
//					Also includes utility functions to be used by
//					the class
//----------------------------------------------------------------

#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>
#include <vector>

class Vec3
{
private:
	std::vector<double> _coords;

public:
	Vec3() : _coords{ 0, 0, 0 } {}
	Vec3(double x, double y, double z)
		: _coords{ x, y, z } {}

	// Getters
	double x() const { return _coords[0]; }
	double y() const { return _coords[1]; }
	double z() const { return _coords[2]; }

	// Overloaded operators
	Vec3 operator-() const { return Vec3(-_coords[0], -_coords[1], -_coords[2]); }
	double operator[] (int i) const { return _coords[i]; }
	double& operator[] (int i) { return _coords[i]; }

	Vec3& operator+=(const Vec3& v)
	{
		_coords[0] += v._coords[0];
		_coords[1] += v._coords[1];
		_coords[2] += v._coords[2];

		return *this;
	}

	Vec3& operator*=(const double t)
	{
		_coords[0] *= t;
		_coords[1] *= t;
		_coords[2] *= t;

		return *this;
	}

	Vec3& operator/=(const double t)
	{
		return *this *= (1 / t);
	}

	// Member functions
	double length() const { return std::sqrt(length_squared()); }
	double length_squared() const
	{
		return _coords[0] * _coords[0] +
			_coords[1] * _coords[1] +
			_coords[2] * _coords[2];
	}
};

// Type aliases for Vec3
using Point3 = Vec3;
using Color = Vec3;

/*
* Vec3 utility functions
*/
// Faciliate output
inline std::ostream& operator<<(std::ostream& out, const Vec3& v)
{
	out << v.x() << ' ' << v.y() << ' ' << v.z();
}

// Sum between two vectors
inline Vec3 operator+(const Vec3& u, const Vec3& v)
{
	return Vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

// Difference between two vectors
inline Vec3 operator-(const Vec3& u, const Vec3& v)
{
	return Vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

// Product between two vectors
inline Vec3 operator*(const Vec3& u, const Vec3& v)
{
	return Vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

// Constant Product
inline Vec3 operator*(double t, const Vec3& v)
{
	return Vec3(t * v.x(), t * v.y(), t * v.z());
}

// Constant division
inline Vec3 operator/(Vec3 v, double t)
{
	return (1 / t) * v;
}

// Dot product
inline double dot(const Vec3& u, const Vec3& v)
{
	return u.x() * v.x() +
		u.y() * v.y() +
		u.z() * v.z();
}

// Cross Product
inline Vec3 cross(const Vec3& u, const Vec3& v)
{
	return Vec3(u.y() * v.z() - u.z() * v.y(),
		u.z() * v.x() - u.x() * v.z(),
		u.x() * v.y() - u.y() * v.x());
}

// Unit Vector
inline Vec3 unit_vector(Vec3 v)
{
	return v / v.length();
}

#endif // !VEC3_H

