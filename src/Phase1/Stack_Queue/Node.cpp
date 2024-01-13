#include <iostream>

#include "Node.h"

using namespace std;

Node::Node(int data)
{
  this->data = data;
  this->next = nullptr;
}

Node::Node(const Node &node)
{
  this->data = node.data;
  if (node.next) this->next = new Node(*node.next);
  else this->next = nullptr;
}

int Node::getData()
{
  return this->data;
}

void Node::setData(int data)
{
  this->data = data;
}

Node *Node::getNext()
{
  return this->next;
}

void Node::setNext(Node *next)
{
  this->next = next;
}