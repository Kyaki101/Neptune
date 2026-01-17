//
// Created by Emanuel Rojas on 1/16/26.
//

#ifndef CMAKE_PROJECT_TEMPLATE_WORLD_H
#define CMAKE_PROJECT_TEMPLATE_WORLD_H
#include <vector>
#include <system/state.h>

namespace systemS {

    class World {
    private:
        std::vector<systemS::State> states;

    public:
        static constexpr double GRAVITY = 9.81;
        static constexpr double DIFFERENTIAL = 0.056;
        World(){}
        std::vector<systemS::State>& getStates();
        void addState(const systemS::State& state);
        void forceGenerator(systemS::State &s);
        void updateSystem();
    };
}

#endif //CMAKE_PROJECT_TEMPLATE_WORLD_H