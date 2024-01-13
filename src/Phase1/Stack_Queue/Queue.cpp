#include <iostream>

#include "Queue.h"

using namespace std;

Queue::Queue()
{
  this->first = nullptr;
  this->last = nullptr;
}


Queue::~Queue()
{
  while (this->first)
    this->defiler();
}


void Queue::enfiler(int data)
{
  Node *node = new Node(data);
  node->setNext(NULL);
  if(!this->last){
    this->first = this->last = node ;
    return;
  }
  this->last->setNext(node);
  this->last = node;
}

int Queue::defiler()
{
  if(!this->first)return-1;
  Node *node = this->first;
  this->first = this->first->getNext();
  if(!this->first)this->last = NULL;
  int data = node->getData();
  delete node;
  return data;
}

void Queue::print()
{
    Node *cp = this->first;
  while(cp){
    cout<<cp->getData()<<"  ";
    cp = cp->getNext();
  }
}

