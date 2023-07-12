#include "Transform.h"
#include "Point.h"
#include "PointCloud.h"
#include"DepthCamera.h"
#include"PassThroughFilter.h"
#include"PointCloudRecorder.h"
#include"RadiusOutlierFilter.h"
#include"Test.h"
#pragma once
using namespace std;
bool Test::TestRead()
{
	DepthCamera dp;
	dp.setFile("camera1.txt");
	PointCloud pc;
	pc = dp.capture();
	vector<Point> points = pc.getPoints();
	if (points[0].getX() != 150) return 0;
	if (points[0].getY() != 150) return 0;
	if (points[0].getZ() != -50) return 0;
	if (points[pc.getPointNumber() - 1].getX() != 400) return 0;
	if (points[pc.getPointNumber() - 1].getY() != 0) return 0;
	if (points[pc.getPointNumber() - 1].getZ() != 50) return 0;

	return 1;
}
bool Test::TestFilters()
{
	DepthCamera dp;
	dp.setFile("camera1.txt");
	PointCloud pc;
	pc = dp.capture();
	RadiusOutlierFilter rf;
	rf.setRadius(25);
	rf.filter(&pc);
	vector<Point> points = pc.getPoints();
	if (points[441].getX() != 150) return 0;
	if (points[441].getY() != 150) return 0;
	if (points[441].getZ() != -50) return 0;

	PassThroughFilter pF;
	pF.setlowerLimitX(0);
	pF.setlowerLimitY(0);
	pF.setlowerLimitZ(-45);
	pF.setupperLimitX(400);
	pF.setupperLimitY(400);
	pF.setupperLimitZ(45);
	pF.filter(&pc);
	if (pc.getPointNumber() != 798) return 0;

	return 1;
}
bool Test::TestTransform()
{
	DepthCamera dp;
	dp.setFile("camera1.txt");
	PointCloud pc;
	pc = dp.capture();
	RadiusOutlierFilter rf;
	rf.setRadius(25);
	rf.filter(&pc);
	vector<Point> points = pc.getPoints();
	PassThroughFilter pF;
	pF.setlowerLimitX(0);
	pF.setlowerLimitY(0);
	pF.setlowerLimitZ(-45);
	pF.setupperLimitX(400);
	pF.setupperLimitY(400);
	pF.setupperLimitZ(45);
	pF.filter(&pc);

	double tr[] = { 100, 500, 50 };
	double ang[] = { 0, 0, -90 };
	Transform Tf;
	Tf.setTrans(tr);
	Tf.setAngles(ang);

	pc = Tf.doTransform(pc);


	return 1;
}
bool Test::TestRecorder()
{
	DepthCamera dp1;
	dp1.setFile("camera1.txt");
	PointCloud pc1;
	pc1 = dp1.capture();

	RadiusOutlierFilter rf;
	rf.setRadius(25);
	rf.filter(&pc1);

	PassThroughFilter pF;
	pF.setlowerLimitX(0);
	pF.setlowerLimitY(0);
	pF.setlowerLimitZ(-45);
	pF.setupperLimitX(400);
	pF.setupperLimitY(400);
	pF.setupperLimitZ(45);
	pF.filter(&pc1);

	DepthCamera dp2;
	dp2.setFile("camera2.txt");
	PointCloud pc2;
	pc2 = dp2.capture();

	rf.filter(&pc2);

	pF.setlowerLimitX(0);
	pF.setlowerLimitY(0);
	pF.setlowerLimitZ(-45);
	pF.setupperLimitX(500);
	pF.setupperLimitY(500);
	pF.setupperLimitZ(45);
	pF.filter(&pc2);

	double tr1[] = { 100, 500, 50 };
	double ang1[] = { 0, 0, -90 };

	Transform Tf;

	Tf.setTrans(tr1);
	Tf.setAngles(ang1);
	pc1 = Tf.doTransform(pc1);

	double tr2[] = { 550, 150, 50 };
	double ang2[] = { 0, 0, 90 };

	Tf.setTrans(tr2);
	Tf.setAngles(ang2);
	pc2 = Tf.doTransform(pc2);

	pc1.appendPointCloud(&pc2);
	PointCloudRecorder Pcr;
	Pcr.setFile("output.txt");
	if (Pcr.save(pc1) != 1) return 0;

	return 1;
}
bool Test::TestAll()
{
	if (TestRead() != 1) return 0;
	if (TestFilters() != 1) return 0;
	if (TestTransform() != 1) return 0;
	if (TestRecorder() != 1) return 0;

	return 1;
}

