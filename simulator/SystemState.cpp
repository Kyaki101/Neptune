//
// Created by Emanuel Rojas on 2/4/25.
//

#include "SystemState.hpp"
#include <iostream>

void sim::SystemState::update() {
    for (auto & obj : objects) {
        obj->setAcceleration(gravity.scalarMultiply(-1.0 * pixelsPerMeter));
        obj->setVelocity(obj->getVelocity() + obj->getAcceleration().scalarMultiply(dt));
        obj->setPosition(obj->getPosition() + obj->getVelocity().scalarMultiply(dt));
        std::cout << obj->getVelocity().getX() << ' ' << obj->getVelocity().getY() << std::endl;
        obj->draw();
    }
}

void sim::SystemState::addObject(std::unique_ptr<Geometry::Shape> obj) {
    objects.push_back(std::move(obj));
}

