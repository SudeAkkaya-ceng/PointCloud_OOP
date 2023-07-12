#include "Point.h"
#include <cmath>

/*!
\param point an Point class argument.
\return bool
*/
bool Point::operator==(Point& point)
{
	if (this->x == point.x && this->y == point.y && this->z == point.z)
		return true;
	else
		return false;

}

/*!
\param toPoint an Point class argument.
\return distance double
*/
double Point::distance(Point& toPoint) {
	return sqrt(pow(toPoint.x - x, 2) + pow(toPoint.y - y, 2) + pow(toPoint.z - z, 2));
}

/*!
\param toPoint an Point class argument.
\return distance double
*/
double Point::distanceToOrigin(Point* toPoint) {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}



