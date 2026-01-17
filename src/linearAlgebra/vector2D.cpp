#include "../../include/linearAlgebra/vector2D.h"
#include <cmath>

double LA::Vector2D::getX() const {
    return x;
}

double LA::Vector2D::getY() const {
    return y;
}

LA::Vector2D LA::Vector2D::operator+(const LA::Vector2D &v) const {
    return { x + v.x, y + v.y };
}

LA::Vector2D LA::Vector2D::operator-(const LA::Vector2D &v) const {
    return { x - v.x, y - v.y };
}
LA::Vector2D LA::Vector2D::operator/(const double scalar) const {
    return { x / scalar, y / scalar };
}

LA::Vector2D LA::Vector2D::operator*(const double scalar) const {
    return { x * scalar, y * scalar };
}

double LA::Vector2D::dot(const LA::Vector2D &v) const {
    return x * v.x + y * v.y;
}

double LA::Vector2D::magnitude() const {
    return sqrt(x * x + y * y);
}

LA::Vector2D LA::Vector2D::normalize() const {
    const double mag = magnitude();
    return { x / mag, y / mag };
}


