#ifndef _QC_include_point_h_ //header guard
#define _QC_include_point_h_

#include "qcmath.h"

class Point{
	
public:
	double x,y,z;

	Point();
	Point(double x, double y, double z);
	
	Point operator+(Point, Point);
	Point operator-(Point, Point);
	Point operator-(Point)
	Point operator*(Point, Point); // inner product

	double modulus();
	
};


#endif // header guard