#include <iostream>
#include "PlayState.h"

bool PlayState::OnEnter()
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

	m_music.Load("Assets/Audio/Music/Clear Day.mp3"); // Composed by Bensound and downloaded from his website
	m_music.Play(Music::PlayLoop::PlayEndless);

	m_score.SetScore(0);

	return true;
}

State* PlayState::Update()
{
	if (Input::Instance()->IsWindowClosed())
	{
		return nullptr;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE))
	{
		return nullptr;
	}

	//=======================Object States==================

	m_player.Update();
	m_coin.Update();

	//=======================Collision======================

	if (m_player.GetCollider().IsColliding(m_coin.GetCollider()))
	{
		m_score.AddtoScore();
		m_coin.SetPosition(rand() % 790, 520);
	}

	//=======================Timer/Score====================

	if (m_score.VictoryCheck() == true)
	{
		return new WinState;
	}

	//======================================================

	return this;
}

bool PlayState::Render()
{
	m_background.Render(0, 0, 0.0);

	if (m_player.isVisible())
	{
		m_player.Render();
	}
	
	m_coin.Render();

	m_score.Render();

	return true;
}

void PlayState::OnExit()
{
	m_music.Unload();
}