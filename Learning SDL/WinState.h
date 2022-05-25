#pragma once
#include "State.h"
#include "Sprite.h"
#include "Text.h"
#include "Input.h"
#include "PlayState.h"
#include "Music.h"

class WinState : public State
{

public:

	bool OnEnter() override;
	State* Update() override;
	bool Render() override;
	void OnExit() override;

private:

	Sprite m_background;
	Text m_text;

};