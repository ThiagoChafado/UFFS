#include "Circle.h"
#include <iostream>

using namespace std;

Circle::Circle(double radius) {
    if (radius <= 0) {
        throw(invalid_argument("Erro no construtor Circle(double): o radius " +
            to_string(radius) + " eh invalido!"));
    }

    radius_ = radius;
}

double Circle::calcula_area() {
    return (3.1416 * radius_ * radius_);
}

void Circle::imprime_area() {
    cout << "Area: " + to_string(calcula_area()) + "\n";
}
