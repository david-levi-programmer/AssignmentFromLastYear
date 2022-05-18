#include "Timer.h"

Timer::Timer()
{
    m_text.Load("Assets/Images/nevis.ttf", 100); //downloaded for free
    m_text.SetColor(0, 0, 0, 255);
    m_text.SetDimension(75, 75);
}

Timer::~Timer()
{
    m_text.Unload();
}

void Timer::SetTimer(int time)
{
    m_time = time;
    m_text.SetText(std::to_string(m_time));
}

void Timer::Render()
{
    SetTimer(m_time);
    m_text.Render(50, 50);
}

void Timer::UpdateTime()
{
    m_pastTick = m_currentTick;
    m_currentTick = SDL_GetTicks();
}

float Timer::GetDTime()
{
    return 0.0f;
}