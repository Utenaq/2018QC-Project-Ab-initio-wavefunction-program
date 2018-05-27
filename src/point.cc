#include "../include/point.h"
#include 

Point::Point(){
	
	x = 0; y = 0; z = 0;
	
}

Point::Point(double _x, double _y; double _z){
	
	x = _x; y = _y; z = _z;
	
}

Point Point::operator+ (Point _A, Point _B){
	
	Point _p(_A.x+_B.x, _A.y+_B.y, _A.z+_B.z);
	
	return _p;
	
}

Point Point::operator-(Point _A){
	
	Point _p = (-_A.x, -_A.y, -_A.z);
	return _p;
	
}

Point Point::operator- (Point _A, Point_B){
	
	return _A+(-_B);
	
}

double Point::operator* (Point _A, Point _B){
	
	return (_A.x*_B.x + _A.y*_B.y + _A.z*_B.z);
	
}

double Point::modulus(){
	
	return QCMath::sqrt(x*x + y*y + z*z);
	
}