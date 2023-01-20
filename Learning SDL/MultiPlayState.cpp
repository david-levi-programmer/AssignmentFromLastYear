#include "MultiPlayState.h"

bool MultiPlayState::OnEnter()
{
	m_background.Load("Assets/Images/MysteryCave.jpg"); //Downloaded from Vecteezy
	m_background.SetSpriteDimension(1280, 720);
	m_background.SetImageDimension(1, 1, 1920, 696);

	m_music.Load("Assets/Audio/Music/Creative Minds.mp3"); // Composed by Bensound and downloaded from his website
	m_music.Play(Music::PlayLoop::PlayEndless);

	if (lobbyChoice.m_selection = Input::Instance()->IsKeyPressed(HM_KEY_1))
	{
		m_host.Initialize();
		m_host.CreateServer();
		m_host.OpenSocket();
		m_message.SetMessage("Waiting for clients...");
		m_host.Listen();
		//=========Loading in host's character==============
		m_player1.SetPosition(0, 520);
		m_player1.SetAngle(0.0);
		m_player1.SetSize(10, 10);
		m_player1.SetSpeed(5);
	}

	if (lobbyChoice.m_selection = Input::Instance()->IsKeyPressed(HM_KEY_2))
	{
		m_client.Initialize();
		m_client.OpenSocket();
		m_message.SetMessage("Welcome!");
		//=========Loading in client's character============
		m_player2.SetPosition(600, 520);
		m_player2.SetAngle(0.0);
		m_player2.SetSize(10, 10);
		m_player2.SetSpeed(5);
	}
	
	m_coin.SetPosition(rand() % 790, 520);
	m_coin.SetAngle(0.0);
	m_coin.SetSize(10, 10);

	return true;
}

State* MultiPlayState::Update()
{
	if (Input::Instance()->IsWindowClosed())
	{
		return nullptr;
	}

	//=======================Object States==================

	m_player1.Update();
	m_player2.Update(); //TODO - How the heck is THIS going to work???
	m_coin.Update();

	//=======================Collision======================

	if (m_player1.GetCollider().IsColliding(m_coin.GetCollider()))
	{
		m_score1.AddtoScore();
		m_coin.SetPosition(rand() % 790, 520);
	}

	if (m_player2.GetCollider().IsColliding(m_coin.GetCollider()))
	{
		m_score2.AddtoScore();
		m_coin.SetPosition(rand() % 790, 520);
	}

	//=======================Score==========================

	if (m_score1.VictoryCheck() == true)
	{
		winner.m_victory = 1;
		return new ResultsState;
	}
	
	if (m_score2.VictoryCheck() == true)
	{
		winner.m_victory = 2;
		return new ResultsState;
	}

	//======================================================

	return this;
}

bool MultiPlayState::Render()
{
	m_message.Render();

    return true;
}

void MultiPlayState::OnExit()
{
	m_host.ShutDown();
	m_client.ShutDown();
	m_music.Unload();
}