#include "../h/bounds.h"


bounds::bounds()
{
}

bounds::bounds(glm::vec3 _center, glm::vec3 _size)
{
	this->centre	= _center;
	this->size		= _size;
	this->extents	= _size / 2.0f;
	this->min		= centre - extents;
	this->max		= centre + extents;
}


bounds::~bounds()
{
}

void bounds::setMinMax(glm::vec3 _min, glm::vec3 _max)
{
	centre		= (_min + _max) / 2.0f;
	extents		= max - centre;
	size		= extents * 2.0f;
	this->min	= centre - extents;
	this->max = centre + extents;
}

glm::vec3 bounds::getcentre()
{
	return centre;
}


glm::vec3 bounds::getSize()
{
	return this->size;
}