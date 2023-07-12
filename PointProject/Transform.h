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


//! Transform sýnýfý.
/*!
Matris oluþturan ve dönþümü yapan sýnýf.
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

	//! angles parametresine public ulaþma
	Eigen::Vector3d getAngles()
	{
		return this->angles;
	}

	//! angles parametresini güncelleme
	void setAngles(Eigen::Vector3d ang)
	{
		this->angles = ang;
	}

	//! trans parametresine public ulaþma
	Eigen::Vector3d getTrans()
	{
		return this->trans;
	}

	//! trans parametresini güncelleme
	void setTrans(Eigen::Vector3d tr)
	{
		this->trans = tr;
	}

	//! transMtrix parametresini güncelleme
	void setTransMatrix(Eigen::Matrix4d trMat)
	{

		this->transMatrix = trMat;
	}

	//! angles parametresini günceller.
	void setRotation(double ang[]);

	//! Eigen angles parametresini günceller.
	void setRotation(Eigen::Vector3d ang);

	//! trans parametresini günceller.
	void setTranslation(double tr[]);

	//! Eigen trans parametresini günceller.
	void setTranslation(Eigen::Vector3d tr);

	//! matris oluþturarak gereken formülü uygular.
	Point doTransform(Point p);

	//! dönüþen noktalardan yeni bir nokta bulutu oluþturur ve vektöre atar.
	PointCloud doTransform(PointCloud p);
};




