cmake_minimum_required(VERSION 4.0.3)
project(Neptune)

include(FetchContent)

# Fetch SFML
FetchContent_Declare(
    sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
)

# Fetch GoogleTest
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(sfml googletest)

# Gather all source files under src/
file(GLOB_RECURSE ALL_SRC CONFIGURE_DEPENDS src/*.cpp)

# Exclude main.cpp from the sources for the library
list(FILTER ALL_SRC EXCLUDE REGEX ".*/main\\.cpp$")

# Create static library from all sources except main.cpp
add_library(neptune STATIC ${ALL_SRC})
target_include_directories(neptune PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Main application executable
add_executable(sfml_app src/main.cpp)
target_link_libraries(sfml_app PRIVATE neptune sfml-graphics sfml-window sfml-system)

# Enable testing and include GoogleTest
enable_testing()
include(GoogleTest)

# List of your test executables (one per component)
set(TEST_COMPONENTS
    linear_algebra_tests
    # geometry_tests
    # simulation_tests
    # ode_tests
)

# Loop through test components and create executables
foreach(test_name IN LISTS TEST_COMPONENTS)
    add_executable(${test_name} tests/${test_name}.cpp)

    target_link_libraries(${test_name}
        neptune
        GTest::gtest_main
    )

    target_include_directories(${test_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

    gtest_discover_tests(${test_name})
endforeach()

