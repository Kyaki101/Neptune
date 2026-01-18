//
// Created by Emanuel Rojas on 1/17/26.
//

#ifndef CMAKE_PROJECT_TEMPLATE_PHYSICSBODY_H
#define CMAKE_PROJECT_TEMPLATE_PHYSICSBODY_H
#include "system/state.h"
#include "physics/bodyType.h"
#include "physics/collider.h"

namespace physics {
    class PhysicsBody {
    private:
        systemS::State state;
        physics::BodyType type;
    public:
        PhysicsBody(const systemS::State& s, physics::BodyType t, physics::Collider): state(s), type(t) {};





    };
}

#endif //CMAKE_PROJECT_TEMPLATE_PHYSICSBODY_H