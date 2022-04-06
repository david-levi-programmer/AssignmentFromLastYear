#include <iostream>
#include <string>
#include "Screen.h"

Screen* Screen::Instance()
{
	static Screen* screen = new Screen;
	return screen;
}

bool Screen::Initilize(const std::string & windowTitle, int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "Error initializing SDL." << std::endl;
		return false;
	}
	
	//TODO - Apply SDL_WINDOW_FULLSCREEN in place of 0
	window = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

	if (!window)
	{
		std::cout << "Error creating game window." << std::endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!renderer)
	{
		std::cout << "Error creating renderer." << std::endl;
		return false;
	}

	return true;
}

void Screen::Clear()
{
	SDL_RenderClear(renderer);
}

void Screen::Present()
{
	SDL_RenderPresent(renderer);
}

void Screen::Shutdown()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

SDL_Renderer* Screen::GetRenderer()
{
	return renderer;
}