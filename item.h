#ifndef OOP_LAB1_ITEM_H
#define OOP_LAB1_ITEM_H


#include <cmath>

class Figure {
public:
    virtual double getPerimeter() const = 0;
    virtual double getArea() const = 0;
    virtual void getBoundingRectangle(double& width, double& height) const = 0;
    virtual ~Figure() = default;
};

class Circle : public Figure {
private:
    double _radius;

public:
    // Constructor
    explicit Circle(double radius) : _radius(radius) {}

    // Getters
    double getPerimeter() const override {
        return 2 * 3.14159 * _radius;
    }
    double getArea() const override {
        return 3.14159 * _radius * _radius;
    }

    // Get the bounding rectangle of the circle
    void getBoundingRectangle(double& width, double& height) const override {
        width = 2 * _radius;
        height = 2 * _radius;
    }
};

class Triangle : public Figure {
private:
    double _side1;
    double _side2;
    double _side3;

public:
    // Constructor
    Triangle(double side1, double side2, double side3)
            : _side1(side1), _side2(side2), _side3(side3) {}

    // Getters
    double getPerimeter() const override {
        return _side1 + _side2 + _side3;
    }
    double getArea() const override {
        double p = getPerimeter() / 2;
        return std::sqrt(p * (p - _side1) * (p - _side2) * (p - _side3));
    }

    // Get the bounding rectangle of the triangle
    void getBoundingRectangle(double& width, double& height) const override {
        width = std::max(_side1, std::max(_side2, _side3));
        height = getArea() / width;
    }

    // Check if the triangle is valid
    bool isTriangleValid() const {
        return (_side1 + _side2 > _side3) && (_side1 + _side3 > _side2) && (_side2 + _side3 > _side1);
    }
};

class Rectangle : public Figure {
private:
    double _width;
    double _height;

public:
    // Constructor
    Rectangle(double width, double height) : _width(width), _height(height) {}

    // Getters
    double getPerimeter() const override {
        return 2 * (_width + _height);
    }
    double getArea() const override {
        return _width * _height;
    }

    // Get the bounding rectangle of the rectangle
    void getBoundingRectangle(double& width, double& height) const override {
        width = _width;
        height = _height;
    }
};


#endif //OOP_LAB1_ITEM_H
