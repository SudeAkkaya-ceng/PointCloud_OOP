/**
* @file PointCloudRecorder.h
* @Author Sude Nur Tokluca 152120191041
* @date Aral�k, 2021
* @brief PointCloudRecorder dosyaya kaydeden s�n�f.
*
* PointCloudRecorder fileName tan�mlama, Point Cloud'un points dizisindeki Point nesnelerini dosyaya yazd�rma.
*/
#include "Point.h"
#include"PointCloud.h"
#include<iostream>
#pragma once
//! PointCloudRecorder s�n�f�.
/*!
 PointCloudRecorder Pointleri dosyaya yazd�ran s�n�f.
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
	//! PointCloud nesnesinin points dizisindeki Point nesnelerinin x,y,z de�erlerini dosyaya kaydeden s�n�f.
	bool save(PointCloud const PointCloud);
};

