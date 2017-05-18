#pragma once
#include "../h/GameObject.h"
#include <vector>
#include "../h/deanX.h"
#include "../h/MeshData.h"
#include "../h/Player.h"
#include "../h/deanPhysics.h"
#include "../h/UIcontext.h"
#include "../h/evilBlock.h"

namespace WhoDean
{

	namespace Engine
	{
		class sceneSetup
		{

		public:
			static void setUptheScene(std::vector<std::shared_ptr<GameObject>>& scene, std::shared_ptr<btDiscreteDynamicsWorld> _physicsWorld);
			static void update();
		};

	}
}