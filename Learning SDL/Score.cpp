#include "Score.h"

Score::Score()
{
	m_text.Load("../Assets/Fonts/homeAwayRegular.otf", 100); //downloaded for free
	m_text.SetColor(255, 0, 0, 255);
	m_text.SetDimension(175, 50);
}

Score::~Score()
{
	m_text.Unload();
}

void Score::SetScore(int score)
{
	m_score = score;
	m_text.SetText(std::to_string(m_score));
}

void Score::Render()
{
	m_text.Render(10, 10);
}