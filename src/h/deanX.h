#pragma once
#include <btBulletDynamicsCommon.h>
#include "..\h\Component.h"

//This is the top level physics class.
//As a static class it holds all the configuration variables for the physics objects.
namespace WhoDean
{
	namespace Engine {
		class deanX
		{
		public:
			void physInit();
			static std::shared_ptr<btDiscreteDynamicsWorld> getWorld();
			
			
		private:
			static btBroadphaseInterface* broadPhase;
			static btDefaultCollisionConfiguration* collisionConfig;
			static btCollisionDispatcher* dispatcher;
			static btSequentialImpulseConstraintSolver* solver;
			static std::shared_ptr<btDiscreteDynamicsWorld> dWorld;

		};

	}
}