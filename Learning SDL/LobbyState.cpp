#include "LobbyState.h"

bool LobbyState::OnEnter()
{
	m_background.Load("Assets/Images/MysteryCave.jpg"); //Downloaded from Vecteezy
	m_background.SetSpriteDimension(1280, 720);
	m_background.SetImageDimension(1, 1, 1920, 696);
	//TODO - Find good lobby music
	m_music.Load("Assets/Audio/Music/All That.mp3"); // Composed by Bensound and downloaded from his website
	m_music.Play(Music::PlayLoop::PlayEndless);

	m_text.Load("Assets/Images/nevis.ttf", 100); //downloaded for free
	m_text.SetColor(0, 0, 0, 255);
	m_text.SetDimension(1000, 100);
	m_text.SetText("1: Host Room 2: Join Room BACKSPACE: Back");

	return true;
}

State* LobbyState::Update()
{
	if (Input::Instance()->IsWindowClosed())
	{
		return nullptr;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_1))
	{
		//TODO - server-side code
		host.Initialize();
		host.OpenSocket();
		host.CreateServer();
		host.Listen();
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_2))
	{
		//TODO - client-side code
		client.Initialize();
		client.OpenSocket();
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_BACKSPACE))
	{
		return new MenuState;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE))
	{
		return nullptr;
	}

	return this;
}

bool LobbyState::Render()
{
	m_background.Render(0, 0, 0.0);

	m_text.Render(150, 300);

	return true;
}

void LobbyState::OnExit()
{
	m_music.Unload();
	m_text.Unload();
}