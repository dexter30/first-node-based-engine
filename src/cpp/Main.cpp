#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <dinput.h>
#include "../h/WhoDeanApp.h"

namespace WhoDean
{

	namespace Engine
	{

		int safe_main(int argc, char* argv[])
		{
			WhoDeanApp::whoDeanInit(argc, argv);
			WhoDeanApp::run();
			
			std::cout << "boot";
			std::cin.get();
			return 0;
		}

	}
}

int main(int argc, char* argv[])
{
	WhoDean::Engine::safe_main(argc, argv);

	std::cout << "boot";
	std::cin.get();
	
	return 0;
}