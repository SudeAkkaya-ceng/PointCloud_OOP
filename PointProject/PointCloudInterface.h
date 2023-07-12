/**
* @file Transform.h
* @Author Sude Akkaya sude.akkayaaa@gmail.com
* @date Ocak, 2022
* @brief Arayuz sinifi.
*
*
*/
#pragma once
#include <iostream>
#include <vector>
#include "PointCloud.h"
#include "PointCloudGenerator.h"
#include "PointCloudRecorder.h"

using namespace std;

//! PointCloud s�n�f�.
class PointCloudInterface {
private:
	PointCloud pointCloud;
	PointCloud patch;
	vector<PointCloudGenerator*> generators;
	PointCloudRecorder *recorder;
public:

	//! vekt�re noktalar�n eklenmesini sa�lar.
	void addGenerator(PointCloudGenerator *newGenerator);

	//! recorder parametresi g�ncelleme
	void setRecorder(PointCloudRecorder *recorder);

	//! Nokta bulutunu filtrelerden ge�irip tutulmas�n� sa�lar.
	bool generate();

	//! Noktalar� dosyaya yazd�r�lmas�n� sa�lar.
	bool record();

};

