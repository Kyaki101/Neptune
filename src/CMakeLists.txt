cmake_minimum_required(VERSION 3.16)
project(neptune LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML CONFIG REQUIRED Graphics)

add_subdirectory(division)

add_executable(neptune main.cpp
        ../include/linearAlgebra/vector2D.h
        ../include/system/state.h
        ../include/system/world.h
        ../include/odeSolver/rk4.h
        linearAlgebra/vector2D.cpp
        odeSolver/rk4.cpp
        system/state.cpp
        system/world.cpp
        odeSolver/derivative.cpp
        physics/circleCollider.cpp
        physics/collisionSolver.cpp
        physics/physicsBody.cpp
        game/gameObject.cpp
)

target_link_libraries(neptune
        PRIVATE
        division
        SFML::Graphics
)

install(TARGETS neptune DESTINATION ${DIVISIBLE_INSTALL_BIN_DIR})
