#include <gtest/gtest.h>
#include <sstream>
#include "trapezoid.h"
#include "rhombus.h"
#include "pentagon.h"
#include "array.h"

TEST(TrapezoidTest, AreaCalculation) {
    Trapezoid t;
    std::istringstream iss("0 0 4 0 3 2 1 2");
    iss >> t;
    EXPECT_NEAR(t.area(), 6.0, 1e-6);
}

TEST(TrapezoidTest, GeometricCenter) {
    Trapezoid t;
    std::istringstream iss("0 0 4 0 3 2 1 2");
    iss >> t;
    Point center = t.geometricCenter();
    EXPECT_NEAR(center.x, 2.0, 1e-6);
    EXPECT_NEAR(center.y, 1.0, 1e-6);
}

TEST(RhombusTest, AreaCalculation) {
    Rhombus r;
    std::istringstream iss("0 0 2 2 4 0 2 -2");
    iss >> r;
    EXPECT_NEAR(r.area(), 8.0, 1e-6);
}

TEST(RhombusTest, GeometricCenter) {
    Rhombus r;
    std::istringstream iss("0 0 2 2 4 0 2 -2");
    iss >> r;
    Point center = r.geometricCenter();
    EXPECT_NEAR(center.x, 2.0, 1e-6);
    EXPECT_NEAR(center.y, 0.0, 1e-6);
}

TEST(PentagonTest, AreaCalculation) {
    Pentagon p;
    std::istringstream iss("0 0 1 2 3 2 4 0 2 -1");
    iss >> p;
    EXPECT_NEAR(p.area(), 8.0, 1e-6);
}

TEST(PentagonTest, GeometricCenter) {
    Pentagon p;
    std::istringstream iss("0 0 1 2 3 2 4 0 2 -1");
    iss >> p;
    Point center = p.geometricCenter();
    EXPECT_NEAR(center.x, 2.0, 1e-6);
    EXPECT_NEAR(center.y, 0.6, 1e-6);
}

TEST(ArrayTest, AddAndRemove) {
    Array arr;
    arr.pushBack(new Trapezoid());
    arr.pushBack(new Rhombus());
    EXPECT_EQ(arr.getSize(), 2);
    arr.removeAt(0);
    EXPECT_EQ(arr.getSize(), 1);
}

TEST(ArrayTest, TotalArea) {
    Array arr;
    
    Trapezoid* t = new Trapezoid();
    std::istringstream iss1("0 0 4 0 3 2 1 2");
    iss1 >> *t;
    arr.pushBack(t);
    
    Rhombus* r = new Rhombus();
    std::istringstream iss2("0 0 2 2 4 0 2 -2");
    iss2 >> *r;
    arr.pushBack(r);

    Pentagon* p = new Pentagon();
    std::istringstream iss3("0 0 1 2 3 2 4 0 2 -1");
    iss3 >> *p;
    arr.pushBack(p);
    
    EXPECT_NEAR(arr.totalArea(), 22.0, 1e-6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}