cmake_minimum_required(VERSION 4.0.3)
project(Neptune)

include(FetchContent)

FetchContent_Declare(
    sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
)

FetchContent_MakeAvailable(sfml)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

add_executable(sfml_app ${SOURCES})

target_link_libraries(sfml_app PRIVATE sfml-graphics sfml-window sfml-system)

target_include_directories(sfml_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
