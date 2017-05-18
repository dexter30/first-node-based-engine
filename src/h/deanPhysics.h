#pragma once
#include "../h/Component.h"
#include "../h/deanX.h"
#include "../h/Transform.h"
#include "../h/GameObject.h"


namespace WhoDean{
	namespace Engine {

		class deanPhysics :
			public Component
		{
		public:
			deanPhysics();
			deanPhysics(std::string _shape);
			void onStart();
			void update();
			btRigidBody *getRigid();
			void setShape();
			void applyForce(glm::vec3 force);
		private:
			std::string shapeName;
			glm::vec3 box;
			std::string model;
			std::shared_ptr<btCollisionShape> phyShape;
			btScalar mass;
			std::shared_ptr<btDefaultMotionState> fallMotion;
			btVector3 fallInertia;
		//	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI;
			btRigidBody* fallRigidBody;
			btTransform position;
			std::weak_ptr<Transform> transformRef;
			
			//std::shared_ptr<btCollisionShape> collisionShape;
		};
	}
}