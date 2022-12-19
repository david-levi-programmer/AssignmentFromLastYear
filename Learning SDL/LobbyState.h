#pragma once

#include <string>
#include "MenuState.h"
#include "Server.h"
#include "Client.h"

class LobbyState : public State
{

public:

	~LobbyState() override = default;

	bool OnEnter() override;
	State* Update() override;
	bool Render() override;
	void OnExit() override;

protected:

	struct Network
	{
		
	};
	//variable will contain whether player chooses to host or a join a room
	Network lobbyChoice;

private:

	Sprite m_background;
	Text m_text;
	Music m_music;
	Server m_host;
	Client m_client;

};