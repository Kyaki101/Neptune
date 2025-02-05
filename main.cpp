#include "raylib.h"

#include "rlgl.h"
#include "raymath.h"
#include "Food.h"
#include "Snake.h"
#include "geometry/Shapes.h"
#include "GLFW/glfw3.h"
#include "linearAlgebra/Vector2D.hpp"
#include "simulator/SystemState.hpp"
#include <iostream>


#define SCREEN_WIDTH 800;
#define SCREEN_HEIGHT 600;

Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

double lastUpdateTime = 0;

bool eventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }

    return false;
}



int main ()
{
    InitWindow(800, 600, "Neptune");

    SetTargetFPS(60);


    std::unique_ptr<Geometry::Shape> rect = std::make_unique<Geometry::Rectangle>(50, 50, 50, 50, darkGreen);

    sim::SystemState SS = sim::SystemState();

    SS.addObject(std::move(rect));

    Food food = Food(darkGreen);

    Snake snake = Snake(darkGreen);

    while (!WindowShouldClose()) {

        if (eventTriggered(0.2)) {
        }


        BeginDrawing();
        ClearBackground(green);

        SS.update();


        EndDrawing();
    }




    CloseWindow();

    return 0;
}