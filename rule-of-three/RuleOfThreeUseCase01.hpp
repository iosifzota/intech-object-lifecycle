#ifndef __RULEOFTHREEUSECASE01_H__
#define __RULEOFTHREEUSECASE01_H__

#include <iostream>
#include <vector>

class Person
{
    int *pInt;

public:

    Person(int x) : pInt(new int(x))
    {
        // empty
    }
    ~Person()
    {
        delete pInt;
    }

    void printVal()
    {
        std::cout << *pInt << std::endl;
    }
};

void testRuleOfThreeUseCase01()
{
    std::vector<Person> vec;

    vec.push_back(Person(3));

    Person tmp = vec[0];
    tmp.printVal(); // What is displayed on the screen? 
}

#endif // __RULEOFTHREEUSECASE01_H__