#pragma once
#include <iostream>

class Vector2D {
public:
	Vector2D();
	Vector2D(float x, float y);
	~Vector2D();
	Vector2D(const Vector2D &p);

	Vector2D &operator=(const Vector2D &p);
	Vector2D &operator+=(const Vector2D &p);
	Vector2D &operator-=(const Vector2D &p);
	Vector2D operator+(const Vector2D &p);
	Vector2D operator-(const Vector2D &p);
	Vector2D operator*(const float scalar);

	friend std::ostream &operator<<(std::ostream& os, const Vector2D &p);

	float x;
	float y;

	inline void set(Vector2D vec) { x = vec.x; y = vec.y; }
};