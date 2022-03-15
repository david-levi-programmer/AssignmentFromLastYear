#include "Game.h"
#include "Input.h"
#include "Main.h"
#include "Music.h"
#include "Text.h"

Screen Game::m_screen;

Game::Game(State* initialState)
{
    m_gameState.reset(initialState);
}

bool Game::Initialize()
{
	Music music;
	Text font;
	Screen screen;

    if (!m_screen.Initilize("My game", 1280, 720))
    {
        return 0;
    }
    
    return true;
}

bool Game::Run()
{
    m_gameState->OnEnter();

    while (m_gameState)
    {
		//screen.Clear();

		Input input;

		input.Update();
		
		State* nextState = m_gameState->Update();

        m_gameState->Render();

        if (nextState != m_gameState.get())
        {
            m_gameState->OnExit();
            m_gameState.reset(nextState);

            if (m_gameState)
            {
                m_gameState->OnEnter();
            }
        }
    }
    
    return true;
}

void Game::Shutdown()
{
	Music::Shutdown();
	Text::Shutdown();
	//screen.Shutdown();
}