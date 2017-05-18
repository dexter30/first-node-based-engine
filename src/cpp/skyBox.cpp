#include "../h/skyBox.h"



skyBox::skyBox()
{
}


skyBox::~skyBox()
{
}

void skyBox::genSkybox(DCamera _cam)
{
	camera = _cam;
	std::vector<const GLchar*> faces;
	faces.push_back("res/darkcity_rt.png");
	faces.push_back("res/darkcity_lf.png");
	faces.push_back("res/darkcity_up.png");
	faces.push_back("res/darkcity_dn.png");
	faces.push_back("res/darkcity_bk.png");
	faces.push_back("res/darkcity.ft.png");



	cubeText = objfile::loadCubemap(faces);
	shader = Graphics::loadObjShader("res/sky");

	const float skyboxVertices[] = {
		// Positions          
		-130.0f,  130.0f, -130.0f,
		-130.0f, -130.0f, -130.0f,
		130.0f, -130.0f, -130.0f,
		130.0f, -130.0f, -130.0f,
		130.0f,  130.0f, -130.0f,
		-130.0f,  130.0f, -130.0f,

		-130.0f, -130.0f,  130.0f,
		-130.0f, -130.0f, -130.0f,
		-130.0f,  130.0f, -130.0f,
		-130.0f,  130.0f, -130.0f,
		-130.0f,  130.0f,  130.0f,
		-130.0f, -130.0f,  130.0f,

		130.0f, -130.0f, -130.0f,
		130.0f, -130.0f,  130.0f,
		130.0f,  130.0f,  130.0f,
		130.0f,  130.0f,  130.0f,
		130.0f,  130.0f, -130.0f,
		130.0f, -130.0f, -130.0f,

		-130.0f, -130.0f,  130.0f,
		-130.0f,  130.0f,  130.0f,
		130.0f,  130.0f,  130.0f,
		130.0f,  130.0f,  130.0f,
		130.0f, -130.0f,  130.0f,
		-130.0f, -130.0f,  130.0f,

		-130.0f,  130.0f, -130.0f,
		130.0f,  130.0f, -130.0f,
		130.0f,  130.0f,  130.0f,
		130.0f,  130.0f,  130.0f,
		-130.0f,  130.0f,  130.0f,
		-130.0f,  130.0f, -130.0f,

		-130.0f, -130.0f, -130.0f,
		-130.0f, -130.0f,  130.0f,
		130.0f, -130.0f, -130.0f,
		130.0f, -130.0f, -130.0f,
		-130.0f, -130.0f,  130.0f,
		130.0f, -130.0f,  130.0f
	};

	glGenVertexArrays(1, &skyVAO);
	glGenBuffers(1, &skyVBO);
	glBindVertexArray(skyVAO);
	
	glBindBuffer(GL_ARRAY_BUFFER, skyVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)* 36, &skyboxVertices[0], GL_STATIC_DRAW);
glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glBindVertexArray(0);
	

}

void skyBox::render()
{
	//glEnable(GL_CULL_FACE);
	
	glDepthMask(GL_FALSE);
	glUseProgram(shader);
	glDisable(GL_CULL_FACE);
	glm::mat4 view = glm::lookAt(camera.getPosition(), camera.getPosition() + camera.getTarget(), glm::vec3(0.0f, 50.0f, 0.0f));
	glm::mat4 proj = glm::perspective(45.0f, 800.0f / 600.0f, 0.1f, 200.0f);

	GLint projMatUniform = glGetUniformLocation(shader, "projection");

	GLint viewMatUniform = glGetUniformLocation(shader, "view");
	glUniformMatrix4fv(projMatUniform, 1, GL_FALSE, glm::value_ptr(proj));
	glUniformMatrix4fv(viewMatUniform, 1, GL_FALSE, glm::value_ptr(view));

	glBindVertexArray(skyVAO);
	glActiveTexture(GL_TEXTURE0);
	//glUniform1i(glGetUniformLocation(shader, "skybox"), 0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubeText);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
	glDepthMask(GL_TRUE);
	glUseProgram(0);
}