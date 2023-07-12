#include "DepthCamera.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include<cstdlib>
#pragma once
using namespace std;
/*!
\ Dosyadan okuma yapýp PointCloud nesnesi oluþturan DepthCamera sýnýfý fonksiyonu.
\ return PointCloud an PointCloud class argument
*/
PointCloud DepthCamera::capture()
{
	PointCloud Point_Cloud;
	ifstream inFile;
	if (read == 0)
	{
		inFile.open(fileName);
		read = 1;
	}
	if (!inFile)
	{
		cout << "ERROR! File can not be opened.";
		exit(0);
	}
	else {
		while (!inFile.eof())
		{
			getline(inFile, line, '\n');
			int x, y, z;
			stringstream ss;
			ss.str(line);
			ss >> x >> y >> z;
			Point point(x, y, z);

			Point_Cloud.addToPointCloud(point);
		}

	}

	return Point_Cloud;
}
/*!
\ Dosyadan okuma yapýp PointCloud nesnesi oluþturan, bu PointCloud'a Filterpipe sýnýfýnýn sahip olduðu filtre iþlemlerini uygulayan ve transfor iþlemini gerçekleþtirip
\istene PointCloud'u hazýrlayan fonksiyon.
\ return PointCloud an PointCloud class argument
*/
PointCloud DepthCamera::captureFor() {

	PointCloud Point_Cloud;
	Point_Cloud = capture();
	getFilterPipe()->filterOut(Point_Cloud);
	Point_Cloud = getTransform().doTransform(Point_Cloud);

	return Point_Cloud;
}

