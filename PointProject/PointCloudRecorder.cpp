#include "PointCloudRecorder.h"
#include <iostream>
#include <fstream>
#include<cstdlib>
#include<iomanip>
#pragma once
using namespace std;
/*!
\param const PointCloud an PointCloud class argument.
\ Dosyaya PointCloud nesnesi Point üyelerini yazdýran PointCloudRecorder sýnýfý fonksiyonu.
\return bool
*/
bool PointCloudRecorder::save(PointCloud const PointCloud)
{
	ofstream outFile;
	if (write == 0)
	{
		outFile.open(fileName);
		write = 1;
	}
	if (!outFile)
	{
		cout << "ERROR! File can not be opened.";
		return 0;
	}
	else
	{
		int p = int(PointCloud.getPointNumber());
		list<Point> pC;
		pC = PointCloud.getPoints();
		list<Point>::iterator it;
		for (it = pC.begin(); it != pC.end(); ++it)
		{
			outFile << showpoint;
			outFile << setprecision(10);
			outFile << it->getX() << " " << it->getY() << " " << it->getZ() << endl;
		}
	}
	return 1;
}

