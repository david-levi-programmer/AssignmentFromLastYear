#pragma once

class Vector2D
{

public:

	Vector2D(int x = 0, int y = 0);
	
	Vector2D Add(const Vector2D& rhs);
	Vector2D Subtract(const Vector2D& rhs);
	Vector2D Scale(int rhs);
	Vector2D Scale(const Vector2D& scale);
	Vector2D Divide(int rhs);
	Vector2D Negation();

	int Magnitude();
	int Distance(const Vector2D& rhs);

	int x;
	int y;

};