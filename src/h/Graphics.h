
#pragma once
#include <glm\glm.hpp>
#include <GL/glew.h>
#include <GL/glut.h>
#include "../h/objfile.h"
#include "../h/GameObject.h"
#include "../h/DCamera.h"

#include <memory>

		class Graphics
		{
		public:

			 void init();
			 void draw(objPart* _modelNode, glm::mat4 MVP, std::shared_ptr<DCamera> cam);
			 void setCam(std::shared_ptr<DCamera> _newCam);
			 void loadShader(std::string path);
			 void setTarget(std::shared_ptr<GameObject> _par);
			 static GLuint loadObjShader(std::string _path);
			 void useShader();
		private:
			 GLuint vertS;
			 GLuint fragS;
			 GLuint programID;
			 
			 //std::shared_ptr<DCamera> miike;

		};

