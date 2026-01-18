//
// Created by Emanuel Rojas on 1/17/26.
//

#include "physics/physicsBody.h"

using namespace physics;

BodyType PhysicsBody::getBodyType() const {
    return type;
}

systemS::State& PhysicsBody::getState() {
    return state;
}

Collider& PhysicsBody::getCollider() const {
    return *collider;
}

