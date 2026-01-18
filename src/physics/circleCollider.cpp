//
// Created by Emanuel Rojas on 1/17/26.
//

#include <physics/circleCollider.h>

using namespace physics;

double CircleCollider::getRadius() const {
    return radius;
}

bool CircleCollider::collideWithCircle(
    const CircleCollider& other,
    systemS::State& stateA,
    systemS::State& stateB
    ) const {

    const double radiusA = this->getRadius();
    const double radiusB = other.getRadius();
    const auto dist = stateB.getPosition() - stateA.getPosition();
    return dist.magnitude() <= radiusA + radiusB;
}

bool CircleCollider::collide(
    Collider& other,
    systemS::State& stateA,
    systemS::State& stateB
    ) const {

    if (auto * circle = dynamic_cast<const CircleCollider*>(&other)) {
        return collideWithCircle(*circle, stateA, stateB);
    }
    return false;
}
