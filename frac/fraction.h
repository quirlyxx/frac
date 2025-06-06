#pragma once

class Fraction {
private:
    int numerator;
    int denominator;

    int reduct(int a, int b);

public:
    Fraction();
    Fraction(int num, int den);

    void input();
    void output();

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    inline int getNumerator() { return numerator; }
    inline int getDenominator() { return denominator; }

    void saveToBinary(const char* filename) const;
    void loadFromBinary(const char* filename);

};




