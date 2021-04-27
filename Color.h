//----------------------------------------------------------------
// File name: Color.h
// Date: 4/26/2021
// Program Purpose: Header file utility functions for a Color 
//					object. A color is an alias for a Vec3 object 
//					to represent RGB colors
//----------------------------------------------------------------

#ifndef COLOR_H
#define COLOR_H

#include "Vec3.h"

void write_color(std::ostream& out, Color pixel_color)
{
	// Write out the translated [0, 255] value of each color component.
	const double multiplier{ 255.999 };
	out << static_cast<int>(multiplier * pixel_color.x()) << ' '
		<< static_cast<int>(multiplier * pixel_color.y()) << ' '
		<< static_cast<int>(multiplier * pixel_color.z()) << '\n';
}

#endif // !COLOR_H
