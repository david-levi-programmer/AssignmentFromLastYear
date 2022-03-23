#include "Player.h"
#include "Input.h"
#include "Screen.h"

Player::Player()
{
	m_image[IDLE].Load("Assets/Images/Adventure_boy_idle.png"); //downloaded for free from OpenGameArt.org
	for (int i = 0; i < TOTAL_STATES; i++)
	{
		m_image[i].SetSpriteDimension(5880, 600);
		m_image[i].SetImageDimension(10, 1, 5880, 600);

		m_image[i].IsAnimated(true);
		m_image[i].SetAnimationSpeed(3.5f);

		if (i == JUMP)
		{
			m_image[i].IsLooping(false);
		}

		else
		{
			m_image[i].IsLooping(true);
		}
	}

	//m_footstep.Load("Assets/Audio/Sounds/Footsteps.wav");
}

Player::~Player()
{
	m_image[m_state].Unload();
}

void Player::SetSpeed(int speed)
{
	m_speed = speed;
}

void Player::SetState(State state)
{
	m_state = state;
}

const BoxCollide& Player::GetCollider() const
{
	return m_collider;
}

/*const SphereCollide& Player::GetCollider() const
{
	return m_collide;
}*/

void Player::Render()
{
	if (m_isVisible)
	{
		if (m_facingDirection == RIGHT)
		{
			m_image[m_state].Render(m_position.x, m_position.y, m_angle, Sprite::NO_FLIP);
		}

		else
		{
			m_image[m_state].Render(m_position.x, m_position.y, m_angle, Sprite::HORZ_FLIP);
		}
	}
}

void Player::Update()
{
	//==========================Key Inputs============================
	if (Input::Instance()->GetKeyDown() == SDL_SCANCODE_LEFT)
	{
		m_state = RUN;
		m_facingDirection = LEFT;
		m_footstep.Play();
	}

	else if (Input::Instance()->GetKeyDown() == SDL_SCANCODE_RIGHT)
	{
		m_state = RUN;
		m_facingDirection = RIGHT;
		m_footstep.Play();
	}

	else if (Input::Instance()->GetKeyDown() == SDLK_SPACE)
	{
		m_state = JUMP;
		m_jumpDirection = UP;
	}
	
	else
	{
		m_direction.x = 0;
		m_direction.y = 0;
		m_state = IDLE;
	}

	//==============================Checks=================================

	if (m_state == RUN)
	{
		if(m_facingDirection == LEFT)
		{
			m_direction.x = -1;
			m_direction.y = 0;
		}

		else
		{
			m_direction.x = 1;
			m_direction.y = 0;
		}
	}

	else if (m_state == JUMP)
	{
		if (m_position.y >= 20 && m_jumpDirection == UP)
		{
			m_direction.x = 0;
			m_direction.y = -1;
		}

		else
		{
			m_direction.x = 0;
			m_direction.y = 1;
			m_jumpDirection = DOWN;
		}
	}

	//=====================================================================

	m_direction = m_direction.Scale(m_speed);
	m_position = m_position.Add(m_direction);

	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.SetDimension(m_size.x, m_size.y);
	m_collider.Update();

	m_image[m_state].Update();

	/*m_collide.SetRadius(m_size.x / 2);
	m_collide.SetPosition(m_position.x, m_position.y);*/
}