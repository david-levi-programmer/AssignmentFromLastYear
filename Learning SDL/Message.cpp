#include "Message.h"

Message::Message(const std::string& message)
{
	if (Input::Instance()->IsKeyPressed(HM_KEY_M))
	{
		//TODO - Figure out this stuff out. Or remove it if there's no time.
	}
}

Message::~Message()
{
	m_text.Unload();
}

void Message::SetMessage(std::string message)
{
	m_text.Load("Assets/Images/nevis.ttf", 100); //downloaded for free
	m_text.SetColor(0, 0, 0, 255);
	m_text.SetDimension(75, 75);
	m_text.SetText(message);
}

void Message::Render()
{
	m_text.Render(10, 600);
}