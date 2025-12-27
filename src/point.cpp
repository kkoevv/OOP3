#include "../include/point.h"

Point::Point() : x(0), y(0) {}
Point::Point(double x, double y) : x(x), y(y) {}

double& Point::operator[](size_t index) {
    assert((index == 0) || (index == 1));
    return (index == 0) ? x : y;
}

double Point::operator[](size_t index) const {
    assert((index == 0) || (index == 1));
    return (index == 0) ? x : y;
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << '(' << p[0] << ", " << p[1] << ')';
    return os;
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p[0] >> p[1];
    return is;
}

bool Point::operator==(const Point &other) const {
    const double eps = 1e-6;
    return fabs(x - other.x) < eps && fabs(y - other.y) < eps;
}