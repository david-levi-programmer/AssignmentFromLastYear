#pragma once

#include "Vector2D.h"

class BoxCollide
{

public:

	void SetPosition(int x, int y);
	void SetDimension(int width, int height);

	void Update();
	bool IsColliding(const BoxCollide& secondBox) const;

private:

	Vector2D m_min;
	Vector2D m_max;
	Vector2D m_position;
	Vector2D m_dimension;

};