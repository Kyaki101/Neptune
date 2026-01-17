//
// Created by Emanuel Rojas on 1/17/26.
//

#ifndef CMAKE_PROJECT_TEMPLATE_DERIVATIVE_H
#define CMAKE_PROJECT_TEMPLATE_DERIVATIVE_H

#include <linearAlgebra/vector2D.h>

namespace ode {
    class Derivative {
        public:
        LA::Vector2D dPos;
        LA::Vector2D dVel;
        Derivative(){}
        Derivative(LA::Vector2D dPos, LA::Vector2D dVel): dPos(dPos), dVel(dVel) {};
        Derivative operator*(double scalar) const;
        Derivative operator/(double scalar) const;
        Derivative operator+(Derivative) const;
    };

}

#endif //CMAKE_PROJECT_TEMPLATE_DERIVATIVE_H