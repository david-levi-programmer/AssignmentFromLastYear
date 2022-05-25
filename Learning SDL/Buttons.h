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
		Default,
		Hovered,
		Clicked
	};

	Buttons(const std::string& filename);

	const Status& GetState() const;
	void Shutdown();

	virtual void Update();
	virtual void Render();

private:

	bool m_isClicked{ false };
	bool m_isHoveredOver{ false };
	Status m_buttonState;
	Sprite m_image;
	SDL_Rect m_mousePosition, m_spritePosition;
	Sound m_hoverSound, m_clickSound;

};