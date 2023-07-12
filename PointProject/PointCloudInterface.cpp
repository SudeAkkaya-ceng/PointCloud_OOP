#include "PointCloudInterface.h"

/*!
\param newGenerator an PointCloudRecorder class argument.
\return void
*/
void PointCloudInterface::addGenerator(PointCloudGenerator* newGenerator)
{

	generators.push_back(newGenerator);
}

/*!
\param recorder an PointCloudRecorder class argument.
\return void
*/
void PointCloudInterface::setRecorder(PointCloudRecorder* recorder)
{
	this->recorder = recorder;
}

/*!
\param nothing argument.
\return bool
*/
bool PointCloudInterface::generate()
{
	for (int i = 0; i < generators.size(); i++)
	{
		pointCloud.appendPointCloud(&(generators[i]->captureFor()));
	}
	patch = pointCloud;
	return true;
}

/*!
\param nothing argument.
\return bool
*/
bool PointCloudInterface::record()
{
	recorder->setFile("output.txt");
	recorder->save(patch);
	return true;
}


