#include <gtest/gtest.h>
#include "../include/linear_algebra/vector2d.h"

TEST(LinearAlgebra, Basic) {

    linear_algebra::Vector2D testVector(2.0, 2.0);

    EXPECT_EQ(testVector.getX(), 2.0);
}

TEST(LinearAlgebra, DotProdTest) {
    linear_algebra::Vector2D vectorA(2.0, 4.0);
    linear_algebra::Vector2D vectorB(5.0, 8.0);

    EXPECT_EQ(vectorA.dotProduct(vectorB), 42.0);
}
