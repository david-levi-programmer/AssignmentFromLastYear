#include "Input.h"

Input* Input::Instance()
{
	static Input* input = new Input;
	return input;
}

char Input::GetKeyUp()
{
    return m_keyUp;
}

char Input::GetKeyDown()
{
    return m_keyDown;
}

int Input::GetMouseButtonDown()
{
    return m_mouseButtonDown;
}

int Input::GetMouseButtonUp()
{
    return m_mouseButtonUp;
}

bool Input::KeyPress()
{
    return m_KeyPress;
}

bool Input::MouseClick()
{
    return m_MouseClick;
}

bool Input::ClosedWindow()
{
    return m_ClosedWindow;
}

const MousePos& Input::GetMousePosition()
{
    return m_mousePosition;
}

void Input::Update()
{
    SDL_Event events;

    while(SDL_PollEvent(&events))
    {
        if (events.type == SDL_QUIT)
        {
            m_ClosedWindow = true;
        }

        else if (events.type == SDL_KEYDOWN)
        {
            m_KeyPress = true;
            m_keyDown = events.key.keysym.sym;
        }

        else if (events.type == SDL_KEYUP)
        {
            m_KeyPress = false;
            m_keyUp = events.key.keysym.sym;
        }

        else if (events.type == SDL_MOUSEBUTTONDOWN)
        {
            m_MouseClick = true;
            m_mouseButtonDown = events.button.button;
        }

        else if (events.type == SDL_MOUSEBUTTONUP)
        {
            m_MouseClick = false;
            m_mouseButtonUp = events.button.button;
        }

        else if (events.type == SDL_MOUSEMOTION)
        {
            m_mousePosition.x = events.motion.x;
            m_mousePosition.y = events.motion.y;
        }
    }
}