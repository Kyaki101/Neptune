//
// Created by Emanuel Rojas on 2/4/25.
//

#include "Vector2D.hpp"

#include <cmath>


LA::Vector2D LA::Vector2D::operator+(const LA::Vector2D &other) {
    return {x + other.x, y + other.y};
}

LA::Vector2D LA::Vector2D::operator-(const LA::Vector2D &other) {
    return {x - other.x, y - other.y};
}

double LA::Vector2D::dotProduct(LA::Vector2D &other) {
    return x * other.x + y * other.y;
}

double LA::Vector2D::magnitude() {
    return sqrt(x * x + y * y);
}

LA::Vector2D LA::Vector2D::normalize() {
    double mag = magnitude();
    return mag == 0 ? LA::Vector2D() : LA::Vector2D(x / mag, y / mag);
}

double LA::Vector2D::distance(const LA::Vector2D &other) {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

LA::Vector2D LA::Vector2D::projection(LA::Vector2D &other) {
    double scalar = dotProduct(other) / other.dotProduct(other);
    return other.scalarMultiply(scalar);
}

LA::Vector2D LA::Vector2D::scalarMultiply(double scalar) {
    return LA::Vector2D(x * scalar, y * scalar);
}

double LA::Vector2D::getX() {
    return x;
}

double LA::Vector2D::getY() {
    return y;
}



