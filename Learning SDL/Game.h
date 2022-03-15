#pragma once

#include <memory>
#include <iostream>
#include <string>

#include "Screen.h"
#include "State.h"

class Game
{

public:

	Game(State* initialState);
	bool Initialize();
	bool Run();
	void Shutdown();

	static Screen& GetScreen() 
	{
		return m_screen;
	}

private:

	std::unique_ptr<State> m_gameState;
	static Screen m_screen;
	//static Input m_input;
};