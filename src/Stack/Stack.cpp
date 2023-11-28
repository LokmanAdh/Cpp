#include <iostream>

#include "Stack.h"

using namespace std;

Stack::Stack()
{
  this->top = nullptr;
}

Stack::Stack(const Stack &pile)
{
  this->top = nullptr;
  if(pile.top){

    Stack *t = new Stack();
    Node *cp = pile.top;
    while(cp){
      t->push(cp->getData());
      cp = cp->getNext();
    }
    while(t->top){
      this->push(t->pop());
    }
  }
}

Stack::~Stack()
{
  while (this->top)
    this->pop();
}

int Stack::peek()
{
  return this->top->getData();
}

void Stack::push(int data)
{
  Node *node = new Node(data);
  node->setNext(this->top);
  this->top = node;
}

int Stack::pop()
{
  if (!this->top)
  {
    cout << "Stack is empty" << endl;
    return -1;
  }
  Node *node = this->top;
  int data = node->getData();
  this->top = this->top->getNext();
  delete node;
  return data;
}

void Stack::print()
{
  if (!this->top)
    cout << "Stack is empty" << endl;
  else
  {
    Stack *tmp = new Stack();
    while (this->top)
    {
      cout << this->peek() << " ";
      tmp->push(this->pop());
    }
    cout << endl;
    while (tmp->top)
      this->push(tmp->pop());
    delete tmp;
  }
}

int Stack::size()
{
  int size = 0;
  Stack *tmp = new Stack();
  while (this->top)
  {
    size++;
    tmp->push(this->pop());
  }
  while (tmp->top)
    this->push(tmp->pop());
  delete tmp;
  return size;
}

void Stack::clear()
{
  while(this->top){
    this->pop();
  }
}

void Stack::operator=(const Stack &pile)
{
  this->clear();
  if(pile.top){

    Stack *t = new Stack();
    Node *tmp = pile.top;
    while(tmp){
      t->push(tmp->getData());
      tmp = tmp->getNext();
    }
    while(t->top){
      this->push(t->pop());
    }

  }else{
    this->top = nullptr;
  }
}

Stack Stack::operator+(const Stack &pile)
{
  Stack resultat(*this);
  if(pile.top){

    Stack *t = new Stack();
    Node *tmp = pile.top;
    while(tmp){
      t->push(tmp->getData());
      tmp = tmp->getNext();
    }
    while(t->top){
      resultat.push(t->pop());
    }

  }
  return resultat;
}
