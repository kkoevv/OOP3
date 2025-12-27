#include "rhombus.h"
#include "figure.h"
#include <cmath>

Rhombus::Rhombus(const Rhombus& other) {
    for(int i = 0; i < 4; ++i) points[i] = other.points[i];
}

Rhombus::Rhombus(Rhombus&& other) noexcept {
    for(int i = 0; i < 4; ++i) points[i] = std::move(other.points[i]);
}

Rhombus& Rhombus::operator=(const Rhombus& other) {
    if(this != &other) {
        for(int i = 0; i < 4; ++i) points[i] = other.points[i];
    }
    return *this;
}

Rhombus& Rhombus::operator=(Rhombus&& other) noexcept {
    if(this != &other) {
        for(int i = 0; i < 4; ++i) points[i] = std::move(other.points[i]);
    }
    return *this;
}

Point Rhombus::geometricCenter() const {
    double x = 0, y = 0;
    for(int i = 0; i < 4; ++i) {
        x += points[i].x;
        y += points[i].y;
    }
    return Point(x/4, y/4);
}

double Rhombus::area() const {
    double d1 = std::sqrt(std::pow(points[2].x - points[0].x, 2) + 
                         std::pow(points[2].y - points[0].y, 2));
    double d2 = std::sqrt(std::pow(points[3].x - points[1].x, 2) + 
                         std::pow(points[3].y - points[1].y, 2));
    return d1 * d2 / 2;
}

void Rhombus::print(std::ostream& os) const {
    os << "Rhombus: ";
    for(int i = 0; i < 4; ++i) {
        os << "(" << points[i].x << ", " << points[i].y << ") ";
    }
}

void Rhombus::read(std::istream& is) {
    for(int i = 0; i < 4; ++i) {
        is >> points[i].x >> points[i].y;
    }
}

bool Rhombus::operator==(const Rhombus& other) const {
    for (int i = 0; i < 4; ++i) {
        if (std::abs(points[i].x - other.points[i].x) > EPS ||
            std::abs(points[i].y - other.points[i].y) > EPS) {
            return false;
        }
    }
    return true;
}

bool Rhombus::operator!=(const Rhombus& other) const {
    return !(*this == other);
}