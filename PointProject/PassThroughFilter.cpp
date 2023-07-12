#include <iostream>
#include"Point.h"
#include"PassThroughFilter.h"
#include "PointCloud.h"


using namespace std;
/*!
\param PointCloud an PointCloud class argument.
\ PointCloud'a filtre iþlemi uygulayan PassThroughFilter sýnýfý fonksiyonu.
*/
void PassThroughFilter::filter(PointCloud* PointCloud)
{
	int p = 0;
	bool flag;
	list<Point>::iterator it;
	list<Point> pC, pCloud;
	pCloud = PointCloud->getPoints();
	for (it = pCloud.begin(); it != pCloud.end(); ++it)
	{
		flag = 0;
		if (it->getX() < lowerLimitX || it->getX() > upperLimitX)
		{
			flag = 1;
		}
		else if (it->getY() < lowerLimitY || it->getY() > upperLimitY)
		{
			flag = 1;
		}
		else if (it->getZ() < lowerLimitZ || it->getZ() > upperLimitZ)
		{
			flag = 1;
		}

		if (flag == 0)
		{
			pC.push_back(*it);
			p++;

		}
	}
	PointCloud->setPoints(pC);
	PointCloud->setPointNumber(p);
}

