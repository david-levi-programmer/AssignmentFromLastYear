#include "PlayState.h"

bool PlayState::OnEnter()
{
	m_background.Load("Assets/Images/Shapes.jpg"); //Found on Google Images, searching for royalty-free images
	m_background.SetSpriteDimension(1280, 720);
	m_background.SetImageDimension(1, 1, 500, 500);

	m_player.SetPosition(50, 450);
	m_player.SetAngle(0.0);
	m_player.SetSize(100, 100);
	m_player.SetSpeed(5);

	m_stone.SetPosition(1000, 500);
	m_stone.SetAngle(0.0);
	m_stone.SetSize(50, 50);
	m_stone.SetSpeed(0);

	m_music.Load("Assets/Audio/Music/bensound-clearday.mp3"); // Composed by Bensound and downloaded from his website
	m_music.Play(Music::PlayLoop::PLAY_ENDLESS);

	m_font.Load("Assets/Images/home-away.regular.otf", 12);
	m_font.Render(50, 450);
	m_score.SetScore(100);

	return true;
}

State* PlayState::Update()
{
	if (Input::Instance()->ClosedWindow())
	{
		return nullptr;
	}

	if (Input::Instance()->GetKeyDown() == SDLK_ESCAPE)
	{
		return nullptr;
	}

	//======================Code for debugging================

	/*if (Input::Instance()->GetKeyDown() == SDLK_LEFT)
	{
		std::cout << "Left key pressed. Move player left." << std::endl;
	}

	if (Input::Instance()->GetKeyDown() == SDLK_RIGHT)
	{
		std::cout << "Right key pressed. Move player right." << std::endl;
	}

	if (Input::Instance()->KeyPress())
	{
		std::cout << input.GetKeyDown() << std::endl;
	}

	if (input.GetMouseButtonDown() == SDL_SCANCODE_LEFT)
	{
		std::cout << "Left button pressed" << std::endl;
	}

	else if (input.GetMouseButtonDown() == SDL_SCANCODE_RIGHT)
	{
		std::cout << "Right button pressed" << std::endl;
	}

	else if (input.GetMouseButtonDown() == SDL_BUTTON_MIDDLE)
	{
		std::cout << "Mouse wheel pressed" << std::endl;
	}*/

	/*MousePos mousePos = input.GetMousePosition();
	std::cout << "Mouse cursor is at position (" << mousePos.x << "," << mousePos.y << ")" << std::endl;*/

	//=======================Player State==================

	m_player.Update();

	//=====================================================

	m_stone.Update();

	//===========Collision=================================
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

	/*SphereCollide playerCollider = player.GetCollider();
	SphereCollide stoneCollider = stone.GetCollider();

	if (playerCollider.IsColliding(stoneCollider))
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

	m_player.Render();

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