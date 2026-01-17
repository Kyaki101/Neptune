//
// Created by Emanuel Rojas on 1/16/26.
//

#ifndef CMAKE_PROJECT_TEMPLATE_VECTOR2D_H
#define CMAKE_PROJECT_TEMPLATE_VECTOR2D_H

namespace LA {
    class Vector2D {
    private:
        double x, y;
    public:
        double getX() const;
        double getY() const;
        Vector2D(const double x, const double y) : x(x), y(y) {}
        Vector2D() : x(0), y(0) {}
        Vector2D operator+(const LA::Vector2D &v) const;
        Vector2D operator-(const LA::Vector2D &v) const;
        double dot(const LA::Vector2D &v) const;
        double magnitude() const;
        Vector2D operator*(double scalar) const;
        Vector2D operator/(double scalar) const;
        Vector2D normalize() const;
    };
}

#endif //CMAKE_PROJECT_TEMPLATE_VECTOR2D_H