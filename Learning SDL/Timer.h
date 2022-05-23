#pragma once
#include "GameObject.h"
#include "Text.h"

class Timer : public GameObject
{

public:

	Timer();
	~Timer();

	void SetTimer(int time);

	void Update();
	virtual void Render();

private:

	Text m_text;
	float m_time = 0;
	Uint32 start = 0;
	Uint32 end = 0;
	float seconds = 0;

};