#pragma once
#include <glm/glm.hpp>
class bounds
{
public:
	bounds();
	bounds(glm::vec3 center, glm::vec3 size);
	~bounds();
	void setMinMax(glm::vec3 min, glm::vec3 max);
	bool intersect(bounds object);
	glm::vec3 getcentre();
	glm::vec3 getSize();
private:
	glm::vec3 centre;
	glm::vec3 size;
	glm::vec3 extents;
	glm::vec3 min;
	glm::vec3 max;

};

