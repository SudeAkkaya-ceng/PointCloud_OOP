/**
* @file PointCloud.h
* @Author Sude Akkaya sude.akkayaaa@gmail.com
* @date Ocak, 2022
* @brief PointCloud temel yapý sýnýfý.
*
* PointCloud sýnýfý Point sýnýfýný liste olarak saklama, kaç tan olduðunu gösterme
*/
#include "Point.h"
#include <iostream>
#include <list>
#include <iterator>
#include <vector>
using namespace std;
#pragma once
//! PointCloud sýnýfý.
/*!
Oluþan noktalarý mantýksal þekilde barýndýran sýnýf
*/
class PointCloud
{
private:

	list<Point> points;
	int pointNumber;
public:
	//! Point constructor.
	PointCloud() { this->pointNumber = 0; this->points; };
	//PointCloud(int pointNumber) { this->pointNumber=0; this->points; };

	//! Point destructor.
	~PointCloud() {  };

	//! points parametresine public ulaþma
	list<Point> getPoints() const
	{
		return this->points;
	}

	//! points parametresi güncelleme
	void setPoints(list<Point> points)
	{
		this->points = points;
	}

	//! pointNumber parametresine public ulaþma
	int getPointNumber() const
	{
		return this->pointNumber;
	}

	//! pointNumber parametresi güncelleme
	void setPointNumber(int pn)
	{
		pointNumber = pn;
	}

	//! her iki nokta bulutunun sahip olduðu noktalara sahip tek bir nokta bulutunu döndürür.
	PointCloud* appendPointCloud(PointCloud* pointCloud);

	//! bir nokta bulutunun	baþka bir nokta bulutuna kopyalanmasýný saðlar.
	PointCloud* getPointCloud();

	//! bir nokta bulutunun	baþka bir nokta bulutuna kopyalanmasýný saðlar.
	void addToPointCloud(Point point);
};




