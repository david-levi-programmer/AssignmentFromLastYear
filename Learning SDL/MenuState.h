#pragma once

#include "Game.h"
#include "State.h"
#include "Input.h"
#include "Screen.h"
#include "Vector.h"
#include "Text.h"
#include "Music.h"
#include "PlayState.h"
#include <string>

class MenuState : public State
{
	
public:

	~MenuState() override = default;

	bool OnEnter() override;
	State* Update() override;
	bool Render() override;
	void OnExit() override;

private:

	Sprite m_background;
	Text m_text;
	Music m_music;

};