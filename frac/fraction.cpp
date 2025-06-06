#include "fraction.h"
#include <iostream>
#include <fstream>
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

void Fraction::saveToBinary(const char* filename) const {
    std::ofstream out(filename, std::ios::binary);
    if (!out) {
        std::cout << "Failed to open file for binary writing.\n";
        return;
    }

    out.write((char*)&numerator, sizeof(numerator));
    out.write((char*)&denominator, sizeof(denominator));

    out.close();
}

void Fraction::loadFromBinary(const char* filename) {
    std::ifstream in(filename, std::ios::binary);
    if (!in) {
        std::cout << "Failed to open file for binary reading.\n";
        return;
    }

    in.read((char*)&numerator, sizeof(numerator));
    in.read((char*)&denominator, sizeof(denominator));

    if (denominator == 0) {
        std::cout << "Loaded denominator is zero. Setting to 1.\n";
        denominator = 1;
    }

    in.close();
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
