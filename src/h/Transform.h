#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <glm\glm.hpp>
#include "Component.h"
#include <vector>
#include <iostream>
class Transform :
	public Component
{
public:
	Transform();
	~Transform();
	glm::vec3 getPos();
	glm::vec3 getScale();
	void setScale(glm::vec3 _newScale);
	void setPos(glm::vec3 _newPos);
	void newPos(glm::vec3 _newPos);
	bool CheckCollision(std::weak_ptr<Transform> _trans);
	float getRad();
	void setRad(float _rad);
	void update()
	{
		
	}
private:
	glm::vec3 localPos;		///Position of the component
	glm::vec3 localRot;		///rotation of the component
	glm::vec3 localScale;	///Local scale of component.
	float radius;
	

	
};

#endif