#include <iostream>
#include <stdexcept>
#include <cstdlib>

// constante entière pour la taille de la pile
const int SIZE{12};

// on définit un type de donnée (une classe) pour gérer une pile d'entier de taille 12 (SIZE)
class IntStack
{
private:
    // vos attributs pour représenter la pile d'entier
    // dans cette version toutes les piles sont de taille SIZE
    // votre code ici
    int pile[SIZE];
    int length{}; // nombre d'éléments dans la pile

public:
    void push(int e)
    {
        // cette fonction ajoute l'entier e dans la pile
        // votre code ici
        if (is_full()) // revient à écrire (is_full()==1)
        {
            exit(EXIT_FAILURE);
        }
        pile[length] = e;
        length += 1;
    }
    int get_top() const // on précise que la méthode ne modifie pas l'objet appelé, on peut alors l'appeler sur un object constant
    {
        // cette fonction retourne le dernier entier empilé
        // votre code ici
        if (is_empty())
        {
            exit(EXIT_FAILURE);
        }
        return pile[length - 1];
    }
    int pop()
    {
        // cette fonction retourne le dernier entier empilé
        // et supprime cet entier de la pile
        // votre code ici
        int top{get_top()};
        length -= 1;
        return top;
    }
    bool is_empty() const
    {
        // cette fonction teste si la pile est vide
        // votre code ici
        if (length == 0)
        {
            return 1; // True
        }
        return 0;
    }
    bool is_full() const
    {
        // cette fonction teste si la pile est pleine
        // il y a SIZE entiers dans la pile
        // votre code ici
        if (length == SIZE)
        {
            return 1;
        }
        return 0;
    }
    void print() const
    {
        // cette fonction affiche la pile, par exemple
        // [1 2 3 [ pour dire que 3 entiers sont dans la pile
        // le dernier empilé est 3
        // votre code ici
        std::cout << '[';
        for (int k = 0; k < length; k++)
        {
            std::cout << ' ' << pile[k] << ' ';
        }
        std::cout << '[' << std::endl;
    }

    friend std::ostream &operator<<(std::ostream &os, const IntStack &pile);
};

/* std::ostream &operator<<(std::ostream &os, const IntStack &pile) {
    os << pile.print();
    return os;
} */

// 1. réaliser le code pour faire fonctionner cette pile d'entier de taille fixée à la compilation
// 2. quelles sont les méthodes qui ne modifient pas l'objet sur lequel elles sont appelées
//    faites en sorte qu'elles puissent être appelées sur un objet constant
// 3. faites la fonction qui permet d'afficher un objet de type IntStack directement avec <<<
//    std::cout << s1;
//    il faut redéfinir l'operator<< en appelant la méthode print

int main()
{
    IntStack s1;
    s1.print(); // affichera [[
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.print();                         // affichera [1 2 3 ]
    std::cout << s1.pop() << std::endl; // affichera 3
    s1.print();                         // affichera [1 2 ]
    return 0;
}
