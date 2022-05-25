#include "MenuState.h"

bool MenuState::OnEnter()
{
	m_background.Load("Assets/Images/MysteryCave.jpg"); //Downloaded from Vecteezy
	m_background.SetSpriteDimension(1280, 720);
	m_background.SetImageDimension(1, 1, 1920, 696);

	m_text.Load("Assets/Images/nevis.ttf", 100); //downloaded for free
	m_text.SetColor(0, 0, 0, 255);
	m_text.SetDimension(1000, 100);
	m_text.SetText("Press ENTER to go into THE 3rd SECOND");

	return true;
}

State* MenuState::Update()
{
	if (Input::Instance()->IsWindowClosed())
	{
		return nullptr;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_RETURN))
	{
		return new PlayState;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE))
	{
		return nullptr;
	}
	
	return this;
}

bool MenuState::Render()
{
	m_background.Render(0, 0, 0.0);

	m_text.Render(150, 300);
	
	return true;
}

void MenuState::OnExit()
{
	Music::Shutdown();
	m_text.Unload();
}