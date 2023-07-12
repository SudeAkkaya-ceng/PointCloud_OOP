/**
* @file DepthCamera.h
* @Author Sude Nur Tokluca 152120191041
* @date Aral�k, 2021
* @brief DepthCamera kamera dosyalar�ndan okuma yapan s�n�f.
*
* DepthCamera fileName tan�mlama ve FileName isimli dosyadan noktalar� okuma.
*/
#include "Point.h"
#include"PointCloud.h"
#include"PointCloudGenerator.h"
#pragma once
//! DepthCamera s�n�f�.
/*!
 Point olu�turma,fileName isimli dosyadan Point x,y,z de�erlerini okuma ve alma,
 Poinleri dizi halinde tutan Point Cloud olu�turma i�levlerini ger�ekle�tiren s�n�f.
*/
using namespace std;
class DepthCamera : public PointCloudGenerator
{
private:

	string fileName;
	bool read;

public:

	string line;
	//! DepthCamera constructor.
	DepthCamera()
	{
		line = " ";
		read = 0;
	}

	//! DepthCamera destructor.
	~DepthCamera()
	{
		line = " ";
		fileName = " ";
		read = 0;
	}

	//! fileName parametresine public ula�ma
	string getFile()
	{
		return fileName;
	}
	//! fileName parametresini public olu�turma
	void setFile(string fileName)
	{
		this->fileName = fileName;
	}

	//! Dosyadan Point x,y,z de�erlerini okur ve bu Pointler ile Point Cloud nesnesi olu�turur.
	PointCloud  capture();
	//! Dosyadan okunan noktalarla PointCloud olu�turur ve bu PointCloudu istenen �ekilde haz�r hale getirir.
	PointCloud  captureFor();
};

