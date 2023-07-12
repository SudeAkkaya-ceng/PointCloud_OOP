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

//! PointCloud sýnýfý.
class PointCloudInterface {
private:
	PointCloud pointCloud;
	PointCloud patch;
	vector<PointCloudGenerator*> generators;
	PointCloudRecorder *recorder;
public:

	//! vektöre noktalarýn eklenmesini saðlar.
	void addGenerator(PointCloudGenerator *newGenerator);

	//! recorder parametresi güncelleme
	void setRecorder(PointCloudRecorder *recorder);

	//! Nokta bulutunu filtrelerden geçirip tutulmasýný saðlar.
	bool generate();

	//! Noktalarý dosyaya yazdýrýlmasýný saðlar.
	bool record();

};

