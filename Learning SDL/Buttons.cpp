#include "Buttons.h"

Buttons::Buttons(const std::string& filename)
{
	m_mousePosition = { 0, 0, 0, 0 };
	m_spritePosition = { 0, 0, 0, 0 };
	SetTag(filename);
	m_image.Load("/Assets/Images/Buttons/Highlighted/Play.png");
	m_image.SetImageDimension(1, 1, 716, 160);
	//TODO - Download button sfx
}

const Buttons::Status& Buttons::GetState() const
{
	return m_buttonState;
}

void Buttons::Shutdown()
{
	m_image.Unload();
}

void Buttons::Update()
{
	m_image.SetImageCel(1, 1);
	m_spritePosition.x = this->GetPosition().x;
	m_spritePosition.y = this->GetPosition().y;

	m_spritePosition.w = m_image.GetSpriteDimension().x;
	m_spritePosition.h = m_image.GetSpriteDimension().y;


}

void Buttons::Render()
{

}