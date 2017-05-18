#include "../h/Display.h"
#include <GL/glew.h>
#include "../h/Platform.h"
#include "../h/WhoDeanApp.h"


#ifdef USE_GL
	#include <GL/freeglut.h>
#endif

#include <windows.h>

int Display::m_width;
int Display::m_height;


void Display::DisplayInit( int argc, char* argv[])
{
	m_width = 800;

	m_height = 600;

#ifdef USE_GL
	glutInit(&argc, argv);
	glutInitWindowSize(m_width, m_height);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Whodeani");
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	// Continuously called when events are not being received
	glutIdleFunc(WhoDean::Engine::WhoDeanApp::idle);

	glutDisplayFunc(_display);
	glutReshapeFunc(reshape);
#endif
	
	glewInit();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);


}

void Display::_display(void)
{
	glClearColor(229.0f / 255.0f, 90.0f / 255.0f, 239.0f / 255.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, m_width,m_height);

	//glutSwapBuffers();
}


void Display::reshape(int _width, int _height)
{
	m_width = _width;
	
	m_height = _height;
	WhoDean::Engine::WhoDeanApp::idle();
}

