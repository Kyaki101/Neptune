//
// Created by Emanuel Rojas on 1/17/26.
//

#ifndef CMAKE_PROJECT_TEMPLATE_CIRCLECOLLIDER_H
#define CMAKE_PROJECT_TEMPLATE_CIRCLECOLLIDER_H

#include "collider.h"

namespace physics {
    class CircleCollider : public Collider {

    private:
        double radius;

    public:
        explicit CircleCollider(const double r): radius(r) {};
        double getRadius() const;

        bool collide(
            Collider& other,
            systemS::State& stateA,
            systemS::State& stateB
        ) const override;

        bool collideWithCircle(
            const CircleCollider& other,
            systemS::State& stateA,
            systemS::State& stateB
        ) const override;
    };
}

#endif //CMAKE_PROJECT_TEMPLATE_CIRCLECOLLIDER_H