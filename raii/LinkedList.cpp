#include "UniquePtr.hpp"

struct Node
{
    int value;
    Node *next;
};

class LinkedList
{
    UniquePtr<Node> head;
    UniquePtr<Node> tail;

public:
    void add(int val)
    {
        Node n = { .value = val };
        
        UniquePtr<Node> nPtr{ new Node{n} };
    }
};