#ifndef VECTOR_2D_LA
#define VECTOR_2D_LA


namespace linear_algebra {
    
class Vector2D {
private:
    double x;
    double y;
public:
    Vector2D(double x, double y);
    Vector2D();
    Vector2D operator*(const double) const;
    Vector2D operator+(const Vector2D &other) const;
    Vector2D operator-(const Vector2D &other) const;
    bool operator==(const Vector2D &other) const;
    double dotProduct(const Vector2D &other) const;
    double magnitude();
    Vector2D projection(const Vector2D &other) const;
    Vector2D normalize();
    double distance(const Vector2D &other);
    double getX() const;
    double getY() const;

};


}

#endif
