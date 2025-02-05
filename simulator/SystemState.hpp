//
// Created by Emanuel Rojas on 2/4/25.
//

#ifndef SYSTEMSTATE_H
#define SYSTEMSTATE_H
#include <vector>

#include "../geometry/Shapes.h"
#include "../linearAlgebra/Vector2D.hpp"

namespace sim {

class SystemState {
    LA::Vector2D gravity = {0, -9.81};
    double currentTime = 0;
    double dt = 0.016;
    double pixelsPerMeter = 50;
    std::vector<std::unique_ptr<Geometry::Shape>> objects;
    public:
    void update();
    void addObject(std::unique_ptr<Geometry::Shape> obj);
    SystemState() = default;


};


}

#endif //SYSTEMSTATE_H
