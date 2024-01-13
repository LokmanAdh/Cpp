#ifndef STACK_H
#define STACK_H

#include "Node.cpp"
class Stack
{
  private:
    Node *top;
  public:
    Stack();
    Stack(const Stack &);
    ~Stack();
    int peek();
    void push(int);
    int pop();
    void print();
    int size();
    void clear();
    void operator=(const Stack&);
    Stack operator+(const Stack&);
};

#endif