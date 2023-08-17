#include "Circle.h"
#include <iostream>

using namespace std;

int main() {
    try {
        double radius;

        cout << "Digite o raio do circulo: ";
        cin >> radius;
    
        Circle circle(radius);

        circle.imprime_area();
    }
    catch (const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
