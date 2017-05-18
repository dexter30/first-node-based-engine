#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <vector>
#include <memory>
#include <string>
#include "Component.h"
#include "../h/Transform.h"
#include "DCamera.h"
#include "../h/Player.h"
#include "../h/deanPhysics.h"
#include <time.h>
#include <math.h>
class Component;

class GameObject: public std::enable_shared_from_this<GameObject>
{
public:
	virtual void onAwake();
	virtual void onStart();
	virtual void update();
	virtual void onCollision(std::string _obj);
	std::shared_ptr<GameObject> parent;
	template <class C>
	std::weak_ptr<C> addComp()
	{
		std::shared_ptr<C> TempComp(new C());
		//TempComp.reset(new C);
		CompList.push_back(TempComp);
		TempComp->parent = shared_from_this();
		return TempComp;
	}

	template <class C>
	std::weak_ptr<C> addComp(std::shared_ptr<C> ToAdd)
	{
		//TempComp.reset(new C);
		CompList.push_back(ToAdd);
		ToAdd->parent = shared_from_this();
		return ToAdd;
	}

	template <class C>
	std::weak_ptr<C> getComp()
	{
		for (int i = 0; i < CompList.size(); i++)
		{
			std::shared_ptr<C> c = std::dynamic_pointer_cast<C>(CompList.at(i));
			if(c != NULL) 
				return c;


		}
		return std::weak_ptr<C>();
	}
	std::string getTag()
	{
		return tag;
	}
	void setTag(std::string _name);

	void setlife(bool _choice);
	bool getlife();
		
protected:
	bool live;
	std::string tag;
	std::vector <std::shared_ptr<Component>> CompList;
	
	

};

#endif