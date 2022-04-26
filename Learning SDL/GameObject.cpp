#include "GameObject.h"

const std::string& GameObject::GetTag() const
{
	return m_tag;
}

void GameObject::SetTag(const std::string& tag)
{
	m_tag = tag;
}

void GameObject::SetPosition(int x, int y)
{
	m_position = { x, y };
}

void GameObject::SetPosition(const Vector<int>& position)
{
	m_position = position;
}

const Vector<int>& GameObject::GetPosition() const
{
	return m_position;
}

void GameObject::SetSize(int width, int height)
{
	m_size = { width, height };
}

void GameObject::SetSize(const Vector<int>& size)
{
	m_size = size;
}

const Vector<int>& GameObject::GetSize() const
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