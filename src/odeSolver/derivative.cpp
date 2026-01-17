//
// Created by Emanuel Rojas on 1/17/26.
//

#include "odeSolver/derivative.h"



ode::Derivative ode::Derivative::operator*(double scalar) const {
    return {dPos * scalar, dVel * scalar};
}

ode::Derivative ode::Derivative::operator/(double scalar) const {
    return {dPos / scalar, dVel / scalar};
}

ode::Derivative ode::Derivative::operator+(Derivative other) const {
    return {dPos + other.dPos, dVel + other.dVel};
}
