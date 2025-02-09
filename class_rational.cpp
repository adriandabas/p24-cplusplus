#include <iostream>
#include "class_rational.h"

int main()
{
    Rational r1;
    Rational r2(1);
    Rational r3(4, 0);
    Rational r4(1, 2);
    Rational r5 = r3 + r4;
    std::cout << r1 << ' ' << r2 << std::endl;
    std::cout << r3 << " + " << r4 << " = " << r5 << std::endl;
    std::cout << "Opérateur float : " << float(r3) << std::endl;
    std::cout << "Opérateur égalité : " << (r3 == r4) << std::endl; // attention il faut rajouter des parenthèses () car l'opérateur << a une priorité supérieure à ==
    return 0;
}