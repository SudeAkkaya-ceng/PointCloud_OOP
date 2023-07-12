#include "PointCloud.h"
using namespace std;
/*!
\param pointCloud an PointCloud class argument.
\return new appended PointCloud class
*/
PointCloud* PointCloud::appendPointCloud(PointCloud* pointCloud) {
	//int newPointNumber = pointCloud->getPointNumber();
	//for (int i = 0; i < newPointNumber; i++)
	//{
	//	points.push_back(pointCloud->points[i]);
	//}

	list<Point>::iterator it;
	for (it = pointCloud->points.begin(); it != pointCloud->points.end(); it++)
	{
		points.push_back(*it);
	}

	setPointNumber(getPointNumber() + pointCloud->getPointNumber());

	return getPointCloud();
}

/*!
\param nothing argument.
\return PointCloud class
*/
PointCloud* PointCloud::getPointCloud() {
	PointCloud* result = new PointCloud;
	result->points = points;
	result->pointNumber = pointNumber;

	return result;
}

/*!
\param point an Point class argument.
\return PointCloud class
*/
void PointCloud::addToPointCloud(Point point) {
	points.push_back(point);
	pointNumber++;
}


