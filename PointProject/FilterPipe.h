/**
* @file FilterPipe.h
* @Author Sude Nur Tokluca 152120191041
* @date Ocak, 2022
* @brief Nokta bulutuna yapýlacak filtreleri ekleyen ve sýrasýyla filtreleyen sýnýf.
*
* FilterPipe eklenen filtre iþlemlerini uygulama
*/
#include "PointCloud.h"
#include"PointCloudFilter.h"
#include <vector>
#pragma once
//! FilterPipe sýnýfý.
/*!
Nokta bulutuna yapýlacak filtreleri tutan sýnýf.
*/
class FilterPipe
{
private:

	vector<PointCloudFilter*> filters;


public:
	//! FilterPipe constructor.
	FilterPipe() {};
	//! FilterPipe destructor.
	~FilterPipe() {};

	//! filters dizisine gönderilen filtreyi ekler.
	void addFilter(PointCloudFilter *filter);

	//! filters dizisindeki filtreleme iþlemlerini sýrasý ile gönderilen nokta bulutuna uygular.
	void filterOut(PointCloud &pc);

};

