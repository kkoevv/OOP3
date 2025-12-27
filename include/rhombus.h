#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"

class Rhombus : public Figure {
    Point points[4];
public:
    Rhombus() = default;
    Rhombus(const Rhombus& other);
    Rhombus(Rhombus&& other) noexcept;
    Rhombus& operator=(const Rhombus& other);
    Rhombus& operator=(Rhombus&& other) noexcept;
    ~Rhombus() override = default;
    bool operator==(const Rhombus& other) const;
    bool operator!=(const Rhombus& other) const;

    Point geometricCenter() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
};

#endif