#pragma once
#include "GameObject.h"
#include "Text.h"

class Timer : public GameObject
{

public:

	Timer();
	~Timer();

	void SetTimer(int time);

	virtual void Update() {}
	virtual void Render();

	static void UpdateTime();
	static float GetDTime();

private:

	static unsigned int m_pastTick;
	static unsigned int m_currentTick;
	Text m_text;
	int m_time = 0;

};