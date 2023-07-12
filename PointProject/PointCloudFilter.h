/**
* @file PointCloudFilter.h
* @Author Sude Nur Tokluca 152120191041
* @date Ocak, 2022
* @brief PointCloudFilter abstract s�n�f�.
*
* PointCloudFilter filtrelerin abstract s�n�f�.
*/
#pragma once
#include "Point.h"
#include"PointCloud.h"
#include<iostream>
//! PointCloudFilter s�n�f�.
/*!
 PointCloudFilter abstract s�n�f�.
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

