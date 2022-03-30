#include "Player.h"

Player::Player()
{
	m_image[static_cast<unsigned int>(Player::State::Idle)].Load("../Assets/Images/protag.png"); //downloaded for free from OpenGameArt.org
	for (int i = 0; i < static_cast<unsigned int>(Player::State::Total_States); i++)
	{
		m_image[i].SetSpriteDimension(100, 100);
		m_image[i].SetImageDimension(22, 1, 440, 24);

		m_image[i].IsAnimated(true);
		m_image[i].SetAnimationSpeed(3.5f);

		if (i == static_cast<unsigned int>(Player::State::Jump))
		{
			m_image[i].IsLooping(false);
		}

		else
		{
			m_image[i].IsLooping(true);
		}
	}

	m_footstep.Load("Assets/Audio/Sounds/Footsteps.wav");
}

Player::~Player()
{
	m_image[static_cast<unsigned int>(m_state)].Unload();
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
	m_isVisible = true;
	
	if (m_isVisible)
	{
		if (m_facingDirection == Player::Direction::Right)
		{
			m_image[static_cast<unsigned int>(m_state)].Render(m_position.x, m_position.y, m_angle, Sprite::Flip::NO_FLIP);
		}

		else
		{
			m_image[static_cast<unsigned int>(m_state)].Render(m_position.x, m_position.y, m_angle, Sprite::Flip::HORZ_FLIP);
		}
	}
}

void Player::Update()
{
	//==========================Key Inputs============================
	if (Input::Instance()->GetKeyDown() == SDL_SCANCODE_LEFT)
	{
		m_state = Player::State::Run;
		m_facingDirection = Player::Direction::Left;
		m_footstep.Play();
	}

	else if (Input::Instance()->GetKeyDown() == SDL_SCANCODE_RIGHT)
	{
		m_state = Player::State::Run;
		m_facingDirection = Player::Direction::Right;
		m_footstep.Play();
	}

	else if (Input::Instance()->GetKeyDown() == SDLK_SPACE)
	{
		m_state = Player::State::Jump;
		m_jumpDirection = Player::Jump::Up;
	}
	
	else
	{
		m_direction.x = 0;
		m_direction.y = 0;
		m_state = Player::State::Idle;
	}

	//==============================Checks=================================

	if (m_state == Player::State::Run)
	{
		if(m_facingDirection == Player::Direction::Left)
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

	else if (m_state == Player::State::Jump)
	{
		if (m_position.y >= 20 && m_jumpDirection == Player::Jump::Up)
		{
			m_direction.x = 0;
			m_direction.y = -1;
		}

		else
		{
			m_direction.x = 0;
			m_direction.y = 1;
			m_jumpDirection = Player::Jump::Down;
		}
	}

	//=====================================================================

	m_direction = m_direction.Scale(m_speed);
	m_position = m_position.Add(m_direction);

	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.SetDimension(m_size.x, m_size.y);
	m_collider.Update();

	m_image[static_cast<unsigned int>(m_state)].Update();

	/*m_collide.SetRadius(m_size.x / 2);
	m_collide.SetPosition(m_position.x, m_position.y);*/
}