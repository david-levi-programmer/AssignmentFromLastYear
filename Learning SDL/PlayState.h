#pragma once

#include <memory>
#include "Sprite.h"
#include "Music.h"
#include "Player.h"
#include "State.h"
#include "Sound.h"
#include "Score.h"
#include "Text.h"
#include "BoxCollider.h"
#include "Coin.h"
#include "WinState.h"

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
	Score m_score;
	Music m_music;
	Player m_player;
	Text m_text;
	Coin m_coin;

};