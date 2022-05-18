#include "Game.h"

bool Game::Initialize()
{
    Screen::Instance();
	Text::Initialize();
	Music::Initialize();

    if (!Screen::Instance()->Initilize("The 3rd Second", 1280, 720))
    {
        return 0;
    }
    
    return true;
}

bool Game::Run(State* initialState)
{
    m_gameState.reset(initialState);
    m_gameState->OnEnter();

    while (m_gameState)
    {
		Screen::Instance()->Clear();
		Input::Instance()->Update();
		
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

		Screen::Instance()->Present();
    }
    
    return true;
}

void Game::Shutdown()
{
	Music::Shutdown();
	Text::Shutdown();
	Screen::Instance()->Shutdown();
}