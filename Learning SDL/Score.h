#pragma once
#include "GameObject.h"
#include "Text.h"
#include "Timer.h"
#include "Sound.h"

class Score : public GameObject
{

public:

	Score();
	~Score();

	void SetScore(int score);
	void AddtoScore();
	bool VictoryCheck();

	virtual void Update() {}
	virtual void Render();

private:

	int m_score = 0;
	Text m_text;
	Timer m_time;
	Sound m_sound;

};