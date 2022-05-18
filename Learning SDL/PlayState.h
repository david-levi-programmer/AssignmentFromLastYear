#pragma once
#include <memory>
#include "Sprite.h"
#include "Block.h"
#include "Music.h"
#include "Player.h"
#include "State.h"
#include "Sound.h"
#include "Score.h"
#include "Text.h"
#include "BoxCollider.h"
#include "Coin.h"
#include "Timer.h"

class PlayState : public State
{

public:

	bool OnEnter() override;
	State* Update() override;
	bool Render() override;
	void OnExit() override;

private:

	bool m_IsGameRunning = true;
	Sprite m_background;
	//Score m_score;
	std::unique_ptr<Score> m_score;
	Block m_block;
	Music m_music;
	Player m_player;
	Text m_font;
	Coin m_coin;
	float m_time;

};