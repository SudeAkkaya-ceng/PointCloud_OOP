#include "FilterPipe.h"


/*! filters dizisine g�nderilen filtreyi ekler.
*/
void FilterPipe::addFilter(PointCloudFilter *filter)
{
	filters.push_back(filter);
}

/*! filters dizisindeki filtreleme i�lemlerini s�ras� ile g�nderilen nokta bulutuna uygular.
*/
void FilterPipe::filterOut(PointCloud &pc)
{
	for (int i = 0; i < filters.size(); i++)
	{
		filters[i]->filter(&pc);
	}
}


