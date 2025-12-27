#include "trapezoid.h"
#include "figure.h"
#include <cmath>

Trapezoid::Trapezoid(const Trapezoid& other) {
    for(int i = 0; i < 4; ++i) points[i] = other.points[i];
}

Trapezoid::Trapezoid(Trapezoid&& other) noexcept {
    for(int i = 0; i < 4; ++i) points[i] = std::move(other.points[i]);
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if(this != &other) {
        for(int i = 0; i < 4; ++i) points[i] = other.points[i];
    }
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if(this != &other) {
        for(int i = 0; i < 4; ++i) points[i] = std::move(other.points[i]);
    }
    return *this;
}

Point Trapezoid::geometricCenter() const {
    double x = 0, y = 0;
    for(int i = 0; i < 4; ++i) {
        x += points[i].x;
        y += points[i].y;
    }
    return Point(x/4, y/4);
}

double Trapezoid::area() const {
    double area = 0;
    for(int i = 0; i < 4; ++i) {
        int j = (i + 1) % 4;
        area += points[i].x * points[j].y - points[j].x * points[i].y;
    }
    return std::abs(area) / 2;
}

void Trapezoid::print(std::ostream& os) const {
    os << "Trapezoid: ";
    for(int i = 0; i < 4; ++i) {
        os << "(" << points[i].x << ", " << points[i].y << ") ";
    }
}

void Trapezoid::read(std::istream& is) {
    for(int i = 0; i < 4; ++i) {
        is >> points[i].x >> points[i].y;
    }
}

bool Trapezoid::operator==(const Trapezoid& other) const {
    for (int i = 0; i < 4; ++i) {
        if (std::abs(points[i].x - other.points[i].x) > EPS ||
            std::abs(points[i].y - other.points[i].y) > EPS) {
            return false;
        }
    }
    return true;
}

bool Trapezoid::operator!=(const Trapezoid& other) const {
    return !(*this == other);
}