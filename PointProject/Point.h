/**
* @file Point.h
* @Author Sude Akkaya sude.akkayaaa@gmail.com
* @date Ocak, 2022
* @brief Point temel yapý sýnýfý.
*
* Point sýnýfý x,y,z koordinatlarý tanýmlama, uzaklýk hesaplama
*/
#pragma once
//! Point sýnýfý.
/*!
Noktalarýn oluþacaðý temel sýnýf
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
	//! x parametresi güncelleme
	void setX(double x)
	{
		this->x = x;
	}

	//! y parametresi güncelleme
	void setY(double y)
	{
		this->y = y;
	}

	//! z parametresi güncelleme
	void setZ(double z)
	{
		this->z = z;
	}

	//! x parametresine public ulaþma
	double getX() const
	{
		return this->x;
	}

	//! y parametresine public ulaþma
	double getY() const
	{
		return this->y;
	}

	//! z parametresine public ulaþma
	double getZ() const
	{
		return this->z;
	}

	//! noktanýn ayný baþka bir nokta ile ayný olup olmadýðýný gösterir
	bool operator==(Point&);

	//! noktanýn baþka bir nokta olan uzaklýðý hesaplanýr
	double distance(Point& toPoint);

	//! noktanýn orjine olan uzaklýðý hesaplanýr
	double distanceToOrigin(Point* toPoint);
};




