#include "../include/diamond.h"
#include <initializer_list>
#include <cmath>
#include "../include/point.h"

Diamond::Diamond() : Figure(numOfPoints) {}

Diamond::Diamond(const std::initializer_list<Point> &t) : Figure(t) {}

Diamond::Diamond(const Diamond &other) : Figure(other) {}
Diamond::Diamond(Diamond &&other) : Figure(std::move(other)) {}

Diamond &Diamond::operator=(const Diamond &other) {
    Figure::operator=(other);
    return *this;
}

Diamond &Diamond::operator=(Diamond &&other) {
    Figure::operator=(std::move(other));
    return *this;
}

bool Diamond::operator==(const Diamond &other) const {
    return Figure::operator==(other);
}

bool Diamond::isValidRotationFigure() const {
    const std::vector<Point>& pts = getPoints();
    if (pts.size() != 4) return false;
    
    // Все стороны должны быть равны (с допуском)
    double side1 = sqrt(pow(getPoint(1)[0] - getPoint(0)[0], 2) + 
                        pow(getPoint(1)[1] - getPoint(0)[1], 2));
    double side2 = sqrt(pow(getPoint(2)[0] - getPoint(1)[0], 2) + 
                        pow(getPoint(2)[1] - getPoint(1)[1], 2));
    double side3 = sqrt(pow(getPoint(3)[0] - getPoint(2)[0], 2) + 
                        pow(getPoint(3)[1] - getPoint(2)[1], 2));
    double side4 = sqrt(pow(getPoint(0)[0] - getPoint(3)[0], 2) + 
                        pow(getPoint(0)[1] - getPoint(3)[1], 2));
    
    const double eps = 0.1;
    if (fabs(side1 - side2) > eps ||
        fabs(side2 - side3) > eps ||
        fabs(side3 - side4) > eps) {
        return false;
    }
    
    // Площадь должна быть положительной
    if (calcArea() <= 1e-6) {
        return false;
    }
    
    return true;
}