#pragma once
#include "..\h\Component.h"
#include "..\h\bounds.h"
class collider :
	public Component
{
public:
	collider();
	~collider();
private:
	bounds object;
};

