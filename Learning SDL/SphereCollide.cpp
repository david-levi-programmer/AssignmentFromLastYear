#include "SphereCollide.h"

SphereCollide::SphereCollide()
{

}

void SphereCollide::SetPosition(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
}

void SphereCollide::SetRadius(int radius)
{
	m_radius = radius;
}

bool SphereCollide::IsColliding(const SphereCollide& secondBox) const
{
	Vector2D centerPointA = Vector2D(m_position.x + m_radius, m_position.y + m_radius);
	Vector2D centerPointB = Vector2D(secondBox.m_position.x + m_radius, secondBox.m_position.y + m_radius);
	
	int distanceBetweenPoints = centerPointA.Distance(centerPointB);

	return (distanceBetweenPoints <= (m_radius + secondBox.m_radius));
}