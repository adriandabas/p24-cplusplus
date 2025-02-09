#include <iostream>
#include "shape.h"

int main()
{
    Circle c{10, 20, 0, 4.5};       // x, y, color, radius
    Rectangle r{20, 30, 0, 30, 60}; // x, y, color, width, height
    std::vector<Shape *> shapes;
    shapes.push_back(&c);
    shapes.push_back(&r);

    /*
    // première version (sans find_at_position et is_at_position)
    shapes[0]->move(4, 6); // équivalent à (*shapes[0]).move(4,6)
    shapes[1]->move(2, 8);
    std::cout << shapes[0]->area() << std::endl; // affiche dans les 63.6173
    std::cout << shapes[1]->area() << std::endl; // 1800
    */

    // deuxième version (avec find_at_position et is_at_position)
    Shape *shape1 = find_at_position(10, 20, shapes);
    // appeler la méthode move et area sur shape1
    shape1->move(4, 6);
    std::cout << shape1->area() << std::endl;
    Shape *shape2 = find_at_position(100, 200, shapes);
    // sur shape2
    if (shape2 != nullptr) // si on n'a pas trouvé d'objet à cette position, l'appel d'une méthode sur nullptr renvoie une erreur
    {
        shape2->move(2, 8);
        std::cout << shape2->area() << std::endl;
    }
    return 0;
}