#pragma once
class Vector2D
{
public:
	float x;
	float y;

	//bool operator==(const Vector2D& other) const {
	//	return x == other.x && y == other.y;
	//}	
	bool operator!=(const Vector2D& other) const {
		return x != other.x || y != other.y;
	}
	Vector2D operator + (const Vector2D& other) const {
		return Vector2D(x + other.x , y + other.y);
	}

	bool operator==(const Vector2D& other) const {
		return x == other.x && y == other.y;
	}

	// Opérateur < pour la comparaison
	bool operator<(const Vector2D& other) const {
		return (x < other.x) || (x == other.x && y < other.y);
	}

	Vector2D(float x, float y)
		: x(x), y(y)
	{
	}
	Vector2D()
		: x(0), y(0)
	{
	}
};

