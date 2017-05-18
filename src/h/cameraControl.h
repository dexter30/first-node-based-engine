#pragma once
#include "DCamera.h"


class cameraControl
{
public:

	static void setMainCam(std::weak_ptr<DCamera> _cam)
	{
		mainCam = _cam;
	};
	static std::weak_ptr<DCamera> getMainCam()
	{
		return mainCam;
	};
private:
	static std::weak_ptr<DCamera> mainCam;
};

