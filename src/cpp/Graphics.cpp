#include "../h/Graphics.h"

	/*
		GLuint Graphics::vertS;
		GLuint Graphics::fragS;
		GLuint Graphics::programID;
		std::shared_ptr<DCamera> Graphics::miike;
		*/
		void Graphics::init()
		{


			std::string shaderString;

			std::ifstream stream("res/main.vert", std::ios::in);

			if (stream.is_open())
			{
				std::string Line = "";

				while (getline(stream, Line)) { shaderString += "\n" + Line; }

				stream.close();
			}

			const GLchar* vertexShader = shaderString.c_str();
			/*{
				"#version 400\n"\

				"layout(location=0) in vec3 in_Position;\n"\
				"layout(location=1) in vec3 in_norm;\n"\
				"layout(location=2) in vec2 in_UV;\n"\
				"out vec4 ex_Color;\n"\
				"out vec3 ex_Norm;\n"\
				"out vec2 ex_UV;\n"\
				"uniform mat4 projMat; \n"\
				"uniform mat4 in_Model; \n"\
				"uniform mat4 in_View; \n"\
				"uniform vec4 WSlight;\n"\
				"void main(void)\n"\
				"{\n"\
				" gl_Position =  projMat *  in_View * in_Model* vec4(in_Position,1.0)  ;\n"\
				" ex_Color = vec4(in_norm.x, in_norm.y, in_norm.z, 1.0);\n"\
				" ex_Norm = in_norm;\n"\
				" ex_UV = in_UV;\n"\
				"}\n"
			};*/

			//stop trying to turn a vector into a float you dumbass
			vertS = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertS, 1, &vertexShader, NULL);
			glCompileShader(vertS);
			int compiled = 0;
			glGetShaderiv(vertS, GL_COMPILE_STATUS, &compiled);
			if (compiled == GL_FALSE)
			{
				std::cout << "Failed to compile vertex shader";

				GLint maxLength = 0;
				glGetShaderiv(vertS, GL_INFO_LOG_LENGTH, &maxLength);
				std::vector<GLchar> errorLog(maxLength);
				glGetShaderInfoLog(vertS, maxLength, &maxLength, &errorLog[0]);
				std::cout << "\n" << &errorLog[0];
			}

			const GLchar* fragmentShader =
			{
				"#version 400\n"\
				"in vec2 ex_UV;\n"\
				"in vec4 ex_Color;\n"\
				"in vec3 ex_Norm;\n"\
				"uniform sampler2D myText;\n"\
				"out vec4 out_Color;\n"\

				"void main(void)\n"\
				"{\n"\
				" out_Color = ex_Color;\n"\
				"vec3 l = normalize(vec3(-1.0, -1.0, -1.0)); \n" \
				" float d = dot(l, ex_Norm);	\n" \
				" out_Color = texture(myText, ex_UV);\n" \
				" //out_Color = vec4(1.0, 1.0, 0.0,1.0) * ex_UV.y;\n" \
				"}\n"
			};

			fragS = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragS, 1, &fragmentShader, NULL);
			glCompileShader(fragS);

			glGetShaderiv(fragS, GL_COMPILE_STATUS, &compiled);
			if (compiled == GL_FALSE)
			{
				std::cout << "Failed to compile fragment shader";
				GLint maxLength = 0;
				glGetShaderiv(fragS, GL_INFO_LOG_LENGTH, &maxLength);
				std::vector<GLchar> errorLog(maxLength);
				glGetShaderInfoLog(fragS, maxLength, &maxLength, &errorLog[0]);
				std::cout << "\n" << &errorLog[0];
			}
			GLuint shaderProgram = glCreateProgram();
			if (shaderProgram == 0) std::cout << "Failed to create shader program";

			programID = glCreateProgram();
			glAttachShader(programID, vertS);
			glAttachShader(programID, fragS);
			glLinkProgram(programID);
			glUseProgram(programID);
			
			glEnable(GL_CULL_FACE);
			glCullFace(GL_BACK);
			glEnable(GL_DEPTH_TEST);


		}

		GLuint Graphics::loadObjShader(std::string _path)
		{
			GLuint shaderID;
			std::string shaderString;

			std::ifstream stream(_path+ ".vert" , std::ios::in);

			if (stream.is_open())
			{
				std::string Line = "";

				while (getline(stream, Line)) { shaderString += "\n" + Line; }

				stream.close();
			}

			const GLchar* vertexShader = shaderString.c_str();
			
			
			GLuint vertShade;
			//stop trying to turn a vector into a float you dumbass
			vertShade = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertShade, 1, &vertexShader, NULL);
			glCompileShader(vertShade);
			int compiled = 0;
			glGetShaderiv(vertShade, GL_COMPILE_STATUS, &compiled);
			if (compiled == GL_FALSE)
			{
				std::cout << "Failed to compile vertex shader";

				GLint maxLength = 0;
				glGetShaderiv(vertShade, GL_INFO_LOG_LENGTH, &maxLength);
				std::vector<GLchar> errorLog(maxLength);
				glGetShaderInfoLog(vertShade, maxLength, &maxLength, &errorLog[0]);
				std::cout << "\n" << &errorLog[0];
			}
			shaderString.clear();
			std::string mix = _path + ".frag";

			stream.open(mix, std::ios::in);
			if (stream.is_open())
			{
				std::string Line = "";

				while (getline(stream, Line)) { shaderString += "\n" + Line; }

				stream.close();
			}

			const GLchar* fragmentShader = shaderString.c_str();
			
			GLuint fragShade;
			fragShade = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragShade, 1, &fragmentShader, NULL);
			glCompileShader(fragShade);

			glGetShaderiv(fragShade, GL_COMPILE_STATUS, &compiled);
			if (compiled == GL_FALSE)
			{
				std::cout << "Failed to compile fragment shader";
				GLint maxLength = 0;
				glGetShaderiv(fragShade, GL_INFO_LOG_LENGTH, &maxLength);
				std::vector<GLchar> errorLog(maxLength);
				glGetShaderInfoLog(fragShade, maxLength, &maxLength, &errorLog[0]);
				std::cout << "\n" << &errorLog[0];
			}
			GLuint shaderProgram = glCreateProgram();
			if (shaderProgram == 0) std::cout << "Failed to create shader program";
			
			GLuint programID;
			programID = glCreateProgram();


			glAttachShader(programID, vertShade);
			glAttachShader(programID, fragShade);
			glLinkProgram(programID);
			glUseProgram(programID);

			//shaderID = glCreateProgram();
			
			//glDeleteShader(vertShade);
			//glDeleteShader(fragShade);
			glEnable(GL_CULL_FACE);
			glCullFace(GL_BACK);
			glEnable(GL_DEPTH_TEST);
			return programID;
		}

		void Graphics::useShader()
		{
			glUseProgram(programID);;
		}

		void Graphics::draw(objPart* _modelNode, glm::mat4 _MVP, std::shared_ptr<DCamera> miike)
		{
			glEnable(GL_DEPTH_TEST);
			glUseProgram(programID);;
			//glm::mat4 view = glm::lookAt(glm::vec3(5.0f, 5.0f, 5.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			glm::mat4 view = glm::lookAt(miike->getPosition(), miike->getPosition() + miike->getTarget(), glm::vec3(0.0f, 1.0f, 0.0f));
			//TODO: Change renderings status depending on if within viewspace.
			//glm::mat4 proj = glm::ortho(-100.0f, 100.0f, -100.0f, 100.0f, -100.0f, 100.0f);
			
			glm::mat4 proj = glm::perspective(45.0f, 800.0f / 600.0f, 0.1f, 200.0f);
			//glm::mat4 inModel = glm::translate(glm::mat4(), _position);
			glm::vec4 worldLight = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			GLint projMatUniform = glGetUniformLocation(programID, "projMat");
			GLint modelMatUniform = glGetUniformLocation(programID, "in_Model");
			GLint viewMatUniform = glGetUniformLocation(programID, "in_View");
			GLint worldLightUni = glGetUniformLocation(programID, "WSlight");
			//GLint textUni = glGetUniformLocation(programID, "myText");
			glUniform4fv(worldLightUni, 1, glm::value_ptr(worldLight));
			glUniformMatrix4fv(projMatUniform, 1, GL_FALSE, glm::value_ptr(proj));
			glUniformMatrix4fv(modelMatUniform, 1, GL_FALSE, glm::value_ptr(_MVP));
			glUniformMatrix4fv(viewMatUniform, 1, GL_FALSE, glm::value_ptr(view));
			//glUniform1i(textUni, 0);
			//glActiveTexture(GL_TEXTURE0 + 0);
			//glBindSampler(0, linearFiltering);
			objPart* head = _modelNode;
			while (_modelNode != NULL)
			{
				glBindTexture(GL_TEXTURE_2D, _modelNode->tex);
				glBindVertexArray(_modelNode->partVAO);
				glDrawArrays(GL_TRIANGLES, 0, _modelNode->vertice.size() / 3);
				_modelNode = _modelNode->nextPart;
			}
			_modelNode = head;

			glUseProgram(0);
		}

		void Graphics::setCam(std::shared_ptr<DCamera> _newCam)
		{
			//miike = _newCam;
		}
		
		void Graphics::setTarget(std::shared_ptr<GameObject> _parent)
		{
			//miike->parent = _parent;
		}

		/*GLuint Graphics::getShader()
		{

		}*/

	