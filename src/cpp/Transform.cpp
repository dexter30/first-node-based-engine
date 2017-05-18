#include "../h/Transform.h"



Transform::Transform()
{
//	glm::vec3 center = parent->getComp<MeshData>().lock->getCenter();
	
	localPos = glm::vec3(0.0f, 0.0f, 0.0f) ;
	localScale = glm::vec3(1.0f, 1.0f, 1.0f);
	radius = 1.0f;
}


Transform::~Transform()
{
}

glm::vec3 Transform::getPos()
{
	return localPos;
}
glm::vec3 Transform::getScale()
{
	return localScale;
}

void Transform::setPos(glm::vec3 _newPos)
{
	localPos = localPos + _newPos;
}

void Transform::newPos(glm::vec3 _newpos)
{
	localPos = _newpos;
}
void Transform::setScale(glm::vec3 _newPos)
{
	localScale = _newPos;
}

bool Transform::CheckCollision(std::weak_ptr<Transform> _trans)
{
	glm::vec3 distance = _trans.lock()->getPos() - localPos;
	float mag = glm::dot(distance, distance);
	float minDist = radius + _trans.lock()->getRad();
	if (mag <= (minDist * minDist))
	{
		return true;
	}
	return false;
}

float Transform::getRad()
{
	return radius;
}
void Transform::setRad(float _rad)
{
	radius = _rad;
}