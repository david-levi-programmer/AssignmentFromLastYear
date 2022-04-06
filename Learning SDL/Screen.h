#pragma once
#include <string>
#include <SDL.h>
#include "Vector2D.h"

class Screen
{

public:

	static Screen* Instance();

	bool Initilize(const std::string& windowTitle, int width, int height);
	void Clear();
	void Present();
	void Shutdown();

	Vector2D GetResolution();
	SDL_Renderer* GetRenderer();

private:

	Screen() {}
	Screen(const Screen&) {}
	Screen& operator=(const Screen&) {}
	
	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;

	Vector2D m_size;

};