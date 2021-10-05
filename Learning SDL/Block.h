#pragma once

#include "GameObject.h"
#include "Sprite.h"
#include "BoxCollide.h"
#include "SphereCollide.h"

class Block : public GameObject
{
public:

	Block(Screen& screen);
	~Block();

	void SetSpeed(int speed);
	//const BoxCollide& GetCollider() const;
	const SphereCollide& GetCollider() const;
	virtual void Update(Input& input);
	virtual void Render(Screen& screen);

private:

	Sprite m_image;

	int m_speed;
	Vector2D m_direction;
	//BoxCollide m_collider;
	SphereCollide m_collider;
};