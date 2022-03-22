#pragma once
#include "State.h"
#include "Input.h"

class MenuState : public State
{
	
public:

	MenuState() {}
	~MenuState() override {}

	bool OnEnter() override;
	State* Update() override;
	bool Render() override;
	void OnExit() override;
};