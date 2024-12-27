#include <iostream>

int pgcd(int a, int b) // ou static int...
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
    Rational(int n = {}, int d = (1)) : num{n}, denom{d} { reduire(); }
    void reduire()
    {
        int p = pgcd(num, denom);
        num = num / p;
        denom = denom / p;
    }
    operator float() const // float(r) ou r.operator float() renvoie la valeur de la fraction
    {
        return static_cast<float>(num) / denom;
    }

    friend Rational operator+(const Rational &r1, const Rational &r2);    // operateur addition
    friend std::ostream &operator<<(std::ostream &os, const Rational &r); // operateur print
    friend void test(Rational, Rational);
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

void test(Rational r1, Rational r2)
{
    bool t{r1.num * r2.denom == r1.denom * r2.num};
    std::cout << t << std::endl;
}

int main()
{
    Rational r1;
    Rational r2(1);
    Rational r3(4, 6);
    Rational r4(1, 2);
    Rational r5 = r3 + r4;
    std::cout << r1 << ' ' << r2 << std::endl;
    std::cout << r3 << " + " << r4 << " = " << r5 << std::endl;
    return 0;
}