#ifndef PLAYER_H
#define PLAYER_H 
#include "..\h\Component.h"
#include "..\h\Input.h"
#include "..\h\Transform.h"
#include "..\h\GameObject.h"
#include "..\h\deanPhysics.h"
#include "..\h\deanX.h"

namespace WhoDean
{

	namespace Engine
	{
		class deanPhysics;

		class Player :
			public Component
		{
		public:
			Player();
			~Player();
			void onStart();
			void update();
			void inControl();
		private:
			std::weak_ptr<deanPhysics> physics;
			std::weak_ptr<Transform> refTransform;

		};

	}
}

#endif