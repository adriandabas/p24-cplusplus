#pragma once

#include <iostream>

class Integer
{
private:
    int value;

public:
    Integer(int v = {}) : value{v} {}
    void incr() { value = value + 1; }
    void decr() { value = value - 1; }
    void print() { std::cout << value << std::endl; }
};

/*
//Deuxième façon de définir la classe Integer, avec les fonctions membre en dehors de la classe (revient exactement au même)
class Integer
{
private:
    int value;

public:
    Integer(int v = {});
    void incr();
    void decr();
    void print();
};

inline Integer::Integer(int v) : value(v) {}    //il ne faut pas remettre 'v = {}' ici (sinon ça ne marche pas...)
inline void Integer::incr() { value = value + 1; }
inline void Integer::decr() { value = value - 1; }
inline void Integer::print() { std::cout << value << std::endl; }
 */