// Version de IntStack avec des mémoires dynamiques

#pragma once

#include <iostream>
#include <stdexcept>
#include <cstdlib>

class IntStack
{
private:
    int size;   // taille de la pile
    int length; // nombre d'éléments dans la pile
    int *pi;    // adresse du premier élément de notre pile

public:
    IntStack(int s);                        // constructeur
    ~IntStack();                            // destructeur : méthode appelée quand on sort du scope, supprime dans le heap automatiquement
    IntStack(const IntStack &r);            // copy CONSTRUCTOR : prend en argument l'objet à copier (par défaut, c++ peut "créer" un IntStack par copie, mais on le def nous même pour avec une nouvelle adresse mémoire)
    IntStack &operator=(const IntStack &r); // assignment OPERATOR : t1=t2 càd t1.operator=(t2)
    void push(int e);
    int get_top() const;
    int pop();
    bool is_empty() const;
    bool is_full() const;
    void print() const;
};

inline IntStack::IntStack(int s) : length(0), size(s)
{
    if (s <= 0)
    {
        throw std::invalid_argument("On essaye de créer une pile de taille négative");
    };
    pi = new int[size]; // tableau de taille max size
}

inline IntStack::~IntStack()
{
    delete[] pi;
}

inline IntStack::IntStack(const IntStack &r) : length(r.length), size(r.size), pi(new int[size])
{
    for (int i = 0; i < length; i++)
    {
        pi[i] = r.pi[i];
    }
}

inline IntStack &IntStack::operator=(const IntStack &r)
{
    if (this != &r) // toujours tester si on n'a pas une auto affectation (t=t)
    {               // this est le pointeur vers l'objet sur leqeuel l'opérateur est appelé
        size = r.size;
        length = r.length;
        delete[] pi; // on supprime l'ancienne adresse dans le tas
        pi = new int[size];
        for (int i = 0; i < length; i++)
        {
            pi[i] = r.pi[i];
        }
    }
    return *this; // toujours renvoyer l'objet pour chaîner les affectations (t1=t2=t3)
}

inline void IntStack::push(int e)
{
    // cette fonction ajoute l'entier e dans la pile
    if (is_full())
    {
        throw std::overflow_error("On essaye d'empiler sur une pile pleine");
    }
    *(pi + length) = e; // pi est l'adresse mémoire du premier élément du tableau, pi+length donne automatiquement l'adresse de l'élément d'indice length, on rajoute l'étoile pour accéder à cet élément
    length += 1;
}

inline int IntStack::get_top() const
{
    // cette fonction retourne le dernier entier empilé
    if (is_empty())
    {
        throw std::underflow_error("On essaye de dépiler une pile vide");
    }
    return *(pi + (length - 1));
}

inline int IntStack::pop()
{
    // cette fonction retourne le dernier entier empilé et le supprime de la pile
    int top{get_top()};
    length -= 1;
    return top;
}

inline bool IntStack::is_empty() const
{
    return length == 0;
}

inline bool IntStack::is_full() const
{
    return length == size;
}

inline void IntStack::print() const
{
    // cette fonction affiche la pile, par exemple
    // [1 2 3 [ pour dire que 3 entiers sont dans la pile
    std::cout << '[';
    for (int k = 0; k < length; k++)
    {
        std::cout << ' ' << *(pi + k) << ' ';
    }
    std::cout << '[' << std::endl;
}

std::ostream &operator<<(std::ostream &os, const IntStack &pile)
{
    pile.print();
    return os;
}