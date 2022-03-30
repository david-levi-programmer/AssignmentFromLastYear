#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Music.h"

class Buttons : public GameObject
{

public:

	Buttons();

	virtual void Update();
	virtual void Render();

private:

	bool m_isClicked{ false };
	bool m_isHoveredOver{ false };
	Sprite m_image;
	SDL_Rect m_spritePosition;

};