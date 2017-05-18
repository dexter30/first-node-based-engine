#include "../h/Input.h"
#include "../h/Platform.h"


#ifdef USE_GL
	#include <GL/freeglut.h>
#endif

		// Static variable declarations
		std::vector<int> Input::keys;
		std::vector<int> Input::downKeys;
		std::vector<int> Input::upKeys;

		void Input::inputInit()
		{
#ifdef USE_GL

			glutKeyboardFunc(keyboard);
			glutKeyboardUpFunc(keyboardUp);
			glutSpecialFunc(_keyboard);
			glutSpecialUpFunc(_keyboardUp);
			glutMouseFunc(mouse);
			glutMotionFunc(passiveMouse);
#endif
		}
		
		void Input::keyboard(unsigned char key, int x, int y)
		{
			_keyboard(key, x, y);
		}

		void Input::mouse(int button, int state, int x, int y)
		{
			

		}
		void Input::passiveMouse(int x, int y)
		{
			//std::cout << x<<y<< std::endl;
		}

		

		void Input::_keyboard(int key, int x, int y)
		{

						std::cout << key << std::endl;


			for (size_t i = 0; i < keys.size(); i++)
			{
				if (keys.at(i) == key)
				{
					return;
				}
			}

			keys.push_back(key);
			downKeys.push_back(key);
		}

		void Input::keyboardUp(unsigned char key, int x, int y)
		{
			_keyboardUp(key, x, y);
		}


		void Input::_keyboardUp(int key, int x, int y)
		{
			for (size_t i = 0; i < keys.size(); i++)
			{
				if (keys.at(i) == key)
				{
					keys.erase(keys.begin() + i);
					i--;
				}
			}

			upKeys.push_back(key);
		}

		bool Input::_getKeys(int key)
		{
			for (int i = 0; i < keys.size(); i++)
			{
				if (key == keys.at(i))	return true;
			}
			return false;
		}
		bool Input::_getUpKeys(int key)
		{
			for (int i = 0; i < upKeys.size(); i++)
			{
				if (key == upKeys.at(i))	return true;
			}
			return false;
		}
		

