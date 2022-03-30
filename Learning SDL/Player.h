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

	enum class State
	{
		Idle,
		Run,
		Jump,
		Total_States
	};

	enum class Direction
	{
		Left,
		Right
	};

	enum class Jump
	{
		Up,
		Down,
		None
	};

	Player();
	~Player();

	void SetSpeed(int speed);
	void SetState(State state);
	const BoxCollide& GetCollider() const;
	//const SphereCollide& GetCollider() const;
	virtual void Render();
	virtual void Update();

private:

	Vector2D m_direction;
	Direction m_facingDirection = Player::Direction::Right;
	int m_speed = 0;
	Jump m_jumpDirection = Player::Jump::None;

	Sprite m_image[static_cast<unsigned int>(Player::State::Total_States)]; 
	Sound m_footstep;
	State m_state = Player::State::Idle;

	BoxCollide m_collider;
	//SphereCollide m_collide;
};