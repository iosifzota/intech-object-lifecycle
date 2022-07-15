PDFs: https://euderz1cloud01.in-tech.global/index.php/f/20739232

== Constructors, Destructors ==
# Coding style
* m_member, camelCase, use only style for curly braces

# Key terms to use
* RAII.

# Examples
* RAII: scoped_lock example [TODO]
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

---
== Personal notes ==

---