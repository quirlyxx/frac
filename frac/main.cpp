#include "fraction.h"
#include <iostream>
using namespace std;

int main() {
    /*Fraction a, b;

    cout << "Enter first fraction:\n";
    a.input();

    cout << "Enter second fraction:\n";
    b.input();

    cout << "\nSum: ";
    (a + b).output();

    cout << "Difference: ";
    (a - b).output();

    cout << "Product: ";
    (a * b).output();

    cout << "Quotient: ";
    (a / b).output();*/

    Fraction a;

    cout << "Enter a fraction:\n";
    a.input();

    a.saveToBinary("fraction.bin");
    cout << "Fraction saved to binary file.\n";

    Fraction b;
    b.loadFromBinary("fraction.bin");
    cout << "Fraction loaded from binary file: ";
    b.output();

    return 0;
}
