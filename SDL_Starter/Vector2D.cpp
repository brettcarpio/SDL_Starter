#include "Vector2D.h"

Vector2D::Vector2D()
	: x(0.f),
	y(0.f) {
}

Vector2D::Vector2D(float x, float y)
	: x(x),
	y(y) {
}

Vector2D::~Vector2D() {
}

Vector2D::Vector2D(const Vector2D &p) {
	x = p.x; 
	y = p.y;
}

Vector2D &Vector2D::operator=(const Vector2D &p) {
	x = p.x;
	y = p.y;
	return *this;
}

Vector2D &Vector2D::operator+=(const Vector2D &p) {
	x += p.x;
	y += p.y;
	return *this;
}

Vector2D &Vector2D::operator-=(const Vector2D &p) {
	x -= p.x;
	y -= p.y;
	return *this;
}

Vector2D Vector2D::operator+(const Vector2D &p) {
	Vector2D pos(x + p.x, y + p.y);
	return pos;
}

Vector2D Vector2D::operator-(const Vector2D &p) {
	Vector2D pos(x - p.x, y - p.y);
	return pos;
}

Vector2D Vector2D::operator*(const float scalar) {
	x *= scalar;
	y *= scalar;
	return *this;
}

std::ostream & operator<<(std::ostream & os, const Vector2D & p) {
	os << "{ x: " << p.x << ", y: " << p.y << "}";
	return os;
}


