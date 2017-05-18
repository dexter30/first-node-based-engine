#ifndef DISPLAY_H
#define DISPLAY_H
#include <glm\glm.hpp>
class Display
{
public:
	
	static void DisplayInit( int argc, char* argv[]);
	static int m_width;
	static int m_height;
private:
	

	static void _display(); //function to be called to current window, To be renamed
	static void reshape(int width, int height);


};

#endif