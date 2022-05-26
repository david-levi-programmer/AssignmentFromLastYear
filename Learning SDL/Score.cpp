#include "Score.h"

Score::Score()
{
	m_text.Load("Assets/Images/nevis.ttf", 100); //downloaded for free
	m_text.SetColor(0, 0, 0, 255);
	m_text.SetDimension(75, 75);

	m_sound.Load("Assets/Audio/Sounds/Coin.wav"); //Downloaded from Freesound.org
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

void Score::AddtoScore()
{
	m_score = m_score + 1;
	m_sound.Play(0);
}

bool Score::VictoryCheck()
{
	if (m_score == 35)
	{
		return true;
	}
}

void Score::Render()
{
	SetScore(m_score);
	m_text.Render(10, 10);
}