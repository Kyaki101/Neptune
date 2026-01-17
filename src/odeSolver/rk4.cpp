//
// Created by Emanuel Rojas on 1/16/26.
//

#include "odeSolver/rk4.h"
#include "linearAlgebra/vector2D.h"
#include "system/state.h"
#include "system/world.h"
#include "odeSolver/derivative.h"
using namespace ode;

ode::Derivative RK4::f(systemS::State s) {
    return { s.getVelocity(), { 0, systemS::World::GRAVITY } };
}

void RK4::update(systemS::State &s) {

    LA::Vector2D pos = s.getPosition();
    LA::Vector2D vel = s.getVelocity();
    constexpr double dt = systemS::World::DIFFERENTIAL;
    const auto k1 = f(s);
    const auto k2 = f(s + (k1 / 2.0) * dt);
    const auto k3 = f(s + (k2 / 2.0) * dt);
    const auto k4 = f(s + k3 * dt);
    const auto avg = (k1 + k2 * 2 + k3 * 2 + k4) * (dt / 6) ;
    s = s + avg;
}
