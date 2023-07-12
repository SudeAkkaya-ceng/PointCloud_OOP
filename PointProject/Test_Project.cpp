#include "Transform.h"
#include "Point.h"
#include "PointCloud.h"  
#include"DepthCamera.h"
#include"PointCloudRecorder.h"
#include"Test_Project.h"
#include "FilterPipe.h"
#include"PointCloudFilter.h"
#include"PassThroughFilter.h"
#include"RadiusOutlierFilter.h"
#include"PointCloudInterface.h"
#include"PointCloudGenerator.h"
#include <list>
#pragma once
using namespace std;

//! Projeyi test eden fonksiyon.
bool Test::Test_Project()
{
	PointCloudRecorder Point_Cloud_Recorder;

	DepthCamera dp1;
	dp1.setFile("camera1.txt");

	RadiusOutlierFilter rf;
	rf.setRadius(25);

	PassThroughFilter pF1;
	pF1.setlowerLimitX(0);
	pF1.setlowerLimitY(0);
	pF1.setlowerLimitZ(-45);
	pF1.setupperLimitX(400);
	pF1.setupperLimitY(400);
	pF1.setupperLimitZ(45);

	FilterPipe Fp1;
	Fp1.addFilter(&rf);
	Fp1.addFilter(&pF1);

	Transform Tf1;
	Eigen::Vector3d tr1 = Eigen::Vector3d(100, 500, 50);
	Eigen::Vector3d ang1 = Eigen::Vector3d(0, 0, -90);
	Tf1.setTrans(tr1);
	Tf1.setAngles(ang1);

	PointCloudGenerator *Point_Cloud_Generator1 = &dp1;
	Point_Cloud_Generator1->setFilterPipe(&Fp1);
	Point_Cloud_Generator1->setTransform(Tf1);


	DepthCamera dp2;
	dp2.setFile("camera2.txt");

	PassThroughFilter pF2;
	pF2.setlowerLimitX(0);
	pF2.setlowerLimitY(0);
	pF2.setlowerLimitZ(-45);
	pF2.setupperLimitX(500);
	pF2.setupperLimitY(500);
	pF2.setupperLimitZ(45);

	FilterPipe Fp2;
	Fp2.addFilter(&rf);
	Fp2.addFilter(&pF2);

	Transform Tf2;
	Eigen::Vector3d tr2 = Eigen::Vector3d(550, 150, 50);
	Eigen::Vector3d ang2 = Eigen::Vector3d(0, 0, 90);
	Tf2.setTrans(tr2);
	Tf2.setAngles(ang2);


	PointCloudGenerator *Point_Cloud_Generator2 = &dp2;
	Point_Cloud_Generator2->setFilterPipe(&Fp2);
	Point_Cloud_Generator2->setTransform(Tf2);

	PointCloudInterface Point_Cloud_Interface;
	Point_Cloud_Interface.setRecorder(&Point_Cloud_Recorder);
	Point_Cloud_Interface.addGenerator(Point_Cloud_Generator1);
	Point_Cloud_Interface.addGenerator(Point_Cloud_Generator2);
	Point_Cloud_Interface.generate();
	Point_Cloud_Interface.record();

	return 1;
}

