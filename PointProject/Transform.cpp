#include "Transform.h"
#include "Point.h"
#include "PointCloud.h"
#include <cmath>
#include <Eigen/Core>

/*!
\param ang an double array.
\return void
*/
void Transform::setRotation(double ang[])
{
	setAngles(Eigen::Vector3d(ang[0], ang[1], ang[2]));
}

/*!
\param ang an Vector3d.
\return void
*/
void Transform::setRotation(Eigen::Vector3d ang)
{
	setAngles(ang);
}

/*!
\param tr an double array.
\return void
*/
void Transform::setTranslation(double tr[])
{
	setTrans(Eigen::Vector3d(tr[0], tr[1], tr[2]));
}

/*!
\param tr an Vector3d.
\return void
*/
void Transform::setTranslation(Eigen::Vector3d tr)
{
	setTrans(tr);
}

/*!
\param p an Point class argument.
\return Point class
*/
Point Transform::doTransform(Point p)
{
	//Eigen::Matrix4d temp;
	Eigen::Matrix4d temp;
	Eigen::Vector3d tr = this->getTrans();
	Eigen::Vector4d tempPoint;
	tempPoint << p.getX(), p.getY(), p.getZ(), 1;
	Point taPoint;

	double teta = this->getAngles()[0] * 3.14159 / 180;
	double beta = this->getAngles()[1] * 3.14159 / 180;
	double alfa = this->getAngles()[2] * 3.14159 / 180;

	temp << cos(alfa) * cos(beta),
		(cos(alfa) * sin(beta) * sin(teta)) - (sin(alfa) * cos(teta)),
		(cos(alfa) * sin(beta) * cos(teta)) + (cos(alfa) * sin(teta)),
		tr[0],
		sin(alfa) * cos(beta),
		(sin(alfa) * sin(beta) * sin(teta)) + (cos(alfa) * cos(teta)),
		(sin(alfa) * sin(beta) * cos(teta)) - (cos(alfa) * sin(teta)),
		tr[1],
		-sin(beta),
		cos(beta) * sin(teta),
		cos(beta) * cos(teta),
		tr[2],
		0, 0, 0, 1;

	Eigen::Vector4d result = temp * tempPoint;

	taPoint.setX(result[0]);
	taPoint.setY(result[1]);
	taPoint.setZ(result[2]);

	return taPoint;
}

/*!
\param p an PointCloud class argument.
\return PointCloud class
*/
PointCloud Transform::doTransform(PointCloud p)
{
	list<Point> temp = p.getPoints();
	list<Point> taPointCloud;
	list<Point>::iterator it;
	for (it = temp.begin(); it != temp.end(); ++it)
	{
		taPointCloud.push_back(doTransform(*it));
	}

	p.setPoints(taPointCloud);

	return p;
}

