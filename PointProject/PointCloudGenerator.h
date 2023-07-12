/**
* @file PointCloudGenerator.h
* @Author Sude Nur Tokluca 152120191041
* @date Ocak, 2022
* @brief PointCloudGenerator kameradan al�nan nokta verilerinine sahip nokta bulutuna filtreleme ve transform i�lemlerini uygular.
*
* PointCloudGenerator nokta bulutununu filtreleme i�lemi uygular ve istenen d�zleme d�n��t�r�lm�� hale getirir.
*/
#include"PointCloud.h"
#include"Transform.h"
#include"FilterPipe.h"
#pragma once
//! PointCloudGenerator s�n�f�.
/*!
 Kameradan al�nan nokta verilerinine sahip nokta bulutuna filtreleme ve transform i�lemlerini uygulama.
*/
using namespace std;
class PointCloudGenerator {
private:

	Transform transform;
	FilterPipe* filterpipe;

public:
	//! PointCloudGenerator constructor.
	PointCloudGenerator()
	{}
	//! PointCloudGenerator destructor.
	~PointCloudGenerator()
	{}
	//! transform parametresine public ula��m
	Transform getTransform()
	{
		return this->transform;

	}
	//! filterpipe parametresine public ula��m
	FilterPipe* getFilterPipe()
	{
		return this->filterpipe;

	}
	//! transform parametresini public olu�turma
	void setTransform(Transform tr)
	{
		this->transform = tr;

	}
	//! filterpipe parametresini public olu�turma
	void setFilterPipe(FilterPipe* fp)
	{
		this->filterpipe = fp;

	}
	//! capture() pure virtual fonksiyonu
	virtual	PointCloud capture() = 0;
	//! captureFor() pure virtual fonksiyonu
	virtual PointCloud captureFor() = 0;
};

