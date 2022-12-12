#include "MultiPlayState.h"

bool MultiPlayState::OnEnter()
{
	m_background.Load("Assets/Images/MysteryCave.jpg"); //Downloaded from Vecteezy
	m_background.SetSpriteDimension(1280, 720);
	m_background.SetImageDimension(1, 1, 1920, 696);

	m_player.SetPosition(0, 520);
	m_player.SetAngle(0.0);
	m_player.SetSize(10, 10);
	m_player.SetSpeed(5);

	m_coin.SetPosition(rand() % 790, 520);
	m_coin.SetAngle(0.0);
	m_coin.SetSize(10, 10);

	m_message.SetMessage("Welcome!");

	m_music.Load("Assets/Audio/Music/Creative Minds.mp3"); // Composed by Bensound and downloaded from his website
	m_music.Play(Music::PlayLoop::PlayEndless);

	return true;
}

State* MultiPlayState::Update()
{
	if (Input::Instance()->IsWindowClosed())
	{
		return nullptr;
	}

	return this;
}

bool MultiPlayState::Render()
{
    return false;
}

void MultiPlayState::OnExit()
{
	m_host.ShutDown();
	m_client.ShutDown();
}