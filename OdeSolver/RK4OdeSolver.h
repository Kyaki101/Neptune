//
// Created by Emanuel Rojas on 2/5/25.
//

#ifndef RK4ODESOLVER_H
#define RK4ODESOLVER_H
#include <memory>

#include "../geometry/Shapes.h"

namespace OdeSolver {

    class RK4OdeSolver {
    public:
        double deltaTime;
        RK4OdeSolver(double dt) {
            deltaTime = dt;
        }

        LA::Vector2D computeAcceleration(LA::Vector2D vel, LA::Vector2D accs);

        void solve(std::unique_ptr<Geometry::Shape> & shape);
    };
}

#endif //RK4ODESOLVER_H
