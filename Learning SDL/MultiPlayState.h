#pragma once

#include <memory>
#include <thread>
#include "State.h"
#include "PlayState.h"
#include "ResultsState.h"
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
	Score m_score1;
	Score m_score2;
	Music m_music;
	Player m_player1;
	Player m_player2;
	Message m_message;
	Coin m_coin;
	Server m_host;
	Client m_client;

};