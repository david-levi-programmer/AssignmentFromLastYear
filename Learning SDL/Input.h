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
	Input();
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
	char m_keyUp;
	char m_keyDown;

	bool m_KeyPress;
	bool m_MouseClick;
	bool m_ClosedWindow;

	int m_mouseButtonUp;
	int m_mouseButtonDown;

	MousePos m_mousePosition;
};