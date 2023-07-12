/**
* @file PointCloudRecorder.h
* @Author Sude Nur Tokluca 152120191041
* @date Aralýk, 2021
* @brief PointCloudRecorder dosyaya kaydeden sýnýf.
*
* PointCloudRecorder fileName tanýmlama, Point Cloud'un points dizisindeki Point nesnelerini dosyaya yazdýrma.
*/
#include "Point.h"
#include"PointCloud.h"
#include<iostream>
#pragma once
//! PointCloudRecorder sýnýfý.
/*!
 PointCloudRecorder Pointleri dosyaya yazdýran sýnýf.
*/
class PointCloudRecorder
{
private:

	string fileName;
	bool write;

public:
	//! PointCloudRecorder constructor.
	PointCloudRecorder()
	{
		write = 0;
	}

	//! PointCloudRecorder destructor.
	~PointCloudRecorder()
	{
		fileName = " ";
		write = 0;
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
	//! PointCloud nesnesinin points dizisindeki Point nesnelerinin x,y,z deðerlerini dosyaya kaydeden sýnýf.
	bool save(PointCloud const PointCloud);
};

