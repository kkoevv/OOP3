#include "../include/diamond.h"
#include "../include/figure.h"
#include "../include/figures.h"
#include "../include/pentagon.h"
#include "../include/point.h"
#include "../include/trapezoid.h"
#include <gtest/gtest.h>
#include <sstream>
#include <vector>

// ---------- Point ----------
TEST(PointTest, EqualityAndAccess) {
    Point p1(1.0, 2.0);
    Point p2(1.0, 2.0);
    Point p3(2.0, 3.0);

    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);

    EXPECT_DOUBLE_EQ(p1[0], 1.0);
    EXPECT_DOUBLE_EQ(p1[1], 2.0);
}

// ---------- Validation Tests ----------
TEST(TrapezoidValidationTest, ValidIsoscelesTrapezoid) {
    // Равнобедренная трапеция
    Trapezoid t({{0,0}, {4,0}, {3,2}, {1,2}});
    EXPECT_TRUE(t.isValidRotationFigure());
}

TEST(TrapezoidValidationTest, InvalidNotIsosceles) {
    // Не равнобедренная трапеция
    Trapezoid t({{0,0}, {4,0}, {4,2}, {0,3}});
    EXPECT_FALSE(t.isValidRotationFigure());
}

TEST(DiamondValidationTest, ValidRhombus) {
    // Правильный ромб
    Diamond d({{0,0}, {2,2}, {4,0}, {2,-2}});
    EXPECT_TRUE(d.isValidRotationFigure());
}

TEST(DiamondValidationTest, InvalidNotRhombus) {
    // Не ромб
    Diamond d({{0,0}, {3,0}, {4,2}, {1,2}});
    EXPECT_FALSE(d.isValidRotationFigure());
}

TEST(PentagonValidationTest, ValidRegularPentagon) {
    // Правильный пятиугольник
    Pentagon p({{0,0}, {2,0}, {3,1}, {1.5,2.5}, {-0.5,1}});
    EXPECT_TRUE(p.isValidRotationFigure());
}

TEST(PentagonValidationTest, InvalidNotRegular) {
    // Неправильный пятиугольник
    Pentagon p({{0,0}, {0,0}, {1,1}, {0.5,1.5}, {0,1}});
    EXPECT_FALSE(p.isValidRotationFigure());
}

TEST(IOValidationTest, InputStreamAcceptsValidFigure) {
    std::stringstream in("0 0 4 0 3 2 1 2"); // Равнобедренная трапеция
    Trapezoid t;
    in >> t;
    EXPECT_FALSE(in.fail());
}

/*TEST(IOValidationTest, InputStreamRejectsInvalidFigure) {
    // Трапеция с НЕгоризонтальным верхним основанием
    // Точки: A(0,0), B(4,0), C(3,2), D(1,2.5) - D выше C!
    std::stringstream in("0 0 10 0 9 5 1 6"); 
    Trapezoid t;
    in >> t;
    EXPECT_TRUE(in.fail());
}*/

// ---------- Area Tests ----------
TEST(AreaTest, TrapezoidArea) {
    Trapezoid t({{0,0}, {4,0}, {3,2}, {1,2}});
    EXPECT_NEAR(static_cast<double>(t), 6.0, 1e-6);
}

TEST(AreaTest, DiamondArea) {
    Diamond d({{0,0}, {2,2}, {4,0}, {2,-2}});
    EXPECT_NEAR(static_cast<double>(d), 8.0, 1e-6);
}

TEST(AreaTest, PentagonArea) {
    // Простой пятиугольник
    Pentagon p({{0,0}, {2,0}, {3,1}, {1.5,2.5}, {-0.5,1}});
    double area = static_cast<double>(p);
    EXPECT_GT(area, 0.0);
    EXPECT_LT(area, 10.0);
}

// ---------- Center Tests ----------
TEST(CenterTest, TrapezoidCenter) {
    Trapezoid t({{0,0}, {4,0}, {3,2}, {1,2}});
    Point c = t.calcGeometricCenter();
    EXPECT_NEAR(c[0], 2.0, 1e-6);
    EXPECT_NEAR(c[1], 0.8888888, 1e-6);
}

// ---------- Copy/Move Tests ----------
TEST(CopyMoveTest, TrapezoidCopy) {
    Trapezoid t1({{0,0}, {4,0}, {3,2}, {1,2}});
    Trapezoid t2 = t1;
    EXPECT_TRUE(t1 == t2);
}

TEST(CopyMoveTest, DiamondMove) {
    Diamond d1({{0,0}, {2,2}, {4,0}, {2,-2}});
    Diamond d2 = std::move(d1);
    EXPECT_NEAR(static_cast<double>(d2), 8.0, 1e-6);
}

// ---------- Figures Container Tests ----------
TEST(FiguresTest, AddAndTotalArea) {
    Figure* t = new Trapezoid({{0,0}, {4,0}, {3,2}, {1,2}});
    Figure* d = new Diamond({{0,0}, {2,2}, {4,0}, {2,-2}});
    
    Figures f({t, d});
    EXPECT_EQ(f.getSize(), 2);
    
    double total = f.calcTotalArea();
    EXPECT_NEAR(total, 14.0, 1e-6);
}

TEST(FiguresTest, DeleteFigure) {
    Figure* t = new Trapezoid({{0,0}, {4,0}, {3,2}, {1,2}});
    Figure* d = new Diamond({{0,0}, {2,2}, {4,0}, {2,-2}});
    
    Figures f({t, d});
    f.deleteFigure(0);
    EXPECT_EQ(f.getSize(), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}