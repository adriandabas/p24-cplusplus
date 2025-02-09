#pragma once

#include <iostream>

int pgcd(int a, int b) // ou static int
{
    while (a % b != 0)
    {
        int x = a;
        a = b;
        b = x % b;
    }
    return b;
}

class Rational
{
private:
    int num;
    int denom;

public:
    Rational(int n = 0, int d = 1) : num{n}, denom{d}
    {
        if (denom == 0)
        {
            throw std::invalid_argument("Le dénominateur ne peut pas être nul");
        }
        reduire();
    }
    void reduire()
    {
        int p = pgcd(num, denom);
        num = num / p;
        denom = denom / p;
    }
    operator float() const // float(r) renvoie la valeur de la fraction
    {
        return static_cast<float>(num) / denom; // static_cast<targeted-type> pour ne pas avoir de conversion (sinon obtient un int car on divise 2 int)
    }

    friend Rational operator+(const Rational &r1, const Rational &r2);    // operateur addition
    friend std::ostream &operator<<(std::ostream &os, const Rational &r); // operateur print
    friend bool operator==(const Rational &r1, const Rational &r2);       // opérateur égalité
};

Rational operator+(const Rational &r1, const Rational &r2)
{
    return Rational(r1.num * r2.denom + r1.denom * r2.num, r1.denom * r2.denom);
}

std::ostream &operator<<(std::ostream &os, const Rational &r)
{
    os << r.num << '/' << r.denom;
    return os;
}

bool operator==(const Rational &r1, const Rational &r2)
{
    return r1.num * r2.denom == r1.denom * r2.num;
}
