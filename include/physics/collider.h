//
// Created by Emanuel Rojas on 1/17/26.
//

#ifndef CMAKE_PROJECT_TEMPLATE_COLLIDER_H
#define CMAKE_PROJECT_TEMPLATE_COLLIDER_H
#include "linearAlgebra/vector2D.h"
#include "system/state.h"

namespace physics {
    class CircleCollider;
    class Collider {
    public:
        virtual ~Collider() = default;

        virtual bool collide(
            Collider& other,
            systemS::State& stateA,
            systemS::State& stateB
        ) const = 0;

        virtual bool collideWithCircle(
            const physics::CircleCollider& other,
            systemS::State& stateA,
            systemS::State& stateB
        ) const = 0;

    };
}

#endif //CMAKE_PROJECT_TEMPLATE_COLLIDER_H