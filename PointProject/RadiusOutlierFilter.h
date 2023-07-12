/**
* @file RadiusOutlierFilter.h
* @Author Sude Nur Tokluca 152120191041
* @date Ocak, 2022
* @brief RadiusOutlierFilter Point Cloud'a filtreleme i�lemi yapan s�n�f.
*
* RadiusOutlierFilter radius tan�mlama, Point Cloud'a filtreleme i�lemi yapma.
*/
#include "PointCloud.h"
#include"PointCloudFilter.h"
#pragma once
//! RadiusOutlierFilter s�n�f�.
/*!
 RadiusOutlierFilter Point Cloud'a filtreleme i�lemi yapan s�n�f.
*/
class RadiusOutlierFilter :public PointCloudFilter
{
private:
	double radius;

public:
	//! RadiusOutlierFilter constructor.
	RadiusOutlierFilter()
	{
		radius = 0;
	};
	//! RadiusOutlierFilter destructor.
	~RadiusOutlierFilter()
	{
		radius = 0;
	};

	//! radius parametresini public olu�turma
	void setRadius(double radius)
	{
		this->radius = radius;
	};
	//! radius parametresine public ula�ma
	double getRadius()
	{
		return this->radius;
	};
	//! PointCloud nesnesinin sahip oldu�u her bir Point nesnesinin dizinin di�er sahip oldu�u nesnelere uzakl���n� radius de�eri ile kar��la�t�r�r ve bu �ekilde filtreleme i�lemi uygular.
	void filter(PointCloud* PointCloud);

};

