#pragma once

#include <string>
#include <SDL.h>

#include "Screen.h"

class Sprite
{

public:

	enum Flip
	{
		NO_FLIP = SDL_FLIP_NONE,
		HORZ_FLIP = SDL_FLIP_HORIZONTAL,
		VERT_FLIP = SDL_FLIP_VERTICAL
	};

	Sprite();
	~Sprite() {}

	void IsAnimated(bool flag);
	void IsLooping(bool flag);

	void SetImageCel(int column, int row);
	void SetAnimationSpeed(float speed);
	void SetSpriteDimension(int width, int height);
	void SetImageDimension(int columns, int rows, int width, int height);

	bool Load(const std::string& filename);
	void Unload();

	void Update();
	void Render(int xPos, int yPos, double angle, Flip flip = NO_FLIP);

private:

	int m_imageCel{ 0 };
	float m_animationSpeed = 0.0f;

	bool m_isAnimated;
	bool m_isAnimationDone;
	bool m_isLooping;

	Flip m_imageFlip;
	SDL_Texture* m_image;
	SDL_Point m_celDimension ;
	SDL_Point m_imageDimension ;
	SDL_Point m_spriteDimension;

};