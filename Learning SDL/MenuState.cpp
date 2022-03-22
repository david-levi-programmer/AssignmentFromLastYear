#include "MenuState.h"

bool MenuState::OnEnter()
{
	return true;
}

State* MenuState::Update()
{
	if (Input::Instance()->ClosedWindow())
	{
		return nullptr;
	}

	if (Input::Instance()->GetKeyDown() == SDLK_ESCAPE)
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