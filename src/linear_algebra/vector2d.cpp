#include "./../../include/linear_algebra/vector2d.h"

#include <cmath>
#include <stdexcept>

namespace linear_algebra {

Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

Vector2D::Vector2D() : x(0), y(0) {}

Vector2D Vector2D::operator*(const double scalar) const {
    return { getX() * scalar, getY() * scalar }; 

}

Vector2D Vector2D::operator+(const Vector2D &other) const {
    return { this->x + other.getX(), this->y + other.getY() };
}

Vector2D Vector2D::operator-(const Vector2D &other) const {
    return { this->x - other.getX(), this->y - other.getY() };
}

bool Vector2D::operator==(const Vector2D &other) const {
    return this->x == other.getX() && this->y == other.getY();
}

double Vector2D::getX() const {
    return this->x;
}

double Vector2D::getY() const {
    return this->y;
}

double Vector2D::dotProduct(const Vector2D &other) const {
    return this->x * other.getX() + this->y * other.getY();
}

double Vector2D::magnitude() {
    return sqrt(this->x * this->x + this->y * this->y);
}

Vector2D Vector2D::projection(const Vector2D &other) const {
    if(other == linear_algebra::Vector2D(0, 0)) {
        throw std::invalid_argument("Cannot make projection to null vector");
    }
    double scalar = dotProduct(other) / other.dotProduct(other);
    return other * scalar;

}

Vector2D Vector2D::normalize() {
    double mag = magnitude();
    return mag == 0 ? Vector2D() : Vector2D(x / mag, y / mag);
}

double Vector2D::distance(const Vector2D &other) {
    return sqrt(pow(this->x - other.getX(), 2) 
                +  pow(this->y - other.getY(), 2));

}

}
