# cmake_minimum_required(VERSION 3.16)
# project(divider_tests)
#
# add_subdirectory(lib/googletest)
#
# include_directories(${DIVISION_HEADERS_DIR})
# include_directories(lib/googletest/googletest/include)
#
# set(SOURCE_FILES main.cpp src/divider_tests.cpp
#         ../include/linearAlgebra/vector2D.h
#         ../include/odeSolver/rk4.h
#         ../include/system/state.h
#         ../include/system/world.h
#         ../include/odeSolver/derivative.h
#         ../src/odeSolver/derivative.cpp
#         ../include/physics/physicsBody.h
#         ../include/physics/collider.h
#         ../include/physics/bodyType.h
#         ../include/physics/circleCollider.h
#         ../include/physics/collisionSolver.h
#         ../include/game/gameObject.h
# )
#
# add_executable(divider_tests ${SOURCE_FILES})
# target_link_libraries(divider_tests division gtest)
# install(TARGETS divider_tests DESTINATION bin)

