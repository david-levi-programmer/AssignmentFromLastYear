#include "Block.h"

Block::Block()
{
	m_image.Load("Assets/Images/stone.png");
	m_image.SetSpriteDimension(100, 100);
	m_image.SetImageDimension(1, 1, 96, 96);
}

Block::~Block()
{
	m_image.Unload();
}

void Block::SetSpeed(int speed)
{
	m_speed = speed;
}

const BoxCollider& Block::GetCollider() const
{
	return m_collider;
}

void Block::Update()
{
	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.SetDimension(m_size.x, m_size.y);
	m_collider.Update();
}

void Block::Render()
{
	m_image.Render(m_position.x, m_position.y, m_angle);
}