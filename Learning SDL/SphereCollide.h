#pragma once

#include "Vector.h"
class SphereCollide
{

public:

	SphereCollide();

	void SetPosition(int x, int y);
	void SetRadius(int radius);

	bool IsColliding(const SphereCollide& secondBox) const;

private:

	int m_radius = 0;
	Vector<int> m_position;

};