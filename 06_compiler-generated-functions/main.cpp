#include <iostream>
#include <cstdlib>

class Duck;
Duck* createDuck();

/*
Rules:
 1) default constructor (if no constructor is defined by the user)
 2) copy constructor (if 5, 6 are not defined by the user)
 3) copy assignment (if 5, 6 are not defined by the user)
 4) destructor.
 
 5) move constructor (if 2, 3, 4, 6 are not defined by the user)
 6) move assignment  (if 2, 3, 4, 5 are not defined by the user)
*/

struct Dog // compiler generated functions:
{
};

struct Duck // compiler generated functions:
{
    Duck(const Duck&other)
    {
        // empty
    }
};

struct Cat // compiler generated functions:
{
    Cat& operator=(const Cat& other)
    {
        // empty
        return *this;
    }
};

struct Camel // compiler generated functions:
{
    Camel(const Camel& other) = default;
};

struct Goat // compiler generated functions:
{
    Goat(Goat&& other)
    {
        // empty
    }
};

struct Lamb
{
    Lamb& operator=(Lamb&& other)
    {
        // empty
        return *this;
    }
};

int main()
{
    return 0;
}










// 
Duck* createDuck()
{
    return (Duck*)malloc(sizeof(*(createDuck())));
}