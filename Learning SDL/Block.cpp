#include "Block.h"

Block::Block()
{
	m_image.Load("Assets/Images/obj_stoneblock001.png");
	m_image.SetSpriteDimension(1280, 720);
	m_image.SetImageDimension(1, 1, 96, 96);
	//m_image.SetImageCel(2, 2);
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