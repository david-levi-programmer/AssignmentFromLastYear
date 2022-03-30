#include <iostream>
#include <SDL_image.h>

#include "Sprite.h"

Sprite::Sprite() 
{
	m_image = nullptr;
	m_animationSpeed = 0.0f;

	m_isAnimated = false;
	m_isAnimationDone = false;
	m_isLooping = false;

	m_celDimension = { 0, 0 };
	m_imageDimension = { 0, 0 };
	m_spriteDimension = { 0, 0 };
}

void Sprite::IsAnimated(bool flag)
{
	m_isAnimated = flag;
}

void Sprite::IsLooping(bool flag)
{
	m_isLooping = flag;
}

void Sprite::SetImageCel(int column, int row)
{
	m_imageCel = (((row - 1) * m_imageDimension.x) + (column + 1));
}

void Sprite::SetAnimationSpeed(float speed)
{
	m_animationSpeed = speed;
}

void Sprite::SetSpriteDimension(int width, int height)
{
	m_spriteDimension.x = width;
	m_spriteDimension.y = height;
}

void Sprite::SetImageDimension(int columns, int rows, int width, int height)
{
	m_imageDimension.x = width;
	m_imageDimension.y = height;

	m_celDimension.x = width / columns;
	m_celDimension.y = height / rows;
}

bool Sprite::Load(const std::string& filename)
{
	SDL_Surface* rawImageData = IMG_Load(filename.c_str());

	if (!rawImageData)
	{
		std::cout << "Error loading image file." << std::endl;
		return false;
	}

	m_image = SDL_CreateTextureFromSurface(Screen::Instance()->GetRenderer(), rawImageData);

	return true;
}

void Sprite::Unload()
{
	SDL_DestroyTexture(m_image);
}

void Sprite::Update()
{
	if (m_isAnimated)
	{
		static float total = 0.0f;
		total += 0.1;

		m_imageCel = static_cast<int>(total *= m_animationSpeed) % (m_imageDimension.x * m_imageDimension.y);
	
		if (!m_isLooping && m_imageCel == (m_imageDimension.x * m_imageDimension.y - 1))
		{
			m_isAnimationDone = true;
		}
	}
}

void Sprite::Render(int xPos, int yPos, double angle, Flip flip)
{
	if (!m_isAnimationDone)
	{
		SDL_Rect sourceRect;
		SDL_Rect targetRect;

		sourceRect.x = (m_imageCel % m_imageDimension.x) * m_celDimension.x;
		sourceRect.y = (m_imageCel / m_imageDimension.x) * m_celDimension.y;
		sourceRect.w = m_imageDimension.x;
		sourceRect.h = m_imageDimension.y;

		targetRect.x = xPos;
		targetRect.y = yPos;
		targetRect.w = m_spriteDimension.x;
		targetRect.h = m_spriteDimension.y;

		SDL_Point centre{ m_spriteDimension.x * 0.5f, m_spriteDimension.y * 0.5f };

		SDL_RenderCopyEx(Screen::Instance()->GetRenderer(), m_image, &sourceRect, &targetRect, angle, &centre, static_cast<SDL_RendererFlip>(flip));
	}
}