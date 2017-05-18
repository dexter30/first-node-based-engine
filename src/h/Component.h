#ifndef COMPONENT_H
#define COMPONENT_H
#include <memory>
#include <string>
class GameObject;

class Component
{
public:
	
	std::shared_ptr<GameObject> getGO();
	std::shared_ptr<GameObject> parent;
	virtual void update();
	virtual void onAwake();
	virtual void onStart();
	virtual void onCollision(std::string _obj);
	
protected:
	
};

#endif