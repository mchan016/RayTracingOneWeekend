//----------------------------------------------------------------
// File name: Ray.h
// Date: 4/26/2021
// Program Purpose: Header file for Ray class that represents a 
//					ray in 3D space with formulat P(t) = A + tb,
//					where P(t) represents position of a ray at
//					time t, A is the original position of the ray,
//					b is the direction of the ray and t is time
//					since ray started from origin.
//----------------------------------------------------------------

#ifndef RAY_H
#define RAY_H

#include "Vec3.h"

class Ray
{
private:
	Point3 _orig;
	Vec3 _dir;

public:
	// Constructors
	Ray() {}
	Ray(const Point3& origin, const Vec3& direction)
		: _orig(origin), _dir(direction) {}

	// Getters
	Point3 origin() const { return _orig; }
	Vec3 direction() const { return _dir; }

	// Member functions
	Point3 at(double t) const
	{
		return _orig + (t * _dir);
	}
};

#endif // !RAY_H

