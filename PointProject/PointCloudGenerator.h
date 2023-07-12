/**
* @file PointCloudGenerator.h
* @Author Sude Nur Tokluca 152120191041
* @date Ocak, 2022
* @brief PointCloudGenerator kameradan alýnan nokta verilerinine sahip nokta bulutuna filtreleme ve transform iþlemlerini uygular.
*
* PointCloudGenerator nokta bulutununu filtreleme iþlemi uygular ve istenen düzleme dönüþtürülmüþ hale getirir.
*/
#include"PointCloud.h"
#include"Transform.h"
#include"FilterPipe.h"
#pragma once
//! PointCloudGenerator sýnýfý.
/*!
 Kameradan alýnan nokta verilerinine sahip nokta bulutuna filtreleme ve transform iþlemlerini uygulama.
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
	//! transform parametresine public ulaþým
	Transform getTransform()
	{
		return this->transform;

	}
	//! filterpipe parametresine public ulaþým
	FilterPipe* getFilterPipe()
	{
		return this->filterpipe;

	}
	//! transform parametresini public oluþturma
	void setTransform(Transform tr)
	{
		this->transform = tr;

	}
	//! filterpipe parametresini public oluþturma
	void setFilterPipe(FilterPipe* fp)
	{
		this->filterpipe = fp;

	}
	//! capture() pure virtual fonksiyonu
	virtual	PointCloud capture() = 0;
	//! captureFor() pure virtual fonksiyonu
	virtual PointCloud captureFor() = 0;
};

