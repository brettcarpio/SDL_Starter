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

	inline float getX() const { return m_x; }
	inline float getY() const { return m_y; }
	inline void setX(const float x) { m_x = x; }
	inline void setY(const float y) { m_y = y; }
	inline void set(const float x, const float y) { m_x = x; m_y = y; }
	inline void set(Vector2D vec) { m_x = vec.getX(); m_y = vec.getY(); }

private:
	float m_x;
	float m_y;
};