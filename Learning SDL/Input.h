#pragma once
#include <SDL.h>

struct MousePos
{
	int x;
	int y;
};

class Input
{

public:

	static Input* Instance();

	void Update();

	char GetKeyUp();
	char GetKeyDown();

	int GetMouseButtonDown();
	int GetMouseButtonUp();

	bool KeyPress();
	bool MouseClick();
	bool ClosedWindow();

	const MousePos& GetMousePosition();

private:

	char m_keyUp = 1;
	char m_keyDown = 0;

	bool m_KeyPress = false;
	bool m_MouseClick = false;
	bool m_ClosedWindow = false;

	int m_mouseButtonUp = 1;
	int m_mouseButtonDown = 0;

	MousePos m_mousePosition{ 0 , 0 };

};