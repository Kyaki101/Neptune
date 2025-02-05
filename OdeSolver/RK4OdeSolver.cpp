//
// Created by Emanuel Rojas on 2/5/25.
//

#include "RK4OdeSolver.h"

LA::Vector2D OdeSolver::RK4OdeSolver::computeAcceleration(LA::Vector2D vel, LA::Vector2D accs) {
    return {0, 9.81 * 100};
}

void OdeSolver::RK4OdeSolver::solve(std::unique_ptr<Geometry::Shape> & shape) {
    LA::Vector2D k1_pos = shape->getVelocity();
    LA::Vector2D k1_vel = shape->getAcceleration();

    LA::Vector2D k2_pos = k1_pos + k1_vel.scalarMultiply(deltaTime / 2);
    LA::Vector2D k2_vel = this->computeAcceleration(shape->getPosition() + k1_pos.scalarMultiply(deltaTime / 2), shape->getVelocity() + k1_vel.scalarMultiply(deltaTime / 2));

    LA::Vector2D k3_pos = k2_pos + k2_vel.scalarMultiply(deltaTime / 2);
    LA::Vector2D k3_vel = this->computeAcceleration(shape->getPosition() + k2_pos.scalarMultiply(deltaTime / 2), shape->getVelocity() + k2_vel.scalarMultiply(deltaTime / 2));

    LA::Vector2D k4_pos = k3_pos + k3_vel.scalarMultiply(deltaTime);
    LA::Vector2D k4_vel = this->computeAcceleration(shape->getPosition() + k3_pos.scalarMultiply(deltaTime), shape->getVelocity() + k3_vel.scalarMultiply(deltaTime));

    shape->setPosition(shape->getPosition() + (k1_pos + k2_pos.scalarMultiply(2) + k3_pos.scalarMultiply(2) + k4_pos).scalarMultiply(deltaTime / 6));
    shape->setVelocity(shape->getVelocity() + (k1_vel + k2_vel.scalarMultiply(2) + k3_vel.scalarMultiply(2) + k4_vel).scalarMultiply(deltaTime / 6));
}

