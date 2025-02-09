#include <iostream>
#include "intstack_dynsize.h"

int main()
{
    int size;
    std::cout << "Choisir la taille de la pile : ";
    std::cin >> size;
    IntStack s1(size);
    for (int k = 1; k <= 3; k++)
    {
        s1.push(k);
    }
    IntStack s2 = s1; // utilisation du copy constructor
    s1.push(10);
    s1.print();
    s2.push(20);
    s1.print();
    s2.print();
    return 0;
}
