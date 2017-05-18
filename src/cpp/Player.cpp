#include "../h/Player.h"

namespace WhoDean
{

	namespace Engine
	{

		Player::Player()
		{
			
		}


		Player::~Player()
		{
		}


		void Player::onStart()
		{
			refTransform = parent->getComp<Transform>();
			physics = parent->getComp<deanPhysics>();
		}

		void Player::update()
		{
			glm::vec3 newPos = glm::vec3(0.0f,0.0f,0.0f);

			if (Input::_getKeys(97))
			{
				physics.lock()->applyForce(glm::vec3(-1000, 0, 0));
			}
			if (Input::_getKeys(100))
			{
				//newPos = refTransform.lock()->getPos();
				physics.lock()->applyForce(glm::vec3(1000, 0, 0));
				//newPos.x += 0.1f;
				//refTransform.lock()->setPos(newPos);
			}
			if (Input::_getKeys(119))
			{
				physics.lock()->applyForce(glm::vec3(0, 0, -1000));
				//newPos = refTransform.lock()->getPos();
				//newPos.z -= 0.1f;
				//refTransform.lock()->setPos(newPos);
			}
			if (Input::_getKeys(115))
			{
				physics.lock()->applyForce(glm::vec3(0, 0, 1000));
				//newPos = refTransform.lock()->getPos();
				//newPos.z += 0.1f;
				//refTransform.lock()->setPos(newPos);
			}
			if (Input::_getKeys(114))
			{
				physics.lock()->applyForce(glm::vec3(0, -1000, 0));
				//newPos = refTransform.lock()->getPos();
				//newPos.y -= 0.1f;
				//refTransform.lock()->setPos(newPos);
			}
			if (Input::_getKeys(102))
			{
				physics.lock()->applyForce(glm::vec3(0, 1000, 0));
				//newPos = refTransform.lock()->getPos();
				//newPos.y += 0.1f;
				//refTransform.lock()->setPos(newPos);
			}
			
		
		}
		void Player::inControl()
		{
			
		}
	}
}