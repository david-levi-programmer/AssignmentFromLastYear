#include <iostream>
#include "Text.h"

bool Text::Initialize()
{
	if (TTF_Init() == -1)
	{
		std::cout << "Error initializing font system." << std::endl;
		return false;
	}

	return true;
}

void Text::Shutdown()
{
	TTF_Quit();
}

Text::Text()
{
	m_texture = nullptr;
	m_font = nullptr;
	m_isDirty = true;
	m_color = { 255, 255, 255, 255 };
	m_dimension = { 10, 10 };
}

void Text::SetText(const std::string text)
{
	m_text = text;
	m_isDirty = true;
}

void Text::SetColor(const SDL_Color& color)
{
	m_color = color;
	m_isDirty = true;
}

void Text::SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	m_color.r = r;
	m_color.r = g;
	m_color.r = b;
	m_color.r = a;
	m_isDirty = true;
}

void Text::SetDimension(int width, int height)
{
	m_dimension = { width, height };
}

bool Text::Load(const std::string& filename, int fontSize)
{
	m_font = TTF_OpenFont(filename.c_str(), fontSize);

	if (!m_font)
	{
		std::cout << "Error loading font file." << std::endl;
		return false;
	}

	return true;
}

void Text::Render(int xPos, int yPos)
{
	SDL_Rect targetRect;

	targetRect.x = xPos;
	targetRect.y = yPos;
	targetRect.w = m_dimension.x;
	targetRect.h = m_dimension.y;

	if (m_isDirty)
	{
		SDL_DestroyTexture(m_texture);
		SDL_Surface* textData = TTF_RenderText_Blended(m_font, m_text.c_str(), m_color);
		m_texture = SDL_CreateTextureFromSurface(Screen::Instance()->GetRenderer(), textData);
		SDL_FreeSurface(textData);
		m_isDirty = false;
	}

	SDL_RenderCopy(Screen::Instance()->GetRenderer(), m_texture, nullptr, &targetRect);
}

void Text::Unload()
{
	TTF_CloseFont(m_font);
}