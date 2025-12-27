#ifndef PENTAGON_H
#define PENTAGON_H

#include "figure.h"

class Pentagon : public Figure {
    Point points[5];
public:
    Pentagon() = default;
    Pentagon(const Pentagon& other);
    Pentagon(Pentagon&& other) noexcept;
    Pentagon& operator=(const Pentagon& other);
    Pentagon& operator=(Pentagon&& other) noexcept;
    ~Pentagon() override = default;
    bool operator==(const Pentagon& other) const;
    bool operator!=(const Pentagon& other) const;
    
    Point geometricCenter() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
};

#endif