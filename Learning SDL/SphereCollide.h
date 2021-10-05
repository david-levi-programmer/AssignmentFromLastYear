#pragma once

#include "Vector2D.h"
class SphereCollide
{


public:

	SphereCollide();

	void SetPosition(int x, int y);
	void SetRadius(int radius);

	bool IsColliding(const SphereCollide& secondBox) const;

private:

	int m_radius;
	Vector2D m_position;

};

