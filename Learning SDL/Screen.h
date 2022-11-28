#pragma once

#include <string>
#include <SDL.h>
#include "Vector.h"

class Screen
{

public:

	static Screen* Instance();

	bool Initilize(const std::string& windowTitle, int width, int height);
	void Clear();
	void Present();
	void Shutdown();

	Vector<int> GetResolution();
	SDL_Renderer* GetRenderer();

private:

	Screen() {}
	Screen(const Screen&) {}
	Screen& operator=(const Screen&) {}
	
	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;

	Vector<int> m_size;

};