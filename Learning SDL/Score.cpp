#include "Score.h"

Score::Score()
{
	m_score = 0;
	m_text.Load("Assets/Fonts/home-away.regular.otf", 100); //downloaded for free
	m_text.SetColor(255, 0, 0, 255);
	m_text.SetDimension(175, 50);
}

Score::~Score()
{
	m_text.UnLoad();
}

void Score::SetScore(int score)
{
	m_score = score;
	m_text.SetText(std::to_string(m_score));
}

void Score::Render(Screen& screen)
{
	m_text.Render(10, 10, screen);
}
