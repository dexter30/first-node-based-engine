#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include "GL/glew.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "lodepng.h"
struct objPart{

	//These vectors hold the vertices, vertex normals and texture coordinates.
	std::vector<float> vertice;
	std::vector<float> vn;
	std::vector<float> vt;

	 //positions
	//normals
	//these vectors are important for face information. I use the elements for the face rendering.
	std::vector<int> elements;
	std::vector<int> verttext;
	std::vector<int> normalinds;

	
	std::string partName;//partname is just the filename
	std::string textureName;
	std::string matName;
	//We need to keep count of several parts which can help with binding to opengl. especilally since it needs to know how much space to reserve.
	int vertCount;
	int indicesCount;
	int UVcount;
	int vtCount;
	int offset;
	int ioffset;
	objPart *nextPart;
	objPart *parent;
	objPart *children;
	int kids;
	glm::vec3 position;
	float angles[3];
	//VAO & VBO
	GLuint partVAO;
	GLuint partVBO;
	GLuint partElem;
	GLuint partUV;
	GLuint tex;
	unsigned char* image;
	unsigned texWidth, texHeight;
	
};

class objfile
{
public:
	objfile(std::string _name);
	~objfile(void);
	objPart *getVertices(); //Returns an objpart object to be rendered in a VAO.
	std::string getTexture(std::string _name);
	static objPart reversedLinkedList(objPart* head);
	static GLuint loadCubemap(std::vector<const GLchar*> faces);
	std::string read(std::string fileName) const;
private:
	std::string name;//filename
	std::vector<glm::vec3> posStore;
	std::vector<glm::vec3> normStore;
	std::vector<glm::vec2> vtStore;
};

