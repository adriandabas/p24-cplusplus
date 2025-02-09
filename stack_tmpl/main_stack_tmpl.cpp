#include <iostream>
#include "stack_tmpl.h"

int main()
{
    Stack<char, 12> s1;
    s1.print();
    s1.push('a');
    s1.push('b');
    s1.push('c');
    s1.print();                     
    std::cout << s1.pop() << std::endl;
    s1.print();                     
    return 0;
}