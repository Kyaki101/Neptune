//
// Created by Emanuel Rojas on 1/16/26.
//

#include "system/world.h"
#include <vector>
#include "odeSolver/rk4.h"

using namespace systemS;

std::vector<systemS::State> systemS::World::states;

void World::addState(const systemS::State &state) {
    states.push_back(state);
}
std::vector<systemS::State> &World::getStates() {
    return states;
}

void World::forceGenerator(systemS::State &s) {

}

void World::updateSystem() {
    for (auto &s : states) {
        ode::RK4::update(s);
    }
}


