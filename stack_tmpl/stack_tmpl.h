// Une classe Stack plus générale en utilisant des TEMPLATES

#pragma once

#include <iostream>
#include <stdexcept>
#include <cstdlib>

template <typename T, int SIZE> // on va pouvoir choisir le type des objets contenus dans la pile et sa taille
class Stack
{
private:
    T pile[SIZE];
    int length{}; // nombre d'éléments dans la pile, initialement vide

public:
    void push(int e);
    T get_top() const;
    T pop();
    bool is_empty() const;
    bool is_full() const;
    void print() const;
};

template <typename T, int SIZE> // on doit rappeler template avant chaque chaque définition
inline void Stack<T, SIZE>::push(int e)
{
    // cette fonction ajoute l'entier e dans la pile
    if (is_full())
    {
        throw std::overflow_error("On essaye d'empiler sur une pile pleine");
    }
    pile[length] = e;
    length += 1;
}

template <typename T, int SIZE>
inline T Stack<T, SIZE>::get_top() const
{
    // cette fonction retourne le dernier entier empilé
    if (is_empty())
    {
        throw std::underflow_error("On essaye de dépiler une pile vide");
    }
    return pile[length - 1];
}

template <typename T, int SIZE>
inline T Stack<T, SIZE>::pop()
{
    // cette fonction retourne le dernier entier empilé et le supprime de la pile
    T top{get_top()};
    length -= 1;
    return top;
}

template <typename T, int SIZE>
inline bool Stack<T, SIZE>::is_empty() const
{
    // cette fonction teste si la pile est vide
    return length == 0;
}

template <typename T, int SIZE>
inline bool Stack<T, SIZE>::is_full() const
{
    // cette fonction teste si la pile est pleine, il y a SIZE entiers dans la pile
    return length == SIZE;
}

template <typename T, int SIZE>
inline void Stack<T, SIZE>::print() const
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

template <typename T, int SIZE>
std::ostream &operator<<(std::ostream &os, const Stack<T, SIZE> &pile)
{
    pile.print();
    return os;
}