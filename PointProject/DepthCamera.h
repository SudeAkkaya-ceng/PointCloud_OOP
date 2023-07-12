/**
* @file DepthCamera.h
* @Author Sude Nur Tokluca 152120191041
* @date Aralýk, 2021
* @brief DepthCamera kamera dosyalarýndan okuma yapan sýnýf.
*
* DepthCamera fileName tanýmlama ve FileName isimli dosyadan noktalarý okuma.
*/
#include "Point.h"
#include"PointCloud.h"
#include"PointCloudGenerator.h"
#pragma once
//! DepthCamera sýnýfý.
/*!
 Point oluþturma,fileName isimli dosyadan Point x,y,z deðerlerini okuma ve alma,
 Poinleri dizi halinde tutan Point Cloud oluþturma iþlevlerini gerçekleþtiren sýnýf.
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

	//! fileName parametresine public ulaþma
	string getFile()
	{
		return fileName;
	}
	//! fileName parametresini public oluþturma
	void setFile(string fileName)
	{
		this->fileName = fileName;
	}

	//! Dosyadan Point x,y,z deðerlerini okur ve bu Pointler ile Point Cloud nesnesi oluþturur.
	PointCloud  capture();
	//! Dosyadan okunan noktalarla PointCloud oluþturur ve bu PointCloudu istenen þekilde hazýr hale getirir.
	PointCloud  captureFor();
};

