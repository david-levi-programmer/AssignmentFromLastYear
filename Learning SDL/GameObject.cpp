#include "GameObject.h"

GameObject::GameObject()
{
	m_angle = 0.0f;
	m_isActive = true;
	m_isAlive = true;
	m_isVisible = true;
}

GameObject::~GameObject()
{

}

const std::string& GameObject::GetTag() const
{
	return m_tag;
}

void GameObject::SetTag(const std::string& tag)
{
	m_tag = tag;
}

void GameObject::Update(const Input& input)
{
}

void GameObject::SetPosition(int x, int y)
{
	m_position = { x, y };
}

void GameObject::SetPosition(const Vector2D& position)
{
	m_position = position;
}

const Vector2D& GameObject::GetPosition() const
{
	return m_position;
}

void GameObject::SetSize(int width, int height)
{
	m_size = { width, height };
}

void GameObject::SetSize(const Vector2D& size)
{
	m_size = size;
}

const Vector2D& GameObject::GetSize() const
{
	return m_size;
}

bool GameObject::isAlive() const
{
	return m_isAlive;
}

bool GameObject::isActive() const
{
	return m_isActive;
}

bool GameObject::isVisible() const
{
	return m_isVisible;
}

void GameObject::isAlive(bool flag)
{
	m_isAlive = flag;
}

void GameObject::isActive(bool flag)
{
	m_isActive = flag;
}

void GameObject::isVisible(bool flag)
{
	m_isVisible = flag;
}

void GameObject::SetAngle(float angle)
{
	m_angle = angle;
}

float GameObject::GetAngle() const
{
	return m_angle;
}