#pragma once

#include "GameObject.h"
#include "Sprite.h"
#include "BoxCollide.h"
#include "SphereCollide.h"

class Block : public GameObject
{

public:

	Block();
	~Block();

	void SetSpeed(int speed);
	const BoxCollide& GetCollider() const;
	//const SphereCollide& GetCollider() const;
	virtual void Update();
	virtual void Render();

private:

	Sprite m_image;

	int m_speed = 0;
	Vector2D m_direction;
	BoxCollide m_collider;
	//SphereCollide m_collider;
};