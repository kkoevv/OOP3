#include "array.h"
#include <stdexcept>

Array::Array() : data(nullptr), size(0), capacity(0) {}

Array::Array(size_t initial_capacity) : size(0), capacity(initial_capacity) {
    data = new Figure*[capacity];
}

Array::~Array() {
    for(size_t i = 0; i < size; ++i) {
        delete data[i];
    }
    delete[] data;
}

void Array::resize(size_t new_capacity) {
    Figure** new_data = new Figure*[new_capacity];
    for(size_t i = 0; i < size; ++i) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

void Array::pushBack(Figure* figure) {
    if(size >= capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = figure;
}

void Array::removeAt(size_t index) {
    if(index >= size) {
        throw std::out_of_range("Index out of range");
    }
    delete data[index];
    for(size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

Figure* Array::operator[](size_t index) const {
    if(index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

size_t Array::getSize() const {
    return size;
}

double Array::totalArea() const {
    double total = 0;
    for(size_t i = 0; i < size; ++i) {
        total += data[i]->area();
    }
    return total;
}