//
// Created by Emanuel Rojas on 2/4/25.
//

#include "SystemState.hpp"
#include <iostream>

void sim::SystemState::update() {
    for (auto & obj : objects) {
        RK4.solve(obj);
        std::cout << obj->getVelocity().getX() << ' ' << obj->getVelocity().getY() << std::endl;
        obj->draw();
    }
}




void sim::SystemState::addObject(std::unique_ptr<Geometry::Shape> obj) {
    objects.push_back(std::move(obj));
}

