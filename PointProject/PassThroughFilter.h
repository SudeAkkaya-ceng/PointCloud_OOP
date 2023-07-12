/**
* @file PassThroughFilter.h
* @Author Sude Nur Tokluca 152120191041
* @date Ocak, 2022
* @brief PassThroughFilter Point Cloud'a filtreleme i�lemi yapan s�n�f.
*
* PassThroughFilter minimum ve maximum filtre noktalar�n� tan�mlama, Point Cloud'a filtreleme i�lemi yapma.
*/
#include "PointCloud.h"
#include "PointCloudFilter.h"
#pragma once
//! PassThroughFilter s�n�f�.
/*!
 PassThroughFilter Point Cloud'a filtreleme i�lemi yapan s�n�f.
*/
class PassThroughFilter : public PointCloudFilter
{
private:
	double upperLimitX;
	double lowerLimitX;
	double upperLimitY;
	double lowerLimitY;
	double upperLimitZ;
	double lowerLimitZ;
public:
	//! PassThroughFilter constructor.
	PassThroughFilter()
	{
		this->upperLimitX = 0;
		this->lowerLimitX = 0;
		this->upperLimitY = 0;
		this->lowerLimitY = 0;
		this->upperLimitZ = 0;
		this->lowerLimitZ = 0;
	};
	//! PassThroughFilter destructor.
	~PassThroughFilter()
	{
		this->upperLimitX = 0;
		this->lowerLimitX = 0;
		this->upperLimitY = 0;
		this->lowerLimitY = 0;
		this->upperLimitZ = 0;
		this->lowerLimitZ = 0;
	};
	//! max X parametresini public olu�turma
	void setupperLimitX(double x)
	{
		this->upperLimitX = x;
	};
	//! max Y parametresini public olu�turma
	void setupperLimitY(double y)
	{
		this->upperLimitY = y;
	};
	//! max Z parametresini public olu�turma
	void setupperLimitZ(double z)
	{
		this->upperLimitZ = z;
	};
	//! min X parametresini public olu�turma
	void setlowerLimitX(double x)
	{
		this->lowerLimitX = x;
	};
	//! min Y parametresini public olu�turma
	void setlowerLimitY(double y)
	{
		this->lowerLimitY = y;
	};
	//! min Z parametresini public olu�turma
	void setlowerLimitZ(double z)
	{
		this->lowerLimitZ = z;
	};


	//! max X parametresine public ula�ma
	double getlowerLimitX()
	{
		return this->lowerLimitX;
	};
	//! max Y parametresine public ula�ma
	double getlowerLimitY()
	{
		return this->lowerLimitY;
	};
	//! max Z parametresine public ula�ma
	double getlowerLimitZ()
	{
		return this->lowerLimitZ;
	};
	//! min X parametresine public ula�ma
	double getupperLimitX()
	{
		return this->upperLimitX;
	};
	//! min Y parametresine public ula�ma
	double getupperLimitY()
	{
		return this->upperLimitY;
	};
	//! min Z parametresine public ula�ma
	double getupperLimitZ()
	{
		return this->upperLimitZ;
	};

	//! PointCloud nesnesinin sahip oldu�u her bir Point nesnesinin x,y,z de�erlerinin verilen s�n�rlar i�inde olup olmad���n� kontrol eder ve bu �ekilde filtreleme i�lemi uygular.
	void filter(PointCloud* PointCloud);

};

