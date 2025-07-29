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
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# === Main Application ===
add_executable(sfml_app ${SOURCES})
target_link_libraries(sfml_app PRIVATE sfml-graphics sfml-window sfml-system)
target_include_directories(sfml_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# === Unit Tests ===
# Enable tests
enable_testing()
include(GoogleTest)

# List of component test files
set(TEST_COMPONENTS
    check
    #    linear_algebra_test
    #    geometry_test
    #    simulation_test
    #    ode_test
)

# Loop through and create one test target per component
foreach(test_name IN LISTS TEST_COMPONENTS)
    add_executable(${test_name} tests/${test_name}.cpp)
    
    target_link_libraries(${test_name}
        GTest::gtest_main
    )
    
    # Include src/ so tests can use your actual code
    target_include_directories(${test_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

    gtest_discover_tests(${test_name})
endforeach()

