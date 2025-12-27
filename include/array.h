#ifndef ARRAY_H
#define ARRAY_H

#include "figure.h"

class Array {
    Figure** data;
    size_t size;
    size_t capacity;
    
    void resize(size_t new_capacity);
public:
    Array();
    Array(size_t initial_capacity);
    ~Array();
    
    void pushBack(Figure* figure); //доб кон
    void removeAt(size_t index); //уд по инд
    Figure* operator[](size_t index) const; //доступ по инд
    size_t getSize() const; //пол размм
    
    double totalArea() const; 
};

#endif