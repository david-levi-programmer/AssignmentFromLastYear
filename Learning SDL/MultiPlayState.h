#pragma once

#include <memory>
#include "State.h"
#include "PlayState.h"
#include "Client.h"
#include "Server.h"

class MultiPlayState : public State
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
	Message m_message;
	Coin m_coin;
	Server m_host;
	Client m_client;

};