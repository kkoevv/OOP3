#pragma once

#include "point.h"
#include <initializer_list>
#include <iostream>
#include <vector>
#include <cmath>

class Figure {
protected:
    Figure() = default;
    Figure(int numOfPoints);
    Figure(const std::initializer_list<Point> &t);
    Figure(const Figure &other) = default;
    Figure(Figure &&other) noexcept = default;
    Figure &operator=(const Figure &other) = default;
    Figure &operator=(Figure &&other) = default;

    std::istream& read(std::istream &is);
    std::istream& readPoints(std::istream &is, int pointNum);
    
public:
    bool operator==(const Figure &other) const;

    Point calcGeometricCenter() const;
    double calcArea() const;
    double calcAreaSigned() const;
    explicit operator double() const;

    friend std::ostream &operator<<(std::ostream &os, const Figure &figure);
    friend std::istream &operator>>(std::istream &is, Figure &figure);

    virtual int getNumOfPoints() const = 0;
    virtual bool isValidRotationFigure() const = 0;
    
    virtual ~Figure() = default;
    
protected:
    const std::vector<Point>& getPoints() const { return points; }
    Point getPoint(size_t index) const { 
        if (index < points.size()) return points[index];
        return Point();
    }
    
private:
    std::vector<Point> points;
};