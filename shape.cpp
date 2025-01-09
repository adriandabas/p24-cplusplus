// inclusion des bibliothèques standard ici
#include <iostream>
#include <vector>

// définition de vos classes ici
class Shape
{
private:
    int x, y;
    int color;

public:
    Shape(int x, int y, int c) : x(x), y(y), color(c) {}
    void move(int newX, int newY)
    {
        x = newX;
        y = newY;
    }
    bool is_at_position(int x1, int y1) const
    {
        return (x1 == x) and (y1 == y);
    }

    // virtual : if you want the compiler to call the function Square::area() (for instance)
    // when objects of type Square have been upcasted (perte d'information) in objects of type Shape*
    virtual float area() const { return 0; }
};

class Square : public Shape
{
private:
    float side;

public:
    Square(int x, int y, int c, float s) : Shape(x, y, c), side(s) {}
    float area() const
    {
        return side * side;
    }
};

class Rectangle : public Shape
{
private:
    float hight;
    float width;

public:
    Rectangle(int x, int y, int c, float h, float w) : Shape(x, y, c), hight(h), width(w) {}
    float area() const
    {
        return hight * width;
    }
};

class Circle : public Shape
{
private:
    float radius;

public:
    Circle(int x, int y, int c, float r) : Shape(x, y, c), radius(r) {}
    float area() const
    {
        return 3.141592 * radius * radius;
    }
};

// optionnel:
// faire une fonction prend en argument x, y et un vecteur de formes et retourne la forme au point (x, y)
Shape *find_at_position(int x, int y, std::vector<Shape *> const &shapes)
{
    // dans cette fonction vous avez besoin de tester si une forme est au point (x, y)
    // pour faire cela sans mettre cette fonction friend, ajouter en plus de move et area
    // une méthode bool is_at_position(int x, int y)
    for (Shape *e : shapes)
    {
        if ((*e).is_at_position(x, y))
        {
            return e;
        }
    }
    return nullptr;
}

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
    // pouvez vous appeler la méthode move et area sur shape2 ? l'exécution des deux lignes suivantes renvoie une erreur
    // shape2->move(2, 8);
    // std::cout << shape2->area() << std::endl;
    return 0;
}