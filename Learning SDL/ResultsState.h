#pragma once

#include "State.h"
#include "WinState.h"

class ResultsState : public State
{


public:

	bool OnEnter() override;
	State* Update() override;
	bool Render() override;
	void OnExit() override;

private:

	Sprite m_background;
	Text m_text;
	Music m_music;

};