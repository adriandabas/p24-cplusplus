#pragma once

void swap_pointer(int *pf, int *pg) // notre fonction prend en argument des ADRESSES MÉMOIRE qui sont COPIÉES, void signifie qu'elle ne renvoie rien
{
    int t = (*pf);
    (*pf) = (*pg);
    (*pg) = t;
}

void swap_reference(int &f, int &g) //entiers passés par référence
{
    int t = f;
    f = g;
    g = t;
}