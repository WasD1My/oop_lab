#include "../oop_lab1_old/googletest/include/gtest/gtest.h"
#include "item.h"

#define EPS 1e-6

TEST(CircleTest, Perimeter) {
Circle c(5.0);
EXPECT_NEAR(c.getPerimeter(), 31.4159, EPS);
}

TEST(CircleTest, Area) {
Circle c(5.0);
EXPECT_NEAR(c.getArea(), 78.53975, EPS);
}

TEST(CircleTest, BoundingRectangle) {
Circle c(5.0);
double width, height;
c.getBoundingRectangle(width, height);
EXPECT_EQ(width, 10.0);
EXPECT_EQ(height, 10.0);
}

TEST(TriangleTest, Perimeter) {
Triangle t(3.0, 4.0, 5.0);
EXPECT_EQ(t.getPerimeter(), 12.0);
}

TEST(TriangleTest, Area) {
Triangle t(3.0, 4.0, 5.0);
EXPECT_NEAR(t.getArea(), 6.0, EPS);
}

TEST(TriangleTest, Validation) {
Triangle t(3.0, 4.0, 5.0);
EXPECT_TRUE(t.isTriangleValid());
}

TEST(RectangleTest, Perimeter) {
Rectangle r(4.0, 5.0);
EXPECT_EQ(r.getPerimeter(), 18.0);
}

TEST(RectangleTest, Area) {
Rectangle r(4.0, 5.0);
EXPECT_EQ(r.getArea(), 20.0);
}

TEST(RectangleTest, BoundingRectangle) {
Rectangle r(4.0, 5.0);
double width, height;
r.getBoundingRectangle(width, height);
EXPECT_EQ(width, 4.0);
EXPECT_EQ(height, 5.0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}