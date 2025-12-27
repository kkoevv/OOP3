#include <iostream>
#include "array.h"
#include "trapezoid.h"
#include "rhombus.h"
#include "pentagon.h"
#include "figure.h"

int main() {
    Array figures;
    std::string command;
    
    while(std::cin >> command) {
        if(command == "trapezoid") {
            Trapezoid* t = new Trapezoid();
            std::cin >> *t;
            figures.pushBack(t);
        }
        else if(command == "rhombus") {
            Rhombus* r = new Rhombus();
            std::cin >> *r;
            figures.pushBack(r);
        }
        else if(command == "pentagon") {
            Pentagon* p = new Pentagon();
            std::cin >> *p;
            figures.pushBack(p);
        }
        else if(command == "print") {
            for(size_t i = 0; i < figures.getSize(); ++i) {
                std::cout << *figures[i] << std::endl;
                Point center = figures[i]->geometricCenter();
                std::cout << "Center: (" << center.x << ", " << center.y << ")" << std::endl;
                std::cout << "Area: " << figures[i]->area() << std::endl;
            }
        }
        else if(command == "total_area") {
            std::cout << "Total area: " << figures.totalArea() << std::endl;
        }
        else if(command == "remove") {
            size_t index;
            std::cin >> index;
            figures.removeAt(index);
        }
        else if(command == "exit") {
            break;
        }
    }
    
    return 0;
}