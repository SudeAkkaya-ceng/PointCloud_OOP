/**
* @file PointCloudFilter.h
* @Author Sude Nur Tokluca 152120191041
* @date Ocak, 2022
* @brief PointCloudFilter abstract sýnýfý.
*
* PointCloudFilter filtrelerin abstract sýnýfý.
*/
#pragma once
#include "Point.h"
#include"PointCloud.h"
#include<iostream>
//! PointCloudFilter sýnýfý.
/*!
 PointCloudFilter abstract sýnýfý.
*/
class PointCloudFilter
{
public:

	//! PointCloudFilter constructor.
	PointCloudFilter() {}

	//! PointCloudFilter destructor.
	~PointCloudFilter() {}

	//! filter() pure virtual fonksiyonu.
	virtual void filter(PointCloud *PointCloud) = 0;

};

