#pragma once
#include "GameObject.h"
#include "BoxCollider.h"
#include "Sprite.h"

class Coin : public GameObject
{

public:

	Coin();
	~Coin();

	const BoxCollider& GetCollider() const;
	virtual void Update();
	virtual void Render();
	void Collected();

private:

	Sprite m_image;
	BoxCollider m_collider;

};