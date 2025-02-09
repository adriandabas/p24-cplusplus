#pragma once

#include <iostream>
#include <stdexcept>
#include <cstdlib>

// constante entière pour la taille de la pile
const int SIZE{12};

class IntStack
{
private:
    // dans cette version toutes les piles sont de taille SIZE
    int pile[SIZE];
    int length{}; // nombre d'éléments dans la pile, initialement nul

public:
    void push(int e);
    int get_top() const; // on précise que la méthode ne modifie pas l'objet appelé, on peut alors l'appeler sur un object constant
    int pop();
    bool is_empty() const;
    bool is_full() const;
    void print() const;
};

inline void IntStack::push(int e)
{
    // cette fonction ajoute l'entier e dans la pile
    if (is_full()) // revient à écrire (is_full()==1)
    {
        throw std::overflow_error("On essaye d'empiler sur une pile pleine");
    }
    pile[length] = e;
    length += 1;
}

inline int IntStack::get_top() const
{
    // cette fonction retourne le dernier entier empilé
    if (is_empty())
    {
        throw std::underflow_error("On essaye de dépiler une pile vide");
    }
    return pile[length - 1];
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
    // cette fonction teste si la pile est vide
    return length == 0;
}

inline bool IntStack::is_full() const
{
    // cette fonction teste si la pile est pleine, il y a SIZE entiers dans la pile
    return length == SIZE;
}

inline void IntStack::print() const
{
    // cette fonction affiche la pile, par exemple
    // [1 2 3 [ pour dire que 3 entiers sont dans la pile
    std::cout << '[';
    for (int k = 0; k < length; k++)
    {
        std::cout << ' ' << pile[k] << ' ';
    }
    std::cout << '[' << std::endl;
}

std::ostream &operator<<(std::ostream &os, const IntStack &pile)
{
    pile.print();
    return os;
}
