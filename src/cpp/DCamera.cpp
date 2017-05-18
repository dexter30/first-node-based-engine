#include "../h/DCamera.h"




		
		void DCamera::update()
		{
			if (parent != NULL)
			{
				//target = parent->getComp<Transform>().lock()->getPos();
				position = parent->getComp<Transform>().lock()->getPos() + offset;
				 
			}
			if (Input::_getKeys(105))
			{
				position += speed * target;
				//position -= speed * glm::vec3(1.0f, 0.0f, 0.0f);
			
			}
			if (Input::_getKeys(107))
			{
				position -= speed * target;
				//position += speed * glm::vec3(1.0f, 0.0f, 0.0f);
				
			}
			if (Input::_getKeys(106))
			{
				position -= glm::normalize(glm::cross(target, glm::vec3(0.0f, 1.0f, 0.0f))) * speed;
				

			}
			if (Input::_getKeys(108))
			{
				position += glm::normalize(glm::cross(target, glm::vec3(0.0f, 1.0f, 0.0f))) * speed;
				

			}
		}


		void DCamera::onStart()
		{
			offset = glm::vec3(0.0f, 5.0f, 5.0f);
		}