#include "../h/Component.h"



void Component::onAwake()
{
	
}

void Component::update()
{

}

std::shared_ptr<GameObject> Component::getGO()
{
	return parent;
}

void Component::onStart()
{

}
void Component::onCollision(std::string _path)
{

}
