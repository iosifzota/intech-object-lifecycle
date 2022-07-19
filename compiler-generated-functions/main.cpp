#include <iostream>
#include <cstdlib>

class Duck;
Duck* createDuck();

/*
Rules:
 1) default constructor (if no constructor is defined by the user);
 2) copy constructor (if no move constructor is defined by the user);
 3) copy assignment (same as point 3);
 4) destructor.

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

int main()
{
    return 0;
}










// 
Duck* createDuck()
{
    return (Duck*)malloc(sizeof(*(createDuck())));
}