#include <gtest/gtest.h>
#include "container.h"
#include <cmath>

const double EPS = 1e-9;

TEST(ContainerTest, EmptyContainer) {
Container container;
EXPECT_EQ(container.getSize(), 0);
}

TEST(ContainerTest, AddCircle) {
Container container;
Circle* circle = new Circle(1.0);
container.insertAt(0, circle);
EXPECT_EQ(container.getSize(), 1);
}

TEST(ContainerTest, GetCircleArea) {
Container container;
Circle* circle = new Circle(1.0);
container.insertAt(0, circle);
Figure* figure = container[0];
EXPECT_NEAR(figure->getArea(), 3.14159, EPS);
}

TEST(ContainerTest, AddRectangle) {
Container container;
Rectangle* rectangle = new Rectangle(2.0, 3.0);
container.insertAt(0, rectangle);
EXPECT_EQ(container.getSize(), 1);
}

TEST(ContainerTest, GetRectangleArea) {
Container container;
Rectangle* rectangle = new Rectangle(2.0, 3.0);
container.insertAt(0, rectangle);
Figure* figure = container[0];
EXPECT_NEAR(figure->getArea(), 6.0, EPS);
}

TEST(ContainerTest, RemoveCircle) {
Container container;
Circle* circle = new Circle(1.0);
container.insertAt(0, circle);
container.removeAt(0);
EXPECT_EQ(container.getSize(), 0);
}

TEST(ContainerTest, GetAreaAfterErase) {
Container container;
Circle* circle = new Circle(1.0);
Rectangle* rectangle = new Rectangle(2.0, 3.0);
container.insertAt(0, circle);
container.insertAt(1, rectangle);
container.removeAt(0);
Figure* figure = container[0];
EXPECT_NEAR(figure->getArea(), 6.0, EPS);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
