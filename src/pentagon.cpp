#include "../include/pentagon.h"
#include "../include/point.h"
#include <initializer_list>
#include <cmath>
#include <vector>

Pentagon::Pentagon() : Figure(numOfPoints) {}

Pentagon::Pentagon(const std::initializer_list<Point> &t) : Figure(t) {}

Pentagon::Pentagon(const Pentagon &other) : Figure(other) {}
Pentagon::Pentagon(Pentagon &&other) : Figure(std::move(other)) {}

Pentagon &Pentagon::operator=(const Pentagon &other) {
    Figure::operator=(other);
    return *this;
}

Pentagon &Pentagon::operator=(Pentagon &&other) {
    Figure::operator=(std::move(other));
    return *this;
}

bool Pentagon::operator==(const Pentagon &other) const {
    return Figure::operator==(other);
}

bool Pentagon::isValidRotationFigure() const {
    const std::vector<Point>& pts = getPoints();
    if (pts.size() != 5) return false;
    
    // 1. Проверяем, что нет совпадающих точек
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (getPoint(i) == getPoint(j)) {
                return false;
            }
        }
    }
    
    // 2. Проверяем, что площадь положительная
    if (calcArea() <= 1e-6) {
        return false;
    }
    
    return true;
}