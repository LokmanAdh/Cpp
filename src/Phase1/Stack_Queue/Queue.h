#ifndef QUEUE_H
#define QUEUE_H

#include "Node.cpp"
class Queue
{
  public:
    Node *first;
    Node *last;
  public:
    Queue();
    ~Queue();
    void enfiler(int);
    int defiler();
    void print();

};

#endif