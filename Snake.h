//
// Created by Emanuel Rojas on 2/4/25.
//

#ifndef SNAKE_H
#define SNAKE_H

#include <deque>

#include "Food.h"
#include "raylib.h"
#include "raymath.h"


class Snake {
    private:


    std::deque<Vector2> body = { {1, 0}, {2, 0}, {3, 0}};

    Vector2 direction = {1, 0};

    Color color;

    public:

    Snake(Color color) {
        this->color = color;
    }

    void Draw() {
        for (int i = 0; i < body.size(); i++) {
            float x = body[i].x;
            float y = body[i].y;
            Rectangle segment = Rectangle{x * 30, y * 30, 30, 30};
            DrawRectangleRounded(segment, 0.5, 6, color);

        }
    }

    void changeDir() {
        if (IsKeyDown(KEY_UP) && direction.y != 1) {
            direction.y = -1;
            direction.x = 0;
        }
        if (IsKeyDown(KEY_DOWN) && direction.y != -1) {
            direction.y = 1;
            direction.x = 0;
        }
        if (IsKeyDown(KEY_RIGHT) && direction.x != -1) {
            direction.y = 0;
            direction.x = 1;
        }
        if (IsKeyDown(KEY_LEFT) && direction.x != 1) {
            direction.y = 0;
            direction.x = -1;
        }
    }

    bool update(Food & food) {
        if (food.getPosition() == body.front()) {
            body.push_front(body.front() + direction);
            return true;
        }
        body.pop_back();
        body.push_front(body.front() + direction);
        return false;
    }


};



#endif //SNAKE_H
