#include "Vector2D.h"
#include <math.h>

Vector2D::Vector2D(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2D Vector2D::Add(const Vector2D& rhs)
{
	Vector2D result;

	result.x = x + rhs.x;
	result.y = y + rhs.y;

	return result;
}

Vector2D Vector2D::Subtract(const Vector2D& rhs)
{
	Vector2D result;

	result.x = x - rhs.x;
	result.y = y - rhs.y;

	return result;
}

Vector2D Vector2D::Scale(int rhs)
{
	Vector2D result;

	result.x = x * rhs;
	result.y = y * rhs;

	return result;
}

Vector2D Vector2D::Scale(const Vector2D& scale)
{
	Vector2D result;
	
	result.x = x * scale.x;
	result.y = y * scale.y;
	
	return result;
}

Vector2D Vector2D::Divide(int rhs)
{
	Vector2D result;

	if (rhs != 0)
	{
		result.x = x / rhs;
		result.y = y / rhs;
	}

	return result;
}

Vector2D Vector2D::Negation()
{
	Vector2D result;

	result.x = -x;
	result.y = -y;

	return result;
}

int Vector2D::Magnitude()
{
	double x = static_cast<double>(this->x);
	double y = static_cast<double>(this->y);
	
	return static_cast<int>(sqrt((x * x) + (y * y)));
}

int Vector2D::Distance(const Vector2D& rhs)
{
	Vector2D temp = Subtract(rhs);
	return static_cast<int>(temp.Magnitude());
}