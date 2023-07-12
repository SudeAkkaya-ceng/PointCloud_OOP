/**
* @file PassThroughFilter.h
* @Author Sude Nur Tokluca 152120191041
* @date Ocak, 2022
* @brief PassThroughFilter Point Cloud'a filtreleme iþlemi yapan sýnýf.
*
* PassThroughFilter minimum ve maximum filtre noktalarýný tanýmlama, Point Cloud'a filtreleme iþlemi yapma.
*/
#include "PointCloud.h"
#include "PointCloudFilter.h"
#pragma once
//! PassThroughFilter sýnýfý.
/*!
 PassThroughFilter Point Cloud'a filtreleme iþlemi yapan sýnýf.
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
	//! max X parametresini public oluþturma
	void setupperLimitX(double x)
	{
		this->upperLimitX = x;
	};
	//! max Y parametresini public oluþturma
	void setupperLimitY(double y)
	{
		this->upperLimitY = y;
	};
	//! max Z parametresini public oluþturma
	void setupperLimitZ(double z)
	{
		this->upperLimitZ = z;
	};
	//! min X parametresini public oluþturma
	void setlowerLimitX(double x)
	{
		this->lowerLimitX = x;
	};
	//! min Y parametresini public oluþturma
	void setlowerLimitY(double y)
	{
		this->lowerLimitY = y;
	};
	//! min Z parametresini public oluþturma
	void setlowerLimitZ(double z)
	{
		this->lowerLimitZ = z;
	};


	//! max X parametresine public ulaþma
	double getlowerLimitX()
	{
		return this->lowerLimitX;
	};
	//! max Y parametresine public ulaþma
	double getlowerLimitY()
	{
		return this->lowerLimitY;
	};
	//! max Z parametresine public ulaþma
	double getlowerLimitZ()
	{
		return this->lowerLimitZ;
	};
	//! min X parametresine public ulaþma
	double getupperLimitX()
	{
		return this->upperLimitX;
	};
	//! min Y parametresine public ulaþma
	double getupperLimitY()
	{
		return this->upperLimitY;
	};
	//! min Z parametresine public ulaþma
	double getupperLimitZ()
	{
		return this->upperLimitZ;
	};

	//! PointCloud nesnesinin sahip olduðu her bir Point nesnesinin x,y,z deðerlerinin verilen sýnýrlar içinde olup olmadýðýný kontrol eder ve bu þekilde filtreleme iþlemi uygular.
	void filter(PointCloud* PointCloud);

};

