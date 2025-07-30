#include <gtest/gtest.h>
#include "../include/linear_algebra/vector2d.h"
#include <stdexcept>

TEST(LinearAlgebra, Basic) {

    linear_algebra::Vector2D testVector(2.0, 2.0);

    EXPECT_EQ(testVector.getX(), 2.0);
}

TEST(LinearAlgebra, DotProdTest) {
    linear_algebra::Vector2D vectorA(2.0, 4.0);
    linear_algebra::Vector2D vectorB(5.0, 8.0);

    EXPECT_EQ(vectorA.dotProduct(vectorB), 42.0);
}

TEST(LinearAlgebra, projectionTest) {
    linear_algebra::Vector2D vectorA(4, 6);
    linear_algebra::Vector2D vectorB(2, 0);
    EXPECT_EQ(vectorA.projection(vectorB), linear_algebra::Vector2D(4.0, 0.0));
}

TEST(LinearAlgebra, NullVecProjection) {
    linear_algebra::Vector2D vectorA(30.0, 43.0);
    linear_algebra::Vector2D vectorB(0.0, 0.0);
    ASSERT_THROW(vectorA.projection(vectorB), std::invalid_argument);
}

TEST(LinearAlgebra, VectorAddition) {
    linear_algebra::Vector2D vectorA(24.0, 54.0);
    linear_algebra::Vector2D vectorB(67.0, 43.0);
    linear_algebra::Vector2D vectorC = vectorA + vectorB;
    EXPECT_EQ(vectorC, linear_algebra::Vector2D(91.0, 97.0));
}
