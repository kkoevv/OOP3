#include "pentagon.h"
#include "figure.h"
#include <cmath>

Pentagon::Pentagon(const Pentagon& other) {
    for(int i = 0; i < 5; ++i) points[i] = other.points[i];
}

Pentagon::Pentagon(Pentagon&& other) noexcept {
    for(int i = 0; i < 5; ++i) points[i] = std::move(other.points[i]);
}

Pentagon& Pentagon::operator=(const Pentagon& other) {
    if(this != &other) {
        for(int i = 0; i < 5; ++i) points[i] = other.points[i];
    }
    return *this;
}

Pentagon& Pentagon::operator=(Pentagon&& other) noexcept {
    if(this != &other) {
        for(int i = 0; i < 5; ++i) points[i] = std::move(other.points[i]);
    }
    return *this;
}

Point Pentagon::geometricCenter() const {
    double x = 0, y = 0;
    for(int i = 0; i < 5; ++i) {
        x += points[i].x;
        y += points[i].y;
    }
    return Point(x/5, y/5);
}

double Pentagon::area() const {
    // формула шнурования
    double area = 0;
    for(int i = 0; i < 5; ++i) {
        int j = (i + 1) % 5;
        area += (points[i].x * points[j].y - points[j].x * points[i].y);
    }
    return std::abs(area) / 2;
}

void Pentagon::print(std::ostream& os) const {
    os << "Pentagon: ";
    for(int i = 0; i < 5; ++i) {
        os << "(" << points[i].x << ", " << points[i].y << ") ";
    }
}

void Pentagon::read(std::istream& is) {
    for(int i = 0; i < 5; ++i) {
        is >> points[i].x >> points[i].y;
    }
}

bool Pentagon::operator==(const Pentagon& other) const {
    for (int i = 0; i < 5; ++i) {
        if (points[i].x != other.points[i].x || points[i].y != other.points[i].y) {
            return false;
        }
    }
    return true;
}

bool Pentagon::operator!=(const Pentagon& other) const {
    return !(*this == other);
}