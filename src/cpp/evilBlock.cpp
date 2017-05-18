#include "../h/evilBlock.h"

namespace WhoDean
{

	namespace Engine
	{
		void evilBlock::onAwake()
		{
			
			this->addComp<Transform>();
			this->getComp<Transform>().lock()->setScale(glm::vec3(0.05f, 0.05f, 0.05f));
				this->addComp<MeshData>();
				this->getComp<MeshData>().lock()->LoadAsset("res/barrel_obj");
				this->addComp<deanPhysics>();
				this->getComp<Transform>().lock()->newPos(glm::vec3(rand() % 30, 100.0f, rand() % 30));
				this->setTag("barrel");
				
		}

		void evilBlock::onCollision(std::string _tag)
		{
			if (_tag == "player")
			{
				this->getComp<Transform>().lock()->newPos(glm::vec3(rand() % 30, 100.0f, rand() % 30));
				deanX::getWorld()->removeRigidBody(this->getComp<deanPhysics>().lock()->getRigid());
				live =false;
				//this->getComp<deanPhysics>().lock()->getRigid()->;
			}

		}
	}
}