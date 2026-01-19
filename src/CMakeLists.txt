cmake_minimum_required(VERSION 3.16)

add_executable(neptune
    main.cpp
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

target_include_directories(neptune
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(neptune
    PRIVATE
        SFML::Graphics
)

install(TARGETS neptune
    DESTINATION bin
)

