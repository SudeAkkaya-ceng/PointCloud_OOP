/**
* @file Point.h
* @Author Sude Akkaya sude.akkayaaa@gmail.com
* @date Ocak, 2022
* @brief Point temel yap� s�n�f�.
*
* Point s�n�f� x,y,z koordinatlar� tan�mlama, uzakl�k hesaplama
*/
#pragma once
//! Point s�n�f�.
/*!
Noktalar�n olu�aca�� temel s�n�f
*/
class Point
{
private:
	double x;
	double y;
	double z;
public:
	//! Point constructor.
	Point() {};
	//! Point constructor.
	Point(double x, double y, double z) { this->x = x, this->y = y, this->z = z; };
	//! Point destructor.
	~Point(void) {  };
	//! x parametresi g�ncelleme
	void setX(double x)
	{
		this->x = x;
	}

	//! y parametresi g�ncelleme
	void setY(double y)
	{
		this->y = y;
	}

	//! z parametresi g�ncelleme
	void setZ(double z)
	{
		this->z = z;
	}

	//! x parametresine public ula�ma
	double getX() const
	{
		return this->x;
	}

	//! y parametresine public ula�ma
	double getY() const
	{
		return this->y;
	}

	//! z parametresine public ula�ma
	double getZ() const
	{
		return this->z;
	}

	//! noktan�n ayn� ba�ka bir nokta ile ayn� olup olmad���n� g�sterir
	bool operator==(Point&);

	//! noktan�n ba�ka bir nokta olan uzakl��� hesaplan�r
	double distance(Point& toPoint);

	//! noktan�n orjine olan uzakl��� hesaplan�r
	double distanceToOrigin(Point* toPoint);
};




