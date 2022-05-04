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
	m_size.x = width;
	m_size.y = height;

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "Error initializing SDL." << std::endl;
		return false;
	}
	
	//TODO - Apply SDL_WINDOW_FULLSCREEN
	m_window = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);

	if (!m_window)
	{
		std::cout << "Error creating game window." << std::endl;
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!m_renderer)
	{
		std::cout << "Error creating renderer." << std::endl;
		return false;
	}

	return true;
}

void Screen::Clear()
{
	SDL_RenderClear(m_renderer);
}

void Screen::Present()
{
	SDL_RenderPresent(m_renderer);
}

void Screen::Shutdown()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

Vector<int> Screen::GetResolution()
{
	//SDL_GetWindowSize(m_window, &m_size.x, &m_size.y);
	return m_size;
}

SDL_Renderer* Screen::GetRenderer()
{
	return m_renderer;
}