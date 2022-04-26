#pragma once

#include "GameObject.h"
#include "Sprite.h"
#include "Input.h"
#include "Vector.h"
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
		TotalStates
	};

	/*enum class Direction
	{
		Left,
		Right
	};*/

	/*enum class Jump
	{
		Up,
		Down,
		None
	};*/

	Player();
	~Player();

	void SetSpeed(int speed);
	void SetState(State state);
	const BoxCollide& GetCollider() const;
	//const SphereCollide& GetCollider() const;
	virtual void Render();
	virtual void Update();

private:

	Vector<int> m_direction;
	Vector<int> m_facingDirection;
	//Direction m_facingDirection = Player::Direction::Right;
	int m_speed = 0;
	
	//Jump m_jumpDirection = Player::Jump::None;
	Vector<int> m_jumpDirection = Vector<int>::Zero;
	
	int m_heightLimit;

	Sprite m_image[static_cast<unsigned int>(Player::State::TotalStates)]; 
	Sound m_footstep;
	State m_state = Player::State::Idle;

	BoxCollide m_collider;
	//SphereCollide m_collide;
};