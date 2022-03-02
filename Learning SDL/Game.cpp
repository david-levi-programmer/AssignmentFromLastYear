#include "Game.h"
#include "Screen.h"
#include "Input.h"
#include "Main.h"
#include "Player.h"
#include "Vector2D.h"
#include "Block.h"
#include "Music.h"
#include "Text.h"
#include "Score.h"
#include "BoxCollide.h"

Game::Game(State* initialState)
{
    m_gameState.reset(initialState);
}

bool Game::Initialize()
{
    Screen screen;
    Input input;
    Music::Initialize(); // only called once before music is loaded
    Text::Initialize();
    Sprite background;

    if (!screen.Initilize("My game", 1280, 720))
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
}
