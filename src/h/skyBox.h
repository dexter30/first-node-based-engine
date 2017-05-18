#pragma once
#include <vector>
#include "../h/objfile.h"
#include "..\h\Graphics.h"
#include "../h/DCamera.h"
class skyBox
{
public:
	skyBox();
	~skyBox();
	void genSkybox(DCamera _cam);
	void render();
private:
	GLuint shader;
	GLuint cubeText;
	GLuint skyVAO;
	GLuint skyVBO;
	DCamera camera;
};

