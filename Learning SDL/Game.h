#pragma once

#include <memory>
#include <iostream>
#include <string>

#include "Input.h"
#include "Music.h"
#include "Screen.h"
#include "State.h"
#include "Text.h"

class Game
{

public:

	//Game(State* initialState);
	bool Initialize();
	bool Run(State* initialState);
	void Shutdown();

private:

	std::unique_ptr<State> m_gameState;
};