/**
* @file RadiusOutlierFilter.h
* @Author Sude Nur Tokluca 152120191041
* @date Ocak, 2022
* @brief RadiusOutlierFilter Point Cloud'a filtreleme iþlemi yapan sýnýf.
*
* RadiusOutlierFilter radius tanýmlama, Point Cloud'a filtreleme iþlemi yapma.
*/
#include "PointCloud.h"
#include"PointCloudFilter.h"
#pragma once
//! RadiusOutlierFilter sýnýfý.
/*!
 RadiusOutlierFilter Point Cloud'a filtreleme iþlemi yapan sýnýf.
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

	//! radius parametresini public oluþturma
	void setRadius(double radius)
	{
		this->radius = radius;
	};
	//! radius parametresine public ulaþma
	double getRadius()
	{
		return this->radius;
	};
	//! PointCloud nesnesinin sahip olduðu her bir Point nesnesinin dizinin diðer sahip olduðu nesnelere uzaklýðýný radius deðeri ile karþýlaþtýrýr ve bu þekilde filtreleme iþlemi uygular.
	void filter(PointCloud* PointCloud);

};

