#pragma once
#include <iostream>
#include <string>

#include <vector>

		class Input
		{
		public:
			static void inputInit();
			static void keyboard(unsigned char key, int x, int y);
			static void mouse(int button, int state, int x, int y);
			static void passiveMouse(int x, int y);
			static void keyboardUp(unsigned char key, int x, int y);

			static void _keyboard(int key, int x, int y);
			static void _keyboardUp(int key, int x, int y);
			static bool _getKeys(int key);
			static bool _getUpKeys(int key);

		private:
			static std::vector<int> keys;
			static std::vector<int> upKeys;
			static std::vector<int> downKeys;

		};

