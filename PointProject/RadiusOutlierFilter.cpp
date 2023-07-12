#include <iostream>
#include"Point.h"
#include"RadiusOutlierFilter.h"
#include "PointCloud.h"


using namespace std;
/*!
\param PointCloud an PointCloud class argument.
\ PointCloud'a filtre iþlemi uygulayan RadiusOutlierFilter sýnýfý fonksiyonu.
*/
void RadiusOutlierFilter::filter(PointCloud* PointCloud)
{
	list<Point>::iterator it, it2;
	list<Point>::iterator jit;
	list<Point> pC, pCloud;
	pCloud = PointCloud->getPoints();
	int p = 0;
	double dst;

	for (it = pCloud.begin(); it != pCloud.end(); ++it)
	{
		bool flag = 0;
		for (jit = pCloud.begin(); jit != pCloud.end(); ++jit)
		{
			if (it != jit)
			{

				dst = (*it).distance(*jit);
				if (dst < radius)
				{
					flag = 1;
					p++;
					break;
				}
			}
		}
		if (flag == 1)
		{
			pC.push_back(*it);
		}
	}
	PointCloud->setPoints(pC);

	PointCloud->setPointNumber(p);
};

