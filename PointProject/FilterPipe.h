/**
* @file FilterPipe.h
* @Author Sude Nur Tokluca 152120191041
* @date Ocak, 2022
* @brief Nokta bulutuna yap�lacak filtreleri ekleyen ve s�ras�yla filtreleyen s�n�f.
*
* FilterPipe eklenen filtre i�lemlerini uygulama
*/
#include "PointCloud.h"
#include"PointCloudFilter.h"
#include <vector>
#pragma once
//! FilterPipe s�n�f�.
/*!
Nokta bulutuna yap�lacak filtreleri tutan s�n�f.
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

	//! filters dizisine g�nderilen filtreyi ekler.
	void addFilter(PointCloudFilter *filter);

	//! filters dizisindeki filtreleme i�lemlerini s�ras� ile g�nderilen nokta bulutuna uygular.
	void filterOut(PointCloud &pc);

};

