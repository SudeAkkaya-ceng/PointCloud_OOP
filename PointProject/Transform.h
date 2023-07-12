/**
* @file Transform.h
* @Author Sude Akkaya sude.akkayaaa@gmail.com
* @date Ocak, 2022
* @brief Transform islemini yapan sinif.
*
*
*/

#include "Point.h"
#include "PointCloud.h"
#include <Eigen/Core>
#pragma once


//! Transform s�n�f�.
/*!
Matris olu�turan ve d�n��m� yapan s�n�f.
*/

class Transform
{
private:
	Eigen::Vector3d angles;
	Eigen::Vector3d trans;
	Eigen::Matrix4d transMatrix;
public:
	//! Transform constructor.
	Transform() {  };
	//! Transform destructor.
	~Transform(void) {  };

	//! angles parametresine public ula�ma
	Eigen::Vector3d getAngles()
	{
		return this->angles;
	}

	//! angles parametresini g�ncelleme
	void setAngles(Eigen::Vector3d ang)
	{
		this->angles = ang;
	}

	//! trans parametresine public ula�ma
	Eigen::Vector3d getTrans()
	{
		return this->trans;
	}

	//! trans parametresini g�ncelleme
	void setTrans(Eigen::Vector3d tr)
	{
		this->trans = tr;
	}

	//! transMtrix parametresini g�ncelleme
	void setTransMatrix(Eigen::Matrix4d trMat)
	{

		this->transMatrix = trMat;
	}

	//! angles parametresini g�nceller.
	void setRotation(double ang[]);

	//! Eigen angles parametresini g�nceller.
	void setRotation(Eigen::Vector3d ang);

	//! trans parametresini g�nceller.
	void setTranslation(double tr[]);

	//! Eigen trans parametresini g�nceller.
	void setTranslation(Eigen::Vector3d tr);

	//! matris olu�turarak gereken form�l� uygular.
	Point doTransform(Point p);

	//! d�n��en noktalardan yeni bir nokta bulutu olu�turur ve vekt�re atar.
	PointCloud doTransform(PointCloud p);
};




