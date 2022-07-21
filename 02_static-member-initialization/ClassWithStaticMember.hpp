#ifndef __CLASSWITHSTATICMEMBER_H__
#define __CLASSWITHSTATICMEMBER_H__

// Did I make a mistake with the naming: Class? Is this a class?
struct ClassWithStaticMember
{
    static int a;
    // static int a = 3; // error : not const


    static const int b = 7; // OK
    // static const int c4 = sqrt(9); // error : in-class initializer not constant
    // static const float c5 = 7.0; // error : in-class not integral (use constexpr rather than const)

};

#endif // __CLASSWITHSTATICMEMBER_H__