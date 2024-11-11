#include <iostream>

void swap(float* pf, float* pg) { //notre fonction prend en argument des ADRESSES MÉMOIRE, void signifie qu'elle ne renvoie rien
    float t = (*pf);
    (*pf)=(*pg);
    (*pg)=t;
}

int main() {
    float f {7.24}; //équivalent à f=7.24
    float g {}; //g=0
    float* pf=&f; 
    float* pg=&g;
    swap(pf,pg);
    std::cout << f << ' ' << g << std::endl;
    return 0;
}
