#ifndef VECTOR_2D_H
#define VECTOR_2D_H

namespace LA {
    class Vector2D {
    private:
        double x, y;
    public:
        Vector2D(double x, double y) : x(x), y(y) {}
        Vector2D() : x(0), y(0) {}
        Vector2D operator+(const Vector2D & other);
        Vector2D operator-(const Vector2D & other);
        double dotProduct(Vector2D & other);
        double magnitude();
        Vector2D normalize();
        double distance(const Vector2D & other);
        Vector2D projection(Vector2D & other);
        Vector2D scalarMultiply(double scalar);
        double getX();
        double getY();


    };
}

#endif