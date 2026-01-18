//
// Created by Emanuel Rojas on 1/17/26.
//
#include "physics/collisionSolver.h"

#include "physics/circleCollider.h"
#include "physics/physicsBody.h"

using namespace physics;

void CollisionSolver::solveCollision(physics::PhysicsBody &a, physics::PhysicsBody &b) {
    auto* A = &a;
    auto* B = &b;
    if (A->getBodyType() == BodyType::Static) {
        std::swap(A, B);
    }
    if (B->getBodyType() == BodyType::Static) {

        return;
    }

    auto& aPos = a.getState().getPosition();
    auto& bPos = b.getState().getPosition();
    const LA::Vector2D dist = aPos - bPos;
    const LA::Vector2D norm = dist.normalize();
    const double len = dist.magnitude();
    auto& aCol = dynamic_cast<CircleCollider&>(a.getCollider());
    auto& bCol = dynamic_cast<CircleCollider&>(b.getCollider());
    const double depth = (bCol.getRadius() + aCol.getRadius()) - len;

    aPos = aPos + norm * (depth * 0.5);
    bPos = bPos - norm * (depth * 0.5);
    auto& aVel = a.getState().getVelocity();
    auto& bVel = b.getState().getVelocity();
    aVel = aVel - norm * (2 * (aVel.dot(norm)));
    bVel = bVel - norm * (2 * (bVel.dot(norm)));

}
