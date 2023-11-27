#include <iostream>

#include "Stack.cpp"

using namespace std;

int main()
{
  Stack stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);

  cout << "Size: " << stack.size() << endl;
  stack.print();

  cout << stack.pop() << endl;
  cout << stack.pop() << endl;

  cout << "Size: " << stack.size() << endl;
  stack.print();
  Stack s(stack);
  s.print();
  Stack pile;
  pile = stack + s ;
  pile.print();

  return 0;
}