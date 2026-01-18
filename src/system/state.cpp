//
// Created by Emanuel Rojas on 1/16/26.
//
#include "system/state.h"
using namespace systemS;

LA::Vector2D& State::getPosition() {
    return this->position;
}
LA::Vector2D& State::getVelocity() {
    return this->velocity;
}

double State::getMass() const {
    return mass;
}

State State::operator+(State other) {
    return { position + other.position, velocity + other.velocity, mass };
}

State State::operator-(State other) {
    return { position - other.position, velocity - other.velocity, mass };
}
State State::operator*(double scalar) {
    return { position * scalar, velocity * scalar, mass };
}
State State::operator/(double scalar) {
    return { position / scalar, velocity / scalar, mass };
}

void State::setPosition(const LA::Vector2D& position) {
    this->position = position;
}
void State::setVelocity(const LA::Vector2D& velocity) {
    this->velocity = velocity;
}
void State::setMass(double mass) {
    this->mass = mass;
}

systemS::State &State::operator=(systemS::State other) {
    this->position = other.position;
    this->velocity = other.velocity;
    this->mass = other.mass;
    return *this;
}

systemS::State State::operator+(ode::Derivative dx) {
    return { position + dx.dPos, velocity + dx.dVel, mass };
}