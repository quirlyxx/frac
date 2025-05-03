#include "fraction.h"
#include <iostream>
using namespace std;

int Fraction::reduct(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

Fraction::Fraction() : numerator(0), denominator(1) {}
Fraction::Fraction(int num, int den) : numerator(num), denominator(den == 0 ? 1 : den) {}

void Fraction::input() {
    cout << "Enter numerator: ";
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;
    while (denominator == 0) {
        cout << "Denominator can't be zero. Try again: ";
        cin >> denominator;
    }
}

void Fraction::output() {
    int divisor = reduct(numerator, denominator);
    cout << numerator / divisor << "/" << denominator / divisor << endl;
}
Fraction Fraction::operator+(const Fraction& other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction::operator-(const Fraction& other) const {
    int num = numerator * other.denominator - other.numerator * denominator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction::operator*(const Fraction& other) const {
    int num = numerator * other.numerator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction::operator/(const Fraction& other) const {
    int num = numerator * other.denominator;
    int den = denominator * other.numerator;
    return Fraction(num, den);
}
