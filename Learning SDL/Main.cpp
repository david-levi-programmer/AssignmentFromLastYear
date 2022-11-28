#include <SDL.h>
#include <SDL_net.h>
#include "Game.h"
#include "PlayState.h"
#include "MenuState.h"

int main(int argc, char* argv[])
{
	std::unique_ptr<Game> game = std::make_unique<Game>();

	if (game->Initialize())
	{
		game->Run(new MenuState); //TODO - Set to LobbyState for testing
		game->Shutdown();
	}

	return 0;
}