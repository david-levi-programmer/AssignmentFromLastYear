#include "PlayState.h"
#include <iostream>
#include <string>
#include "Score.h"
#include "BoxCollide.h"
#include "Player.h"
#include "Vector2D.h"
#include "Block.h"

Input input;
Screen screen;
Sprite background;
Player player(screen);
Block stone(screen);
Score* score = new Score;

bool PlayState::OnEnter()
{
	background.Load("Assets/Images/500_F_286150681_7Wct7Snh4fGqCYWD3NN5DQTXIsvH5Gw2.jpg", screen); //Found on Google Images, searching for royalty-free images
	background.SetSpriteDimension(1280, 720);
	background.SetImageDimension(1, 1, 1280, 720);

	player.SetPosition(50, 450);
	player.SetAngle(0.0);
	player.SetSize(100, 100);
	player.SetSpeed(5);

	stone.SetPosition(1000, 500);
	stone.SetAngle(0.0);
	stone.SetSize(50, 50);
	stone.SetSpeed(0);

	Music music;
	music.Load("Assets/Audio/Music/bensound-clearday.mp3"); // Composed by Bensound and downloaded from his website
	music.Play(Music::PlayLoop::PLAY_ENDLESS);

	score->SetScore(100);
    
    return true;
}

State* PlayState::Update()
{
	while (IsGameRunning)
	{
		input.Update();

		if (input.ClosedWindow())
		{
			IsGameRunning = false;
		}

		if (input.GetKeyDown() == SDLK_ESCAPE)
		{
			IsGameRunning = false;
		}

		//======================Code for debugging================

		/*if (input.GetKeyDown() == SDLK_LEFT)
		{
			std::cout << "Left key pressed. Move player left." << std::endl;
		}

		if (input.GetKeyDown() == SDLK_RIGHT)
		{
			std::cout << "Right key pressed. Move player right." << std::endl;
		}

		if (input.KeyPress())
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

		player.Update(input);
		
		//=====================================================

		stone.Update(input);
		
		//===========Collision=================================
		BoxCollide playerCollider = player.GetCollider();
		BoxCollide stoneCollider = stone.GetCollider();

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

	}

	if (!IsGameRunning)
	{
		return nullptr;
	}

	return this;
}

bool PlayState::Render()
{
	background.Render(0, 0, 0.0, screen);

	player.Render(screen);

	if (player.isVisible())
	{
		player.Render(screen);
	}
	
	stone.Render(screen);

	score->Render(screen);

	screen.Present();

	return true;
}

void PlayState::OnExit()
{
	delete score;

	background.Unload();
	screen.Shutdown();
}