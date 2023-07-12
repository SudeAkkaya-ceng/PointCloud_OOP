#include "FilterPipe.h"


/*! filters dizisine gönderilen filtreyi ekler.
*/
void FilterPipe::addFilter(PointCloudFilter *filter)
{
	filters.push_back(filter);
}

/*! filters dizisindeki filtreleme iþlemlerini sýrasý ile gönderilen nokta bulutuna uygular.
*/
void FilterPipe::filterOut(PointCloud &pc)
{
	for (int i = 0; i < filters.size(); i++)
	{
		filters[i]->filter(&pc);
	}
}


