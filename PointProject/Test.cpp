#include "Transform.h"
#include "Point.h"
#include "PointCloud.h"
#include"DepthCamera.h"
#include"PassThroughFilter.h"
#include"PointCloudRecorder.h"
#include"RadiusOutlierFilter.h"
#include"Test.h"
#include <list>
#pragma once
using namespace std;

bool Test::TestAll()
{
	DepthCamera dp1;
	dp1.setFile("camera1.txt");
	PointCloud pc1;
	pc1 = dp1.capture();
	list<Point> points = pc1.getPoints();
	// Test of DepthCamera,Point,PointCloud.;
	Point firstPoint = points.front();
	if (firstPoint.getX() != 150) return 0;
	if (firstPoint.getY() != 150) return 0;
	if (firstPoint.getZ() != -50) return 0;

	Point lastPoint = points.back();
	if (lastPoint.getX() != 400) return 0;
	if (lastPoint.getY() != 0) return 0;
	if (lastPoint.getZ() != 50) return 0;


	//RadiusOutlierFilter rf;
	//rf.setRadius(25);
	//rf.filter(&pc1);
	//// Test of RadiusOutlierFilter.
	//list<Point> pointsF = pc1.getPoints();
	//auto l_front = pointsF.begin();
	//std::advance(l_front, 441);
	//Point point441 = *l_front;
	//if (point441.getX() != 150) return 0;
	//if (point441.getY() != 150) return 0;
	//if (point441.getZ() != -50) return 0;

	//PassThroughFilter pF;
	//pF.setlowerLimitX(0);
	//pF.setlowerLimitY(0);
	//pF.setlowerLimitZ(-45);
	//pF.setupperLimitX(400);
	//pF.setupperLimitY(400);
	//pF.setupperLimitZ(45);
	//pF.filter(&pc1);

	//// Test of PassThroughFilter.
	//if (pc1.getPointNumber() != 798) return 0;

	////DepthCamera dp2;
	//dp2.setFile("camera2.txt");
	//PointCloud pc2;
	//pc2 = dp2.capture();

	//rf.filter(pc2);

	//pF.setlowerLimitX(0);
	//pF.setlowerLimitY(0);
	//pF.setlowerLimitZ(-45);
	//pF.setupperLimitX(500);
	//pF.setupperLimitY(500);
	//pF.setupperLimitZ(45);
	//pF.filter(pc2);

	//Eigen::Vector3d tr1=Eigen::Vector3d(100, 500, 50);
	//Eigen::Vector3d ang1 = Eigen::Vector3d(0, 0, -90);

	//Transform Tf;

	//Tf.setTrans(tr1);
	//Tf.setAngles(ang1);
	//pc1 = Tf.doTransform(pc1);

	//// Test of Transform.
	//list<Point> pointsT = pc1.getPoints();
	//Point firstPoint2 = pointsT.front();
	//if (firstPoint2.getX() == 150) return 0;
	//if (firstPoint2.getY() == 150) return 0;
	//if (firstPoint2.getZ() == -45) return 0;

	//Eigen::Vector3d tr2 = Eigen::Vector3d(550, 150, 50);
	//Eigen::Vector3d ang2 = Eigen::Vector3d(0, 0, 90);

	//Tf.setTrans(tr2);
	//Tf.setAngles(ang2);
	//pc2 = Tf.doTransform(pc2);

	//pc1.appendPointCloud(&pc2);
	//PointCloudRecorder Pcr;
	//Pcr.setFile("output.txt");

	//// Test of PointCloudRecorder.
	//if (Pcr.save(pc1) != 1) return 0;

	return 1;
}

