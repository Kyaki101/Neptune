//
// Created by Emanuel Rojas on 2/4/25.
//

#ifndef SYSTEMSTATE_H
#define SYSTEMSTATE_H
#include <vector>

#include "../geometry/Shapes.h"
#include "../linearAlgebra/Vector2D.hpp"
#include "../OdeSolver/RK4OdeSolver.h"

namespace sim {

class SystemState {
    LA::Vector2D gravity = {0, -9.81};
    OdeSolver::RK4OdeSolver RK4;
    double dt;
    double currentTime = 0;
    double pixelsPerMeter = 50;
    std::vector<std::unique_ptr<Geometry::Shape>> objects;
    public:
    void update();
    double getDT() {
        return this->dt;
    }
    void addObject(std::unique_ptr<Geometry::Shape> obj);

    SystemState(double deltaTime): RK4(OdeSolver::RK4OdeSolver(deltaTime)), dt(deltaTime){};
};


}

#endif //SYSTEMSTATE_H
