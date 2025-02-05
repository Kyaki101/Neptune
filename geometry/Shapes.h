//
// Created by Emanuel Rojas on 2/4/25.
//

#ifndef SHAPES_H
#define SHAPES_H
#include "raylib.h"
#include "../linearAlgebra/Vector2D.hpp"

namespace Geometry {
    class Shape {
    public:
        virtual void draw() = 0;
        virtual void applyForce(LA::Vector2D& force) = 0;
        virtual LA::Vector2D getVelocity() = 0;
        virtual LA::Vector2D getAcceleration() = 0;
        virtual LA::Vector2D getPosition() = 0;
        virtual void setPosition(LA::Vector2D pos) = 0;
        virtual void setAcceleration(LA::Vector2D accs) = 0;
        virtual void setVelocity(LA::Vector2D vel) = 0;
        virtual ~Shape() = default;
    };


    class Rectangle : public Shape {
    private:
        LA::Vector2D velocity, acceleration, position;
        Color color;
        double width, height, mass;
    public:
        Rectangle(double x, double y, double width, double height, Color color) {
            position = LA::Vector2D(x, y);
            velocity = LA::Vector2D(0, 0);
            this->width = width;
            this->height = height;
            acceleration = LA::Vector2D();
            this->color = color;
            this->mass = 10;


        }
        void applyForce(LA::Vector2D& force) override;
        void draw() override;
        LA::Vector2D getVelocity() override;
        LA::Vector2D getAcceleration() override;
        LA::Vector2D getPosition() override;
        void setAcceleration(LA::Vector2D accs) override;
        void setPosition(LA::Vector2D pos) override;
        void setVelocity(LA::Vector2D vel) override;
        double getHeight();
        double getWidth();


    };

}

#endif //SHAPES_H
