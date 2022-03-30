#pragma once
#include <string>

#include "Game.h"
#include "Input.h"
#include "Block.h"
#include "Music.h"
#include "Player.h"
#include "State.h"
#include "Sound.h"
#include "Score.h"
#include "Text.h"
#include "Vector2D.h"

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
	Music music;
	Player player;
	Text font;


};