#include "MenuState.h"

bool MenuState::OnEnter()
{
	return true;
}

State* MenuState::Update()
{
	if (Input::Instance()->IsWindowClosed())
	{
		return nullptr;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE))
	{
		return nullptr;
	}
	
	return this;
}

bool MenuState::Render()
{
	return true;
}

void MenuState::OnExit()
{

}