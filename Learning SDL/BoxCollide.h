#pragma once

#include "Vector.h"

class BoxCollide
{

public:

	void SetPosition(int x, int y);
	void SetDimension(int width, int height);

	void Update();
	bool IsColliding(const BoxCollide& secondBox) const;

private:

	Vector<int> m_min;
	Vector<int> m_max;
	Vector<int> m_position;
	Vector<int> m_dimension;

};