#include <iostream>
#include <string>

#include "PlayState.h"

bool PlayState::OnEnter()
{
	background.Load("Assets/Images/Shapes.jpg"); //Found on Google Images, searching for royalty-free images
	background.SetSpriteDimension(1280, 720);
	background.SetImageDimension(1, 1, 500, 500);

	player.SetPosition(50, 450);
	player.SetAngle(0.0);
	player.SetSize(100, 100);
	player.SetSpeed(5);

	stone.SetPosition(1000, 500);
	stone.SetAngle(0.0);
	stone.SetSize(50, 50);
	stone.SetSpeed(0);

	music.Load("Assets/Audio/Music/bensound-clearday.mp3"); // Composed by Bensound and downloaded from his website
	music.Play(Music::PlayLoop::PLAY_ENDLESS);

	font.Load("Assets/Images/home-away.regular.otf", 12);
	font.Render(50, 450);
	score.SetScore(100);

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

	player.Update();

	//=====================================================

	stone.Update();

	//===========Collision=================================
	BoxCollide playerCollider = player.GetCollider();
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
	background.Render(0, 0, 0.0);

	player.Render();

	if (player.isVisible())
	{
		player.Render();
	}

	stone.Render();

	score.Render();

	return true;
}

void PlayState::OnExit()
{
	Music::Shutdown();
	Text::Shutdown();
	background.Unload();
}