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

	m_stone.SetPosition(700, 520);
	m_stone.SetAngle(0.0);
	m_stone.SetSize(10, 10);
	m_stone.SetSpeed(0);

	m_music.Load("Assets/Audio/Music/Clear Day.mp3"); // Composed by Bensound and downloaded from his website
	m_music.Play(Music::PlayLoop::PlayEndless);

	m_font.Load("nevis.ttf", 12);
	m_font.Render(50, 450);
	m_score.SetScore(100);

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

	//=======================Player State==================

	m_player.Update();

	//=====================================================

	m_stone.Update();

	//=======================Collision=====================
	m_playerCollider = m_player.GetCollider();
	//BoxCollide stoneCollider = stone.GetCollider();

	/*if (playerCollider.IsColliding(stoneCollider))
	{
		std::cout << "Collision!" << std::endl;
	}

	else
	{
		std::cout << "No collision." << std::endl;
	}*/
	//============================

	return this;
}

bool PlayState::Render()
{
	m_background.Render(0, 0, 0.0);

	if (m_player.isVisible())
	{
		m_player.Render();
	}

	m_stone.Render();

	m_score.Render();

	return true;
}

void PlayState::OnExit()
{
	Music::Shutdown();
	Text::Shutdown();
	m_background.Unload();
}