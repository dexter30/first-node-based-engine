#include "../h/MeshData.h"
GLfloat vertices[] = {
	-0.8f, 0.8f, 0.0f, 1.0f,
	
	0.8f, 0.8f, 0.0f, 1.0f,
	0.0f, -0.8f, 0.0f, 1.0f
};

GLfloat colors[] = {
	1.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f
};

MeshData::MeshData()
{
	

	
 
  
}

void MeshData::update()
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//while (modelNode != NULL)
	//{

	//std::cout << "My Message: " << message << "\n";
	if (parent->getlife())
	{
		std::shared_ptr<DCamera> ref = cameraControl::getMainCam().lock();
		glm::mat4 MVP = glm::translate(glm::mat4(), transformRef.lock()->getPos());
		MVP = glm::scale(MVP, transformRef.lock()->getScale());
		renderer.draw(modelNode, MVP, ref);
	}
	//modelNode = modelNode->nextPart;
	//}
}

MeshData::~MeshData()
{
}

void MeshData::recalculateBounds()
{
	mode = modelNode;
	float minX = mode->vertice.at(0);
	float maxX = mode->vertice.at(0);

	float minY = mode->vertice.at(1);
	float maxY = mode->vertice.at(1);
	
	float minZ = mode->vertice.at(2);
	float maxZ = mode->vertice.at(2);

	while (mode != NULL)
	{
		for (int i = 0; i < mode->vertice.size(); i += 3)
		{
			if (mode->vertice.at(i) < minX)
			{
				minX = mode->vertice.at(i);
			}
			if (mode->vertice.at(i) > maxX)
			{
				maxX = mode->vertice.at(i);
			}

			if (mode->vertice.at(i + 1) < minY)
			{
				minY = mode->vertice.at(i + 1);
			}
			if (mode->vertice.at(i + 1) > maxY)
			{
				maxY = mode->vertice.at(i + 1);
			}

			if (mode->vertice.at(i + 2) < minZ)
			{
				minZ = mode->vertice.at(i + 2);
			}
			if (mode->vertice.at(i + 2) > maxZ)
			{
				maxZ = mode->vertice.at(i + 2);
			}
		}
		mode = mode->nextPart;

	}
	float midX = (maxX + minX) / 2.0f;
	float midY = (maxY + minY) / 2.0f;
	float midZ = (maxZ + minZ) / 2.0f;

	float sizeX = maxX - minX;
	float sizeY = maxY - minY;
	float sizeZ = maxZ - minZ;

	meshBounds = bounds(glm::vec3(midX, midY, midY), glm::vec3(sizeX, sizeY, sizeZ));
	mode = modelNode;
	
}

glm::vec3 MeshData::getBounds()
{
	return meshBounds.getSize();
}


void MeshData::onStart()
{
	renderer.init();
	transformRef = parent->getComp<Transform>();
	transformRef.lock()->setPos(-meshBounds.getcentre());

}

void MeshData::LoadAsset(char* _name)
{
	int totalInts = 0;
	int totalVerts = 0;
	int totalnorms = 0;

	objfile model(_name);
	objPart *mode = model.getVertices();
	objPart *model1 = new objPart;
	*model1 = objfile::reversedLinkedList(mode);
	mode = new objPart;
	mode = model1;

	while (mode != NULL)
	{
		mode->offset = totalVerts;
		totalVerts += mode->vertCount;

		mode->ioffset = totalInts;
		totalInts += mode->elements.size();

		totalnorms += mode->vn.size();
		mode = mode->nextPart;

	}
	mode = model1;

	modelNode = model1;
	long partSize = 0;
	while (mode != NULL)
	{
		glGenVertexArrays(1, &mode->partVAO);
		glBindVertexArray(mode->partVAO);
		glGenBuffers(1, &mode->partVBO);
		glBindBuffer(GL_ARRAY_BUFFER, mode->partVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float)* mode->vertice.size(), &mode->vertice[0], GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(0);


		glGenBuffers(1, &mode->partElem);
		glBindBuffer(GL_ARRAY_BUFFER, mode->partElem);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float)*mode->vn.size(), &mode->vn[0], GL_STATIC_DRAW);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(1);

		glGenBuffers(1, &mode->partUV);
		glBindBuffer(GL_ARRAY_BUFFER, mode->partUV);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float)*mode->vt.size(), &mode->vt[0], GL_STATIC_DRAW);

		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(2);

		
		glGenTextures(1, &mode->tex);
		glBindTexture(GL_TEXTURE_2D, mode->tex);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,mode->texWidth, mode->texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, mode->image);
		//glEnable(GL_TEXTURE_2D);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		
		mode = mode->nextPart;
		


	}
	mode = model1;



	recalculateBounds();
}

glm::vec3 MeshData::getCenter()
{
	return meshBounds.getcentre();
}