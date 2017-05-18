#pragma once
#include <glm\glm.hpp>
#include "Component.h"
#include "Input.h"
#include "GameObject.h"
		class DCamera :
			public Component
		{
		public:
			void onStart();
			glm::vec3 getPosition() { return position; }
			glm::vec3 getTarget() { return target; }
			void setPosition(glm::vec3 _pos) { position = _pos; speed = 0.5f; }
			void setTarget(glm::vec3 _tar) { target = _tar; }
			void update();
		private:
			glm::vec3 position;
			glm::vec3 up;
			glm::vec3 target;
			glm::vec3 offset;
			float speed;
		};

