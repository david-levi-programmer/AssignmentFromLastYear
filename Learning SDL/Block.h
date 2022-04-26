#pragma once

#include "GameObject.h"
#include "Sprite.h"
#include "BoxCollide.h"

class Block : public GameObject
{

public:

	Block();
	~Block();

	void SetSpeed(int speed);
	const BoxCollide& GetCollider() const;
	virtual void Update();
	virtual void Render();

private:

	Sprite m_image;

	int m_speed = 0;
	Vector<int> m_direction;
	BoxCollide m_collider;

};