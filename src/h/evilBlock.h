#pragma once
#include "..\h\GameObject.h"
#include "../h/MeshData.h"
#include "../h/deanPhysics.h"
#include "../h/Transform.h"
#include "../h/deanX.h"
#include <vector>
namespace WhoDean
{

	namespace Engine
	{
		class evilBlock :
			public GameObject
		{
		public:

			void onAwake();
			void onCollision(std::string _tag);
		private:
			std::vector<std::shared_ptr<GameObject>> barrels;
		};

	}
}