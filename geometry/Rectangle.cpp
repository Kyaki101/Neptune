
#include "Shapes.h"

void Geometry::Rectangle::applyForce(LA::Vector2D& force) {
    acceleration = acceleration + (force.scalarMultiply(1.0 / this->mass));
}

LA::Vector2D Geometry::Rectangle::getPosition() {
    return position;
}

LA::Vector2D Geometry::Rectangle::getVelocity() {
    return velocity;
}

LA::Vector2D Geometry::Rectangle::getAcceleration() {
    return acceleration;
}

double Geometry::Rectangle::getHeight() {
    return height;
}

double Geometry::Rectangle::getWidth() {
    return width;
}

void Geometry::Rectangle::setPosition(LA::Vector2D pos) {
    position = pos;
}

void Geometry::Rectangle::setVelocity(LA::Vector2D vel) {
    velocity = vel;
}

void Geometry::Rectangle::setAcceleration(LA::Vector2D accs) {
    acceleration = accs;
}


void Geometry::Rectangle::draw() {
    DrawRectangle(position.getX(), position.getY(), width, height, color);
}

