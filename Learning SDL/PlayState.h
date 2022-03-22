#pragma once

#include "Game.h"
#include "Sprite.h"
#include "State.h"
#include "Screen.h"
#include "Input.h"
#include "Main.h"
#include "Player.h"
#include "Vector2D.h"
#include "Block.h"
#include "Music.h"
#include "Text.h"
#include "Score.h"
#include "BoxCollide.h"
#include <string>

class PlayState : public State
{

public:

	PlayState() {}
	~PlayState() override {}

	bool OnEnter() override;
	State* Update() override;
	bool Render() override;
	void OnExit() override;

private:

	bool IsGameRunning = true;
	Sprite background;
	Score score;
	Block stone;
	Player player;


};