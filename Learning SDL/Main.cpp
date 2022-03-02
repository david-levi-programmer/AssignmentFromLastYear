#include <memory>
#include <iostream>
#include <string>
#include <SDL.h>
#include "Game.h"
#include "State.h"

bool IsGameRunning = true;

int main(int argc, char* argv[])
{
	std::unique_ptr<Game> game = std::make_unique<Game>(new MenuState);

	if (game->Initialize())
	{
		game->Run();
		game->Shutdown();
	}

	system("pause");
	return 0;
}