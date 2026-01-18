//
// Created by Emanuel Rojas on 1/16/26.
//

#ifndef CMAKE_PROJECT_TEMPLATE_STATE_H
#define CMAKE_PROJECT_TEMPLATE_STATE_H

#include <linearAlgebra/vector2D.h>
#include "odeSolver/derivative.h"

namespace systemS {
    class State {
    private:
        LA::Vector2D position;
        LA::Vector2D velocity;
        double mass;
    public:
        State(const LA::Vector2D position, const double mass): position(position),
            velocity(LA::Vector2D()),
            mass(mass){};
        State(const LA::Vector2D position, const LA::Vector2D velocity, const double mass): position(position),
            velocity(velocity),
            mass(mass){};

        LA::Vector2D& getPosition();
        LA::Vector2D& getVelocity();
        systemS::State operator+(systemS::State);
        systemS::State operator-(systemS::State);
        systemS::State operator*(double);
        systemS::State operator/(double);
        systemS::State& operator=(systemS::State);
        State operator+(ode::Derivative);
        double getMass() const;
        void setMass(double mass);
        void setPosition(const LA::Vector2D &position);
        void setVelocity(const LA::Vector2D &velocity);
    };


}

#endif //CMAKE_PROJECT_TEMPLATE_STATE_H