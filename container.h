#ifndef OOP_LAB1_CONTAINER_H
#define OOP_LAB1_CONTAINER_H


#include <stdexcept>
#include "item.h"

class Container {
private:
    static const size_t MAX_SIZE = 100; // Define a maximum size for the array
    Figure* figures[MAX_SIZE];
    size_t size = 0;

public:
    // Destructor: free memory of the figures
    ~Container() {
        for (size_t i = 0; i < size; ++i) {
            delete figures[i];
        }
    }

    // Get the size of the array
    size_t getSize() const {
        return size;
    }

    // Get the figure at the specified index
    Figure* operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return figures[index];
    }

    // Get the figure at the specified index
    Figure*& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return figures[index];
    }

    // Add a figure to the end of the array
    void insertAt(size_t index, Figure* figure) {
        if (size == MAX_SIZE) {
            throw std::out_of_range("Array is full");
        }
        if (index > size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = size; i > index; --i) {
            figures[i] = figures[i - 1];
        }
        figures[index] = figure;
        ++size;
    }

    // Remove a figure from the array
    void removeAt(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        delete figures[index];
        for (size_t i = index; i < size - 1; ++i) {
            figures[i] = figures[i + 1];
        }
        --size;
    }
};


#endif //OOP_LAB1_CONTAINER_H
