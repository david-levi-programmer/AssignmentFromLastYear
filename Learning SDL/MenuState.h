#pragma once

#include "Game.h"
#include "State.h"
#include "Input.h"
#include "Screen.h"
#include "Main.h"
#include "Vector2D.h"
#include "Text.h"
#include "Music.h"
#include "Sound.h"
#include <string>

class MenuState : public State
{
	
public:

	MenuState() {}
	~MenuState() override {}

	bool OnEnter() override;
	State* Update() override;
	bool Render() override;
	void OnExit() override;
};