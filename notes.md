PDFs: https://euderz1cloud01.in-tech.global/index.php/f/20739232

== Constructors, Destructors ==
# Coding style
* m_member, camelCase, use only style for curly braces

# Key terms to use
* RAII.

# Examples
* RAII: scoped_lock example [NOT(instead unique pointer fulfils this topic)]
* Creating more than 1 object in expressions. [Drafted]

# Rules for compiler generated functions
1. default ctor (generated only if no ctor is declared by user)
2. copy ctor (generated only if no 3, 4, 5, 6 declared by user)
3. copy assignment operator (generated only if 2, 4, 5, 6 not declared by user)
4. dtor

C++ 11:
5. move ctor (generated only if 2, 3, 4, 6 not declared by user)
6. move assigment operator (generated only if 2, 3, 4, 5 not declared by user)


# Tricky corner cases
* Throwing exceptions from constructors. ~dog() { throw 20; } // If more than tow dogs are in a scope, there will be two or more exceptions active at the end of scope exit.
                       // This is because after throwing an exception c++ first unwindinds the stack and then passes the exception to the caught statement.
*  Using the delete keyword to prevent generation of a function by the compiler counts as user defined function: class Cow {      Cow& operator=(const Cow&) = delete; // This counts as if operator= was implemented by the user. => No move ctor or assigment. }

---
== Personal notes ==

---
== Copy, Move ==

# Key terms to use
* Shallow copy vs Deep copy. - Expensive vs Inexpensive
* The rule of 3: destructor + copy constructor + copy assignment operator (if any from the list is defined then probably all three should be defined)
* The rule of 5: rule of 3 + move constructor + move assignment (only if move is needed for the class) (unlike the rule of three failing to provide the move imples only a loss in performance)

# Tricky corner cases
* Copy semantics combined with move semantics for a function might be confusing: void foo(Vector v); // foo(a) <- copy ctor is called; foo(std::move(a)) <- move ctor is called.
* Destructors using rvalues (Why it is important to implement copy constructor/assignment)

# Examples
* Rule of three [Drafted]
* R.f.C.G.F (Rules for Compiler Generated Functions): std::swap in copy assignment. [TODO]
* Rule of five [Drafted]
* An exercise/presentation to demonstrate && & and copy semantics (using a function).
* foo(createVector()).

------------------------------------------------
------------------------------------------------

== Content ==
# Part 1
## Motivation for object lifecyle (Cosmin)
- Why do we need to manage an object's lifecycle, why and when do we need to copy, move, destruct
- Slide 3: not explaining why we are talking about an object's lifecycle (memory, in general)
- object vs class

## Overview of class with all possible type of ctors declared. For a taste of what's is going to be discussed. (Cosmin)
- Slide 5:

## Ctor/Dtor pair simple example (Cosmin)
- Slide 8: looks ok, constructor/destructor pair, add simple example
- Iosif: code example (it's simple but it's a more elaboarate example to show how useful a destructor can be:  however the part for the interns to implement is very small)

## Scope (Cosmin)
- Slide 8.

## RAII (Iosif)
- Slide 14
- Iosif: code example (Unique ptr: without move semantics!!)

## Default ctor (Cosmin)
- Slide 18-20
- Slide 20: compare initialization of basic variables with object variables initialization (objects will implicitily initialize -ctor will be called-, while for basic types no initialization (exception if they are global variables))

## References and other members that require initialization (Iosif)
- Slide 21: move to code along

## Static member initialization (Iosif)
- Slide 22: constexpr it's a bit complicated

## When are ctrs and assigments called? (Iosif)
- Slide 6.

## Move vs Copy: use case overview (Cosmin)
- Slide 3:

## Copy ctor and assignment presentation
### Shallow vs Deep copy (Cosmin)
- Slide 15: also add example of shallow copy vs deep copy
### Copy ctor signature (Cosmin)
- Slide 6: don't really understand the point with const return type, why?
- Slide 7: remove template, explain that before destructor delete[] we should check for nullptr, as a minimum -> proper fix is on next slide
- Slide 8: (motivation for custom copy ctor)
    go manually through this example, instantiate 2 objects and go through their lifecycles -> what happens when the second object gets deleted??
    Matrix(int d1, int d2) :dim{d1,d2}, elem{new T[d1∗d2]} {} // simplified (no error handling)
    what would happen here if the class members were defined the other way around?? (first one elem and then dim), without using the parameters
    even though dim is first in the initializer list, members are initialized in the order they are declared
    also, to respect RAII, it would be really advised to never expose the raw pointer inside the class
    if someone is able to get that pointer, they will be able to also delete its allocated space and the destructor will have a really bad time
    same with the copy constructor, the new object's destructor will try to free the (maybe) already freed space
- Slide 9: remove template, Why use initialization list vs initialization in block of code (double initialization if the init list is not used)?
- Slide 10: good point, be more explicit (we have to get rid of the old content when doing assignment, simple example with pointer)
- Iosif: example "rule of three"
### Idiom of writing the copy assignment (Cosmin)
- Slide 11: careful! you need move fcts for std::swap [TODO] Test if the code works
- What if we try to swap objects of a type that does not have a move constructor? We copy and pay the price.
#### Exceptions: throwing (Cosmin)
- Slide 11: good point, explain what throwing is (simple example out of bounds or nullptr dereferencing), also careful
### Default and compiler generated functions (Iosif)
- Show the list of rules for compiler generated functions
- Slide 13: ok, but when do you use the default copy operators? if you don't have pointers in your class, then ALWAYS
### What happens when it is used with inheritence? (Iosif)
- Slide 14: here we could explain in detail what is happening (a deep copy of each base is created)
- Breif explanation of inheritence.
### Common sense rules for copy ctor and assignment: (Iosif)
- Slide 15: nice, but too complicated, it can be simplified

# Part 2

## Motivation for move semantics (Cosmin)
- Slide 18: remove template
- Slide 19-21

## Simple example of move semantics (the case of Matrix class): ctor (Cosmin)
 - Slide 22
 - Iosif: example "rule of five"
 
## Move vs Copy: side effects (NOT throwing, valid moved-from state) (Cosmin)
- Slide 4: too complex for begginners, rewrite - unspecified => recognizable deteted state (e.g value of 0 for ints and nullptr for pointers). From the CppTalk the valid, recognizable state is the default state of that object 99% of the time. Unspecified means one cannot say what is containted in the class: e.g. instead of reseting an int member the move ctor did not touch that member; that in member is in an valid but unspecified state.
### Rvalues and lvalues (Iosif)
- Slide 23: explain why, Iosif write example
### Rvalues, lvalules and move, copy semantics interactions (Iosif)
- Slide 24
### Tricky point (Cosmin)
- Slide 24: maybe move the initializer list in the declaration (it's not a good idea to combine initializer lists with a function body), there is a case where you cannot do anything: when you have references in class; if you do not give any initializer list, you will first initialize dim and elem with default values and then reassign them

## Simple example of move semantics continued: asignment (Iosif)
- Slide 25: initialization vs assignment: explain when the move constructor is called and when the move assignment is called (do this for copy and move, it's the same)

## How does the compiler know when to call move or copy ctors or assigments (Iosif)
- Slide 26: good point, lvalue and rvalue are EXPRESSION relevant, they do not exist in general; in theory lvalue and rvalue are possible value categories of an experssion; use example from https://www.youtube.com/watch?v=St0MNEU5b0o -> just tell the compiler which function to call for this operation -> it's up to you how you implement each, you could do copy in move ctr if you so wish

## Returning large objects (Cosmin)
- Slide 27: good point, maybe rephrase
- Emphasize that the compiler calls the move ctor on return

### Alternatives to implement moving object without move semantics (Iosif)
- Slide 28: give answers to the questions if we choose to keep them