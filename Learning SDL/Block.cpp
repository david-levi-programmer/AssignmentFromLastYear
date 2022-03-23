#include "Block.h"

Block::Block()
{
	m_image.Load("Assets/Images/Objects.png");
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
	return m_collide;
}*/

void Block::Update()
{
	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.SetDimension(m_size.x, m_size.y);
	m_collider.Update();
	/*m_collide.SetRadius(m_size.x / 2);
	m_collide.SetPosition(m_position.x, m_position.y);*/
}

void Block::Render()
{
	m_image.Render(m_position.x, m_position.y, m_angle);
}