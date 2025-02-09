#pragma once

#include <iostream>
#include <vector>

class Shape
{
protected: // pour pouvoir accèder à x,y dans les méthodes des classes dérivées
    float x, y;
    int color;

public:
    Shape(float x, float y, int c) : x(x), y(y), color(c) {}
    void move(float newX, float newY)
    {
        x = newX;
        y = newY;
    }
    // virtual : if you want the compiler to call the function Square::area() (for instance)
    // when objects of type Square have been upcasted (perte d'information) in objects of type Shape*
    virtual bool is_at_position(float x1, float y1) const = 0;
    virtual float area() const = 0; // méthode abstraite ()=0) : on ne peut plus créer d'objet juste de type Shape. Pour s'assurer que personne ne crée d'objet de type juste Shape, on peut mettre le constructeur de shape en protected.
};

class Square : public Shape
{
private:
    float side;

public:
    Square(float x, float y, int c, float s) : Shape(x, y, c), side(s) {}
    float area() const // on peut remettre virtual ici (pas nécessaire). On peut aussi indiquer "override" pour dire qu'on redef une méthode héritée de shape.
    {
        return side * side;
    }
    bool is_at_position(float x1, float y1) const //(x,y) est le sommet en haut à gauche du carré
    {
        return (x1 >= x and x1 <= x + side) and (y1 <= y and y1 >= y - side);
    }
};

class Rectangle : public Shape
{
private:
    float height;
    float width;

public:
    Rectangle(float x, float y, int c, float h, float w) : Shape(x, y, c), height(h), width(w) {}
    float area() const
    {
        return height * width;
    }
    bool is_at_position(float x1, float y1) const //(x,y) est le sommet en haut à gauche du rectangle
    {
        return (x1 >= x and x1 <= x + width) and (y1 <= y and y1 >= y - height);
    }
};

class Circle : public Shape
{
private:
    float radius;

public:
    Circle(float x, float y, int c, float r) : Shape(x, y, c), radius(r) {}
    float area() const
    {
        return 3.141592 * radius * radius;
    }
    bool is_at_position(float x1, float y1) const //(x,y) est le centre du cercle
    {
        return (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) <= radius * radius;
    }
};

Shape *find_at_position(float x, float y, std::vector<Shape *> const &shapes)
{
    // prend en argument x, y et un vecteur de formes et retourne la première forme au point (x, y)
    for (Shape *e : shapes)
    {
        if ((*e).is_at_position(x, y))
        {
            return e;
        }
    }
    return nullptr; // pointeur nul vers un objet de type Shape*
}
