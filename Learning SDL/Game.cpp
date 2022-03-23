#include "Game.h"
#include "Input.h"
#include "Main.h"
#include "Music.h"
#include "Text.h"
#include "Sprite.h"

Game::Game(State* initialState)
{
    m_gameState.reset(initialState);
}

bool Game::Initialize()
{
    if (!Screen::Instance()->Initilize("The 3rd Second", 1280, 720))
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
		Screen::Instance()->Clear();
		Input::Instance()->Update();
		
		State* nextState = m_gameState->Update();

        m_gameState->Render();

		Screen::Instance()->Present();

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
	Screen::Instance()->Shutdown();
}