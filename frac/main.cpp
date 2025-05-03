#include "fraction.h"
#include <iostream>
using namespace std;

int main() {
    Fraction a, b;

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
    (a / b).output();

    return 0;
}
