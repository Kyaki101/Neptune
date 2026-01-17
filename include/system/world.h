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
        static std::vector<systemS::State> states;


    public:
        static constexpr double GRAVITY = 9.81;
        static constexpr double DIFFERENTIAL = 0.016;
        static std::vector<systemS::State>& getStates();
        static void addState(const systemS::State& state);
        static void forceGenerator(systemS::State &s);
        static void updateSystem();

        World() = delete;
        World(const World &) = delete;
        World(World &&) = delete;
        World &operator=(const World &) = delete;
        World &operator=(World &&) = delete;
    };
}

#endif //CMAKE_PROJECT_TEMPLATE_WORLD_H