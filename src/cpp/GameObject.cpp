#include "../h/GameObject.h"




void GameObject::onAwake()
{
	srand(time(NULL));
	this->addComp<Transform>();
	tag = "default";
	live = true;
}

void GameObject::update()
{
	for (int i = 0;i < CompList.size(); i++)
	{
		CompList.at(i)->update();
	}


}


void GameObject::onStart()
{
	for (int i = 0; i < CompList.size(); i++)
	{
		CompList[i]->onStart();
	}
	live = true;
}

void GameObject::onCollision(std::string _obj)
{
	for (int i = 0; i < CompList.size(); i++)
	{
		CompList[i]->onCollision(_obj);
	}
}

void GameObject::setTag(std::string _tag)
{
	tag = _tag;
}

void GameObject::setlife(bool _choice)
{
	live = _choice;
}
bool GameObject::getlife()
{
	return live;
}