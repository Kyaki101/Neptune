//
// Created by Emanuel Rojas on 1/16/26.
//

#ifndef CMAKE_PROJECT_TEMPLATE_RK4_H
#define CMAKE_PROJECT_TEMPLATE_RK4_H
#include <system/state.h>
#include "odeSolver/derivative.h"

namespace ode {
    class RK4 {
    public:
        static void update(systemS::State &s) ;
        static ode::Derivative f(systemS::State s);
    };
}


#endif //CMAKE_PROJECT_TEMPLATE_RK4_H