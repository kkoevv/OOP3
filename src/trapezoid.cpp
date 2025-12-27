#include "../include/trapezoid.h"
#include <initializer_list>
#include <cmath>
#include "../include/point.h"

Trapezoid::Trapezoid() : Figure(numOfPoints) {}

Trapezoid::Trapezoid(const std::initializer_list<Point> &t) : Figure(t) {}

Trapezoid::Trapezoid(const Trapezoid &other) : Figure(other) {}
Trapezoid::Trapezoid(Trapezoid &&other) : Figure(std::move(other)) {}

Trapezoid &Trapezoid::operator=(const Trapezoid &other) {
    Figure::operator=(other);
    return *this;
}

Trapezoid &Trapezoid::operator=(Trapezoid &&other) {
    Figure::operator=(std::move(other));
    return *this;
}

bool Trapezoid::operator==(const Trapezoid &other) const {
    return Figure::operator==(other);
}

bool Trapezoid::isValidRotationFigure() const {
    const std::vector<Point>& pts = getPoints();
    if (pts.size() != 4) return false;


    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (getPoint(i) == getPoint(j)) {
                return false;
            }
        }
    }

   
    if (calcArea() <= 1e-6) {
        return false;
    }

    //гор осн
    if (fabs(getPoint(0)[1] - getPoint(1)[1]) > 1e-6) {
        return false;
    }
    
    // верхнее осн
    if (fabs(getPoint(2)[1] - getPoint(3)[1]) > 1e-6) {
        return false;
    }

    //бок ст равны
    double leftSide = sqrt(pow(getPoint(3)[0] - getPoint(0)[0], 2) + 
                           pow(getPoint(3)[1] - getPoint(0)[1], 2));
    double rightSide = sqrt(pow(getPoint(2)[0] - getPoint(1)[0], 2) + 
                            pow(getPoint(2)[1] - getPoint(1)[1], 2));
    
    if (fabs(leftSide - rightSide) > 0.001) {
        return false;
    }

    // симметрия (сер осн)
    double midBottomX = (getPoint(0)[0] + getPoint(1)[0]) / 2;
    double midTopX = (getPoint(2)[0] + getPoint(3)[0]) / 2;
    
    if (fabs(midBottomX - midTopX) > 0.001) {
        return false;
    }

    double baseAB = fabs(getPoint(1)[0] - getPoint(0)[0]);
    double baseCD = fabs(getPoint(3)[0] - getPoint(2)[0]);
    
    if (baseAB <= baseCD) {
        return false;
    }

    // 7. высота
    double height = fabs(getPoint(2)[1] - getPoint(1)[1]);
    if (height < 1e-6) {
        return false;
    }

    return true;
}