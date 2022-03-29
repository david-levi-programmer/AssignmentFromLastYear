#pragma once
#include <string>
#include <SDL.h>
class Screen
{

public:

	static Screen* Instance();

	bool Initilize(const std::string& windowTitle = "CU5011 Assignment 3", int width = 1280, int height = 720);
	void Clear();
	void Present();
	void Shutdown();

	SDL_Renderer* GetRenderer();

private:

	Screen() {}
	Screen(const Screen&) {}
	Screen& operator=(const Screen&) {}
	
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

};