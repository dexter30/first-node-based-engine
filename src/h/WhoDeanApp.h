#ifndef ENGINEAPP_H
#define ENGINEAPP_H
#include <memory>
#include "../h/MeshData.h"
#include "../h/GameObject.h"
#include "../h/DCamera.h"
#include "../h/WhoDeanUI.h"
#include "../h/UIcontext.h"
#include "../h/skyBox.h"
namespace WhoDean
{

namespace Engine
{
	
	class WhoDeanApp;
	struct Context
	{
		bool running;
	};

	class WhoDeanApp
	{
	public:
		static void whoDeanInit(int argc, char* argv[]);
		static void idle();
		//static void destroy();
		static void run();
		//static void quit();
	private:
		static std::shared_ptr<Context> context;
		static std::weak_ptr<Player> controlled;
		MeshData meshed;
		static UIcontext name;
		static deanX phyWorld;
		static skyBox sky;
		
		//static std::shared_ptr<DCamera> mainCam;
		
	};

	
}//end engine NS
}//end WhoDean NS
#endif
