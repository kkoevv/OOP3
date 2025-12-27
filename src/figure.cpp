#include "../include/figure.h"
#include <cmath>

Figure::Figure(int numOfPoints) { 
    points.resize(numOfPoints); 
}

Figure::Figure(const std::initializer_list<Point> &t) { 
    points.assign(t); 
}

std::ostream &operator<<(std::ostream &os, const Figure &figure) {
    os << "Точки фигуры:\n";
    for (size_t i = 0; i < figure.points.size(); i++) {
        os << figure.points[i] << ' ';
    }
    os << '\n';
    return os;
}

Figure::operator double() const { 
    return calcArea(); 
}

double Figure::calcArea() const { 
    return std::abs(calcAreaSigned()); 
}

double Figure::calcAreaSigned() const {
    double s = 0;
    for (size_t i = 0; i < points.size(); i++) {
        size_t j = (i + 1) % points.size();
        s += points[i][0] * points[j][1] - points[j][0] * points[i][1];
    }
    return s / 2;
}

Point Figure::calcGeometricCenter() const {
    double a = calcAreaSigned();
    double cx = 0, cy = 0;
    for (size_t i = 0; i < points.size(); i++) {
        size_t j = (i + 1) % points.size();
        double cross = points[i][0] * points[j][1] - points[j][0] * points[i][1];
        cx += (points[i][0] + points[j][0]) * cross;
        cy += (points[i][1] + points[j][1]) * cross;
    }
    cx /= (6 * a);
    cy /= (6 * a);
    return Point(cx, cy);
}

std::istream &operator>>(std::istream &is, Figure &figure) {
    std::streampos start = is.tellg();
    std::istream &result = figure.read(is);
    
    if (!is.fail()) {
        if (!figure.isValidRotationFigure()) {
            is.setstate(std::ios::failbit);
            is.clear();
            is.seekg(start);
        }
    }
    
    return result;
}

bool Figure::operator==(const Figure &other) const {
    if (points.size() != other.points.size()) return false;
    for (size_t i = 0; i < points.size(); i++) {
        if (!(points[i] == other.points[i])) return false;
    }
    return true;
}

std::istream &Figure::readPoints(std::istream &is, int pointNum) {
    points.resize(pointNum);
    for (int i = 0; i < pointNum; i++) {
        if (!(is >> points[i])) {
            break;
        }
    }
    return is;
}

std::istream &Figure::read(std::istream &is) {
    return readPoints(is, getNumOfPoints());
}