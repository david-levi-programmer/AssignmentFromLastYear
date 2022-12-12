#include "ResultsState.h"

bool ResultsState::OnEnter()
{
	m_background.Load("Assets/Images/MysteryCave.jpg"); //Downloaded from Vecteezy
	m_background.SetSpriteDimension(1280, 720);
	m_background.SetImageDimension(1, 1, 1920, 696);

	m_music.Load("Assets/Audio/Music/Energy.mp3"); // Composed by Bensound and downloaded from his website
	m_music.Play(Music::PlayLoop::PlayEndless);

	m_text.Load("Assets/Images/nevis.ttf", 100); //downloaded for free
	m_text.SetColor(0, 0, 0, 255);
	m_text.SetDimension(1000, 100);
	m_text.SetText("VICTORY!!! ENTER: Back to Lobby SPACE: Main Menu ESC: Quit");

	return true;
}

State* ResultsState::Update()
{
	if (Input::Instance()->IsWindowClosed())
	{
		return nullptr;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_RETURN))
	{
		return new LobbyState;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_SPACE))
	{
		return new MenuState;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE))
	{
		return nullptr;
	}

	return this;
}

bool ResultsState::Render()
{
	m_background.Render(0, 0, 0.0);

	m_text.Render(150, 300);

	return true;
}

void ResultsState::OnExit()
{
	m_background.Unload();
	m_text.Unload();
	m_music.Unload();
}