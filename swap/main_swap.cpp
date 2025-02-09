#include <iostream>
#include "swap.h"

int main()
{
    int a{12};
    int b{81};
    std::cout << "Initialement : " << 'a' << '=' << a << " et " << 'b' << '=' << b << std::endl;
    // swap_pointer(&a,&b);
    swap_reference(a, b);
    std::cout << "Après le swap : " << 'a' << '=' << a << " et " << 'b' << '=' << b << std::endl;
    return 0;
}
