#include <memory>
#include <iostream>
#include <string>
#include <SDL.h>
#include "Game.h"
#include "PlayState.h"

int main(int argc, char* argv[])
{
	std::unique_ptr<Game> game = std::make_unique<Game>();

	if (game->Initialize())
	{
		game->Run(new PlayState);
		game->Shutdown();
	}

	return 0;
}