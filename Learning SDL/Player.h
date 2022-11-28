#pragma once

#include <iostream>
#include "GameObject.h"
#include "Sprite.h"
#include "Input.h"
#include "Vector.h"
#include "BoxCollider.h"
#include "Sound.h"

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

	Player();
	~Player();

	void SetSpeed(int speed);
	void SetState(State state);
	const BoxCollider& GetCollider() const;
	SDL_Point GetDimension();
	virtual void Render();
	virtual void Update();

private:

	Vector<int> m_direction;
	Vector<int> m_facingDirection;
	int m_speed = 0;
	
	Vector<int> m_jumpDirection = Vector<int>::Zero;
	
	int m_heightLimit;

	Sprite m_image[static_cast<unsigned int>(Player::State::TotalStates)];
	State m_state = Player::State::Idle;
	Sound m_jump;

	BoxCollider m_collider;

};