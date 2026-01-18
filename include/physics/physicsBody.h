//
// Created by Emanuel Rojas on 1/17/26.
//

#ifndef CMAKE_PROJECT_TEMPLATE_PHYSICSBODY_H
#define CMAKE_PROJECT_TEMPLATE_PHYSICSBODY_H
#include <memory>

#include "system/state.h"
#include "physics/bodyType.h"
#include "physics/collider.h"

namespace physics {
    class PhysicsBody {
    private:
        systemS::State state;
        physics::BodyType type;
        std::unique_ptr<physics::Collider> collider;
    public:
        PhysicsBody(const systemS::State& s, const physics::BodyType t, const std::shared_ptr<physics::Collider>& c):
            state(s),
            type(t),
            collider(std::move(c).get()){};
        BodyType getBodyType() const;
        systemS::State& getState();
        Collider& getCollider() const;

    };
}

#endif //CMAKE_PROJECT_TEMPLATE_PHYSICSBODY_H