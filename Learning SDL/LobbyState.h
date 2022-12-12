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

private:

	Sprite m_background;
	Text m_text;
	Music m_music;
	Server m_host;
	Client m_client;

};