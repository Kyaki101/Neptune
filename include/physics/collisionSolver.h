//
// Created by Emanuel Rojas on 1/17/26.
//

#ifndef CMAKE_PROJECT_TEMPLATE_COLLISIONSOLVER_H
#define CMAKE_PROJECT_TEMPLATE_COLLISIONSOLVER_H
#include "physicsBody.h"

namespace physics {
    class CollisionSolver {
    public:
        CollisionSolver() = delete;
        CollisionSolver(const CollisionSolver&) = delete;
        CollisionSolver(CollisionSolver&&) = delete;
        CollisionSolver& operator=(const CollisionSolver&) = delete;
        CollisionSolver& operator=(CollisionSolver&&) = delete;
        static void solveCollision(physics::PhysicsBody& a, physics::PhysicsBody& b);
    };
}

#endif //CMAKE_PROJECT_TEMPLATE_COLLISIONSOLVER_H