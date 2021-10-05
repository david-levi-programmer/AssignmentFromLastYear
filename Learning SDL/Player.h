#pragma once

#include "GameObject.h"
#include "Sprite.h"
#include "Input.h"
#include "Vector2D.h"
#include "Sound.h"
#include "BoxCollide.h"
#include "SphereCollide.h"

class Player : public GameObject //inheritance - player is a game object
{

public:

	enum State
	{
		IDLE,
		RUN,
		JUMP,
		TOTAL_STATES
	};

	enum Direction
	{
		LEFT,
		RIGHT
	};

	enum Jump
	{
		UP,
		DOWN,
		NONE
	};

	Player(Screen& screen);
	~Player();

	void SetSpeed(int speed);
	void SetState(State state);
	//const BoxCollide& GetCollider() const;
	const SphereCollide& GetCollider() const;
	virtual void Render(Screen& screen);
	virtual void Update(Input& input);

private:

	Vector2D m_direction;
	Direction m_facingDirection;
	int m_speed;
	Jump m_jumpDirection;

	Sprite m_image[TOTAL_STATES]; 
	Sound m_footstep;
	State m_state;

	BoxCollide m_collider;
	SphereCollide m_collide;
};