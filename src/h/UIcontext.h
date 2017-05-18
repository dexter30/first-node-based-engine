#pragma once
#include "../h/Component.h"
#include <string>
#include <glm\glm.hpp>
#include "../h/WhoDeanUI.h"
#include <string>
#include <vector>
#include "../h/Input.h"
class UIcontext: public Component
{
public:
	UIcontext();
	UIcontext(std::string _words, GLfloat x, GLfloat y);
	UIcontext(std::string _path);
	void onStart();
	void update();
	void changeText(std::string _words);
	void loadScript(std::string _path);
	void speakText();
	void onCollision(std::string _path);
private:
	int scriptLine;
	bool textTrigger  = false;
	std::vector<std::string> script;
	int x, y;
	int width, height;
	std::string wordsToPrint;
};

