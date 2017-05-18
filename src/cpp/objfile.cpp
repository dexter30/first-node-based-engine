#include "../h/objfile.h"
#include <string>

#include "../h/lodepng.h"
objfile::objfile(std::string _name)
{
	//we aassign a name to this class.
	//name = _name;
	name = _name;
}


objfile::~objfile(void)
{
	

}


objPart* objfile::getVertices()
{
	//We read in the information from the file and then we load it in to the objpart struct.
	
	
	
	int linenumber =0; //The programs internal line counter since most libraries don't keep track of document line.
	
	//This is the instance of a struct where we save our information .
	objPart *currentObj = NULL;
	
	//We open the file with ifstream.
	
	std::ifstream file(name + ".obj");
	//Then we have a few strings to save the dummy values we don't need.
	std::string lineT, v, o; 
	while (std::getline(file, lineT))
	{
		float x, y, z;
		linenumber++;
		if (lineT[0] != NULL)
		{
			std::istringstream iss(lineT);
			if (lineT[0] == 'v'&& lineT[1] != 'n' && lineT[1] != 't')
			{
				

										//Use the string stream to assign the values.
				iss >> v >> x >> y >> z;


				//then we push into our vector for use later.
				//currentObj->vertice.push_back(x);
				//currentObj->vertice.push_back(y);
				//currentObj->vertice.push_back(z);
				glm::vec3 toAdd(x, y, z);
				posStore.push_back(toAdd);
			}
			if (lineT[0] == 'v' && lineT[1] == 'n')
			{
				//currentObj->UVcount++;
				iss >> v >> x >> y >> z;
				//currentObj->vn.push_back(x);
				//currentObj->vn.push_back(y);
				//currentObj->vn.push_back(z);
				glm::vec3 toAdd(x, y, z);
				normStore.push_back(toAdd);
			}

			//and same for texture coords
			if (lineT[0] == 'v' && lineT[1] == 't')
			{
				//currentObj->vtCount++;
				iss >> v >> x >> y;
				glm::vec2 toAdd(x, 1-y);
				vtStore.push_back(toAdd);
			}
		}
	}

	//We must initialise the ints.
	
	int vtCount=0;
	file.clear();
	file.seekg(0);
	//now we begin the main loop this loop will go through every line and we handle the infomration accordingly as we hit each line.
	while(std::getline(file, lineT))
	{
		linenumber++;
		float x, y, z; 
		int x1, y1, z1, w1, u1, b1 , r1, s1, t1;
		char slash;
		//This is so we ignore blank lines.
		if (lineT[0] != NULL)
		{
		std::istringstream iss( lineT ); //This allows us to record the line 
		
		//This is if we read a simple vertice.

		if ((lineT[0] == 'o' || lineT[0] == 'g' ) && lineT[1] == ' ')
		{
			if (currentObj != NULL)
			{
				objPart* newObj = currentObj;
				currentObj = new objPart;
				currentObj->nextPart = newObj;
				currentObj->vertCount = 0;
				currentObj->indicesCount = 0;
				currentObj->UVcount = 0;
				currentObj->vtCount = 0;
				currentObj->position = glm::vec3(1.0f, 1.0f, 0.0f);
				currentObj->angles[0] = 0;
				currentObj->angles[1] = 0;
				currentObj->angles[2] = 0;
				
			}
			else{
				currentObj = new objPart;
				currentObj->vertCount = 0;
				currentObj->indicesCount = 0;
				currentObj->UVcount = 0;
				currentObj->vtCount = 0;
				currentObj->nextPart = NULL;
			}
			iss >> v >> currentObj->partName;
			
		}

	
		
		if (lineT[0] == 'u')
		{
			
			iss >> v >> o;
			currentObj->matName = o;

			currentObj->textureName = getTexture(currentObj->matName);
			
			currentObj->textureName = "res/" + currentObj->textureName;
			lodepng_decode32_file(&currentObj->image, &currentObj->texWidth, &currentObj->texHeight, currentObj->textureName.c_str());
			
		
		}
		
		

		//Faces is slightly different. because of how they are structured.
		if(lineT[0] == 'f')
		{
			currentObj->vertCount++;// increment count
			//the slash string just saves the slash thats in the obj file.
			currentObj->indicesCount++;
			iss>>v>>x1>>slash>>y1>>slash>>z1>>
				    u1>>slash>>b1>>slash>>w1>>
				    r1>>slash>>s1>>slash>>t1;
			//we have to decrement the indices because the index in the vector start at 0 not 1 like it is in the obj.
			x1--;
			u1--;
			r1--;
			z1--;
			w1--;
			t1--;
			y1--;
			b1--;
			s1--;
			x1=abs(x1);
			y1=abs(y1);
			z1=abs(z1);
			u1=abs(u1);
			b1=abs(b1);
			w1=abs(w1);
			r1=abs(r1);
			s1=abs(s1);
			t1=abs(t1);
			
			currentObj->elements.push_back(x1);
			currentObj->verttext.push_back(y1);
			currentObj->normalinds.push_back(z1);
			currentObj->elements.push_back(u1);
			currentObj->verttext.push_back(b1);
			currentObj->normalinds.push_back(w1);
			currentObj->elements.push_back(r1);
			currentObj->verttext.push_back(s1);
			currentObj->normalinds.push_back(t1);

			currentObj->vertice.push_back(posStore.at(x1).x);
			currentObj->vertice.push_back(posStore.at(x1).y);
			currentObj->vertice.push_back(posStore.at(x1).z);

			currentObj->vertice.push_back(posStore.at(u1).x);
			currentObj->vertice.push_back(posStore.at(u1).y);
			currentObj->vertice.push_back(posStore.at(u1).z);

			currentObj->vertice.push_back(posStore.at(r1).x);
			currentObj->vertice.push_back(posStore.at(r1).y);
			currentObj->vertice.push_back(posStore.at(r1).z);

			currentObj->vt.push_back(vtStore.at(y1).x);
			currentObj->vt.push_back(vtStore.at(y1).y);
										  
										  
			currentObj->vt.push_back(vtStore.at(b1).x);
			currentObj->vt.push_back(vtStore.at(b1).y);
										  
										  
			currentObj->vt.push_back(vtStore.at(s1).x);
			currentObj->vt.push_back(vtStore.at(s1).y);
			

			currentObj->vn.push_back(normStore.at(z1).x);
			currentObj->vn.push_back(normStore.at(z1).y);
			currentObj->vn.push_back(normStore.at(z1).z);
										  	  
			currentObj->vn.push_back(normStore.at(w1).x);
			currentObj->vn.push_back(normStore.at(w1).y);
			currentObj->vn.push_back(normStore.at(w1).z);
													  	  
			currentObj->vn.push_back(normStore.at(t1).x);
			currentObj->vn.push_back(normStore.at(t1).y);
			currentObj->vn.push_back(normStore.at(t1).z);
		}												  
		}

	}
	
	return currentObj;
}

objPart objfile::reversedLinkedList(objPart* head)
{
	if (head == NULL) { return *head; }

	objPart *newRoot = NULL;
	while (head){
		objPart *next = head->nextPart;
		head->nextPart = newRoot;
		newRoot = head;
		head = next;
	}
	// now let the head point at the last node (prev)
	return *newRoot;

}

std::string objfile::getTexture(std::string _name)
{
	//We open the file with ifstream.
	std::ifstream file(name + ".mtl");
	//Then we have a few strings to save the dummy values we don't need.
	int linenumber = 0;
	std::string lineT, v, o;
	bool CorrectFile = false;
	while (std::getline(file, lineT))
	{
		linenumber++;
		if (lineT[0] != NULL)
		{
			std::stringstream iss(lineT);
			if (lineT[0] == 'n')
			{
				iss >> v >> o;
				if (_name == o)
				{
					CorrectFile = true;
				}
			}
			if ((lineT[1] == 'm' || lineT[0] == 'm') && CorrectFile == true)
			{
				iss >> v >> o;
				return o;
				//objnoText.textureName = o;
			}

		}
	}
	file.close();
	return "";
}

GLuint objfile::loadCubemap(std::vector<const GLchar*> faces)
{
	GLuint textureID;
	glGenTextures(1, &textureID);
	//glActiveTexture(GL_TEXTURE0);

	unsigned int width, height;
	unsigned char* image;

	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
	for (GLuint i = 0; i < faces.size(); i++)
	{
		lodepng_decode32_file(&image, &width, &height, faces[i]);



		//image = SO2IL_load_image(faces[i], &width, &height, 0, SOIL_LOAD_RGB);
		glTexImage2D(
			GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0,
			GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image
		);

	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	return textureID;
}

std::string objfile::read(std::string fileName) const
{
	std::string shaderString;

	std::ifstream stream(fileName, std::ios::in);

	if (stream.is_open())
	{
		std::string Line = "";

		while (getline(stream, Line)) { shaderString += "\n" + Line; }

		stream.close();
	}

	return shaderString;
}