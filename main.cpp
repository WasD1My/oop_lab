#include <iostream>
#include "container.h"

int main() {
    Container container;
    int choice;
    do {
        std::cout << "\n1. Add a Circle\n"
                  << "2. Add a Rectangle\n"
                  << "3. Add a Triangle\n"
                  << "4. Remove a figure\n"
                  << "5. Display Areas\n"
                  << "6. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double radius;
                std::cout << "Enter radius of the circle: ";
                std::cin >> radius;
                Circle* circle = new Circle(radius);
                container.insertAt(container.getSize(), circle);
                break;
            }
            case 2: {
                double width, height;
                std::cout << "Enter width and height of the rectangle: ";
                std::cin >> width >> height;
                Rectangle* rectangle = new Rectangle(width, height);
                container.insertAt(container.getSize(), rectangle);
                break;
            }
            case 3: {
                double side1, side2, side3;
                std::cout << "Enter the sides of the triangle: ";
                std::cin >> side1 >> side2 >> side3;
                Triangle* triangle = new Triangle(side1, side2, side3);
                container.insertAt(container.getSize(), triangle);
                break;
            }
            case 4: {
                size_t index;
                std::cout << "Enter the index of the figure to remove (starting from 0): ";
                std::cin >> index;
                container.removeAt(index);
                break;
            }
            case 5: {
                for (size_t i = 0; i < container.getSize(); ++i) {
                    std::cout << "Area of figure " << i << ": " << container[i]->getArea() << "\n";
                }
                break;
            }
            case 6: {
                std::cout << "Exiting...\n";
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 6);

    return 0;
}
