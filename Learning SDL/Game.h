#pragma once

#include <memory>
#include <iostream>
#include <string>
#include "State.h"

class Game
{

public:

	Game(State* initialState);
	bool Initialize();
	bool Run();
	void Shutdown();

private:

	std::unique_ptr<State> m_gameState;

};