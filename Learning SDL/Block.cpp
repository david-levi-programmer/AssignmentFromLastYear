#include "Block.h"

Block::Block(Screen& screen)
{
	m_image.Load("Assets/Images/Objects.png", screen);
	m_image.SetSpriteDimension(100, 100);
	m_image.SetImageDimension(2, 2, 600, 318);
	m_image.SetImageCel(2, 2);
}

Block::~Block()
{
	m_image.Unload();
}

void Block::SetSpeed(int speed)
{
	m_speed = speed;
}

const BoxCollide& Block::GetCollider() const
{
	return m_collider;
}

/*const SphereCollide& Block::GetCollider() const
{
	return m_collider;
}*/

void Block::Update(Input& input)
{
	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.SetDimension(m_size.x, m_size.y);
	m_collider.Update();
	/*m_collider.SetRadius(m_size.x / 2);
	m_collider.SetPosition(m_position.x, m_position.y);*/
}

void Block::Render(Screen& screen)
{
	m_image.Render(m_position.x, m_position.y, m_angle, screen);
}