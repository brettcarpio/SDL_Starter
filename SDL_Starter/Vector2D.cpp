#include "Vector2D.h"

Vector2D::Vector2D()
	: m_x(0.f),
	m_y(0.f) {
}

Vector2D::Vector2D(float x, float y)
	: m_x(x),
	m_y(y) {
}

Vector2D::~Vector2D() {
}

Vector2D::Vector2D(const Vector2D &p) {
	set(p.getX(), p.getY());
}

Vector2D &Vector2D::operator=(const Vector2D &p) {
	set(p.getX(), p.getY());
	return *this;
}

Vector2D &Vector2D::operator+=(const Vector2D &p) {
	set(m_x + p.getX(), m_y + p.getY());
	return *this;
}

Vector2D &Vector2D::operator-=(const Vector2D &p) {
	set(m_x - p.getX(), m_y - p.getY());
	return *this;
}

Vector2D Vector2D::operator+(const Vector2D &p) {
	Vector2D pos(m_x + p.getX(), m_y + p.getY());
	return pos;
}

Vector2D Vector2D::operator-(const Vector2D &p) {
	Vector2D pos(m_x - p.getX(), m_y - p.getY());
	return pos;
}

Vector2D Vector2D::operator*(const float scalar) {
	set(m_x * scalar, m_y * scalar);
	return *this;
}

std::ostream & operator<<(std::ostream & os, const Vector2D & p) {
	os << "{ x: " << p.getX() << ", y: " << p.getY() << "}";
	return os;
}


