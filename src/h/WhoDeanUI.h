#pragma once
#include <freetype-2.7.1\include\ft2build.h>
#include FT_FREETYPE_H

#include "../h/Graphics.h"
#include <iostream>
#include <map>
#include "../h/Display.h"

struct Character {
	GLuint     TextureID;  // ID handle of the glyph texture
	glm::ivec2 Size;       // Size of glyph
	glm::ivec2 Bearing;    // Offset from baseline to left/top of glyph
	GLuint     Advance;    // Offset to advance to next glyph
};


class WhoDeanUI
{
public:
	static void InitdeanUI();
	static void RenderText(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
private:
	
	static FT_Library ft;
	static FT_Face face;
	static GLuint tex;
	static std::map<GLchar, Character> Characters;
	static glm::mat4 projection;
	static GLuint VAO, VBO;
	static GLuint tShader;
};

