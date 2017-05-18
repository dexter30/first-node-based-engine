#include "../h/deanX.h"
namespace WhoDean
{
	namespace Engine {
		// std::shared_ptr<btDiscreteDynamicsWorld> getWorld;


	 /*btBroadphaseInterface* deanX::broadPhase;
	 btDefaultCollisionConfiguration* deanX::collisionConfig;
	 btCollisionDispatcher* deanX::dispatcher;
	 btSequentialImpulseConstraintSolver* deanX::solver;
	 std::shared_ptr<btDiscreteDynamicsWorld> deanX::dWorld;*/

		 btBroadphaseInterface* deanX::broadPhase;
		 btDefaultCollisionConfiguration* deanX::collisionConfig;
		 btCollisionDispatcher* deanX::dispatcher;
		 btSequentialImpulseConstraintSolver* deanX::solver;
		 std::shared_ptr<btDiscreteDynamicsWorld> deanX::dWorld;

		void deanX::physInit()
		{

			broadPhase = new btDbvtBroadphase();
			collisionConfig = new btDefaultCollisionConfiguration();
			dispatcher = new btCollisionDispatcher(collisionConfig);
			solver = new btSequentialImpulseConstraintSolver;
			dWorld.reset(new btDiscreteDynamicsWorld(dispatcher, broadPhase, solver, collisionConfig));

			dWorld->setGravity(btVector3(0, -10, 0));

		}

		std::shared_ptr<btDiscreteDynamicsWorld> deanX::getWorld()
		{
			return dWorld;
		}
	}

}