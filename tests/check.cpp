#include <gtest/gtest.h>

TEST(bruh_test, BasicAssertions) {

    EXPECT_STRNE("hello", "world");

    EXPECT_EQ(7 * 6, 42);
}
