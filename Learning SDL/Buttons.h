#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Music.h"
#include "Sound.h"
//#include "Input.h"
#include <string>

class Buttons : public GameObject
{

public:

	enum class Status
	{
		Clicked,
		Hovered,
		Default
	};

	Buttons(const std::string& filename);

	virtual void Update();
	virtual void Render();

private:

	bool m_isClicked{ false };
	bool m_isHoveredOver{ false };
	Status m_buttonState;
	Sprite m_image;
	SDL_Rect m_spritePosition;
	//Input m_mousePosition;

};