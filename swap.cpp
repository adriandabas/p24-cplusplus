#include <iostream>

void swap_pointer(int* pf, int* pg) { //notre fonction prend en argument des ADRESSES MÉMOIRE, void signifie qu'elle ne renvoie rien
    int t = (*pf);
    (*pf)=(*pg);
    (*pg)=t;
}

void swap_reference(int& f, int& g) {
    int t=f;
    f=g;
    g=t;
}

int main() {
    int a {12}; 
    int b {81};
    //swap_pointer(&a,&b);
    swap_reference(a,b);
    std::cout << 'a' << '=' << a << " et " << 'b' << '=' << b << std::endl;
    return 0;
}
