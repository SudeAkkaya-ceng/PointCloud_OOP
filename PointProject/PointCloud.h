/**
* @file PointCloud.h
* @Author Sude Akkaya sude.akkayaaa@gmail.com
* @date Ocak, 2022
* @brief PointCloud temel yap� s�n�f�.
*
* PointCloud s�n�f� Point s�n�f�n� liste olarak saklama, ka� tan oldu�unu g�sterme
*/
#include "Point.h"
#include <iostream>
#include <list>
#include <iterator>
#include <vector>
using namespace std;
#pragma once
//! PointCloud s�n�f�.
/*!
Olu�an noktalar� mant�ksal �ekilde bar�nd�ran s�n�f
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

	//! points parametresine public ula�ma
	list<Point> getPoints() const
	{
		return this->points;
	}

	//! points parametresi g�ncelleme
	void setPoints(list<Point> points)
	{
		this->points = points;
	}

	//! pointNumber parametresine public ula�ma
	int getPointNumber() const
	{
		return this->pointNumber;
	}

	//! pointNumber parametresi g�ncelleme
	void setPointNumber(int pn)
	{
		pointNumber = pn;
	}

	//! her iki nokta bulutunun sahip oldu�u noktalara sahip tek bir nokta bulutunu d�nd�r�r.
	PointCloud* appendPointCloud(PointCloud* pointCloud);

	//! bir nokta bulutunun	ba�ka bir nokta bulutuna kopyalanmas�n� sa�lar.
	PointCloud* getPointCloud();

	//! bir nokta bulutunun	ba�ka bir nokta bulutuna kopyalanmas�n� sa�lar.
	void addToPointCloud(Point point);
};




