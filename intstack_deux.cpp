#include <iostream>
#include <stdexcept>
#include <cstdlib> //librairie C car commence par la lettre c : permet d'utilier exit et abort

// Version de IntStack avec des mémoires dynamiques

// on définit un type de donnée (une classe) pour gérer une pile d'entier de taille 12 (SIZE)
class IntStack
{
private:
    // vos attributs pour représenter la pile d'entier
    // dans cette version toutes les piles sont de taille SIZE
    // votre code ici
    int size;   // taille de la pile
    int length; // nombre d'éléments dans la pile
    int *pi;    // adresse du premier élément de notre pile

public:
    IntStack(int s) : length(0), size(s) // constructeur
    {
        if (s < 0)
        {
            exit(EXIT_FAILURE);
        };
        pi = new int[size]; // tableau de taille max size
    }
    ~IntStack() // destructeur : méthode appelée quand on sort du scope, supprime dans le heap automatiquement
    {
        delete[] pi;
    }
    IntStack(const IntStack &r) : length(r.length), size(r.size)    // copy constructor : par défaut, c++ peut "créer" un IntStack par copie, mais on le def nous même pour avec une nouvelle adresse mémoire
    {
        pi = new int[size];
    } 

    void push(int e)
    {
        // cette fonction ajoute l'entier e dans la pile
        // votre code ici
        if (is_full()) // revient à écrire (is_full()==1)
        {
            exit(EXIT_FAILURE);
        }
        *(pi + length) = e; // pi est l'adresse mémoire du premier élément du tableau, pi+length donne automatiquement l'adresse de l'élément d'indice length, on rajoute l'étoile pour accéder à cet élément
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
        return *(pi + (length - 1));
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
        return length == 0;
    }
    bool is_full() const
    {
        return length == size;
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
            std::cout << ' ' << *(pi + k) << ' ';
        }
        std::cout << '[' << std::endl; // vr: pas besoin l'utilisateur décidera si il veut aller à la ligne << std::endl;
    }
};

std::ostream &operator<<(std::ostream &os, const IntStack &pile)
{
    pile.print();
    return os;
}

// 1. réaliser le code pour faire fonctionner cette pile d'entier de taille fixée à la compilation
// 2. quelles sont les méthodes qui ne modifient pas l'objet sur lequel elles sont appelées
//    faites en sorte qu'elles puissent être appelées sur un objet constant
// 3. faites la fonction qui permet d'afficher un objet de type IntStack directement avec <<<
//    std::cout << s1;
//    il faut redéfinir l'operator<< en appelant la méthode print

int main()
{
    int size;
    std::cout << "Choisir la taille de la pile : ";
    std::cin >> size;
    IntStack s1(size);
    s1.print(); // affichera [[
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.print();                         // affichera [1 2 3 ]
    std::cout << s1.pop() << std::endl; // affichera 3
    s1.print();                         // affichera [1 2 ]
    return 0;
}