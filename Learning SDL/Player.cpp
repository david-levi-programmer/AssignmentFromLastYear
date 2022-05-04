#include "Player.h"

Player::Player()
{
	/*auto setSprite = [&](State playerState, const std::string& filename, int columns, int rows, int width, int height)
	{
		m_image[static_cast<unsigned int>(Player::State::TotalStates)].Load(filename);
		m_image[static_cast<unsigned int>(Player::State::TotalStates)].SetSpriteDimension(width, height);
		m_image[static_cast<unsigned int>(Player::State::TotalStates)].SetImageDimension(columns, rows, width, height);
	};*/

	m_image[static_cast<unsigned int>(Player::State::Idle)].Load("Assets/Images/protag_idle.png"); //cropped from a sprite downloaded for free from OpenGameArt.org
	m_image[static_cast<unsigned int>(Player::State::Run)].Load("Assets/Images/protag_run.png");
	m_image[static_cast<unsigned int>(Player::State::Jump)].Load("Assets/Images/protag_jump.png");

	m_image[static_cast<unsigned int>(Player::State::Idle)].SetSpriteDimension(100, 100);
	m_image[static_cast<unsigned int>(Player::State::Idle)].SetImageDimension(8, 1, 160, 24);

	m_image[static_cast<unsigned int>(Player::State::Run)].SetSpriteDimension(100, 100);
	m_image[static_cast<unsigned int>(Player::State::Run)].SetImageDimension(6, 1, 120, 24);

	m_image[static_cast<unsigned int>(Player::State::Jump)].SetSpriteDimension(100, 100);
	m_image[static_cast<unsigned int>(Player::State::Jump)].SetImageDimension(8, 1, 158, 24);


	for (int i = 0; i < static_cast<unsigned int>(Player::State::TotalStates); i++)
	{
		m_image[i].IsAnimated(true);
		m_image[i].SetAnimationSpeed(1.0f);
		m_image[i].IsLooping(true);
	}

	m_footstep.Load("Assets/Audio/Sounds/Footsteps.wav");

	m_heightLimit = 300;
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

void Player::Render()
{
	m_isVisible = true;

	if (m_isVisible)
	{
		if (m_facingDirection == Vector<int>::Right)
		{
			m_image[static_cast<unsigned int>(m_state)].Render(m_position.x, m_position.y, m_angle, Sprite::Flip::NoFlip);
		}

		else
		{
			m_image[static_cast<unsigned int>(m_state)].Render(m_position.x, m_position.y, m_angle, Sprite::Flip::HorzFlip);
		}
	}
}

void Player::Update()
{
	//==========================Key Inputs============================
	if (Input::Instance()->IsKeyPressed(HM_KEY_LEFT) && m_state != State::Jump)
	{
		m_state = Player::State::Run;
		m_facingDirection = Vector<int>::Left;
		m_footstep.Play();
	}

	else if (Input::Instance()->IsKeyPressed(HM_KEY_RIGHT) && m_state != State::Jump)
	{
		m_state = Player::State::Run;
		m_facingDirection = Vector<int>::Right;
		m_footstep.Play();
	}

	else if (Input::Instance()->IsKeyPressed(HM_KEY_SPACE))
	{
		m_state = Player::State::Jump;
		m_jumpDirection = Vector<int>::Up;
	}

	else if(m_state != State::Jump)
	{
		m_direction = Vector<int>::Zero;
		m_state = Player::State::Idle;
	}

	//==============================Checks=================================

	if (m_state == Player::State::Run)
	{
		m_direction = m_facingDirection;
	}

	else if (m_state == Player::State::Jump && m_jumpDirection != Vector<int>::Down)
	{
		m_jumpDirection = Vector<int>::Up;

		if (Input::Instance()->IsKeyPressed(HM_KEY_LEFT))
		{
			m_facingDirection = Vector<int>::Left;
			m_direction = m_facingDirection;
		}

		if (Input::Instance()->IsKeyPressed(HM_KEY_RIGHT))
		{
			m_facingDirection = Vector<int>::Right;
			m_direction = m_facingDirection;
		}

		if (m_position.y == m_heightLimit)
		{
			m_jumpDirection = Vector<int>::Down;
		}
	}

	else if (m_state == Player::State::Jump && m_jumpDirection == Vector<int>::Down)
	{
		if (Input::Instance()->IsKeyPressed(HM_KEY_LEFT))
		{
			m_facingDirection = Vector<int>::Left;
			m_direction = m_facingDirection;
		}

		if (Input::Instance()->IsKeyPressed(HM_KEY_RIGHT))
		{
			m_facingDirection = Vector<int>::Right;
			m_direction = m_facingDirection;
		}

		if (m_position.y >= 520)
		{
			m_state = State::Idle;
			m_jumpDirection = Vector<int>::Zero;
		}
	}

	//=====================================================================

	m_position = m_position + (m_direction * m_speed);
	m_position = m_position + (m_jumpDirection * m_speed);

	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.SetDimension(m_size.x, m_size.y);
	m_collider.Update();

	m_image[static_cast<unsigned int>(m_state)].Update();
}