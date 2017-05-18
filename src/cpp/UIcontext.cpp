#include "../h/UIcontext.h"

UIcontext::UIcontext()
{
	
}

UIcontext::UIcontext(std::string _words, GLfloat _x, GLfloat _y )
{
	wordsToPrint = _words;
	x = _x;
	y = _y;
}

void UIcontext::onStart()
{

}

void UIcontext::update()
{
	
	int px=0, py =0;
	
	if (textTrigger == true)
	{
		
		if (Input::_getKeys(32))
		{
			
			
				scriptLine++;
			
		}
		if (scriptLine >= script.size())
		{
			textTrigger = false;

		}
		speakText();
		
	}

}

void UIcontext::changeText(std::string _words)
{
	script.push_back(_words);
	textTrigger = true;
}

void UIcontext::speakText()
{
	if (textTrigger == true)
	{
		WhoDeanUI::RenderText(script[scriptLine], x, y, 1.0f, glm::vec3(4.0f, 1.0f, 0.0f));
	}
}


UIcontext::UIcontext(std::string _path)
{
	std::ifstream stream(_path + ".txt", std::ios::in);
	std::string shaderString;
	if (stream.is_open())
	{

		std::string Line = "";

		while (getline(stream, Line)) { script.push_back(Line); }

		stream.close();
	}
	x = 0;
	y = 500;
	scriptLine = 0;
}

void UIcontext::onCollision(std::string _obj)
{
	if (_obj == "player")
	{
		textTrigger = true;
	}
}