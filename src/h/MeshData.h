#pragma once
#include "Component.h"
#include <glm\glm.hpp>
#include <GL/glew.h>
#include <GL/glut.h>
#include <string>
#include "../h/objfile.h"
#include "../h/bounds.h"

#include "../h/Transform.h"
#include "../h/Graphics.h"
#include "../h/cameraControl.h"
class bounds;
class MeshData :
	public Component
{
	
public:
	MeshData();

	//MeshData(std::string M) : message(M) {}

	~MeshData();
	void update();
	void recalculateBounds();
	glm::vec3 getBounds();
	virtual void onStart();
	void LoadAsset(char* _name);
	glm::vec3 MeshData::getCenter();
private:
	objPart* modelNode;
	objPart* mode;
	GLuint VAOid;
	GLuint VBOid;
	GLuint colourVboId;
	GLuint normalvbo;
	GLuint ColourID;
	const GLchar* vertexShader;
	const GLchar* fragment;
	bounds meshBounds;
	Graphics renderer;
	bool rendering;
	glm::vec3 transform;
	std::weak_ptr<Transform> transformRef;
	//std::string message;
};

