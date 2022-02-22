#pragma once
#include <string>
#include <SDL.h>
class Screen
{

public:

	Screen();

	bool Initilize(const std::string& windowTitle = "Assignment 3", int width = 1280, int height = 720);
	void Clear();
	void Present();
	void Shutdown();

	SDL_Renderer* GetRenderer();

private:

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

};