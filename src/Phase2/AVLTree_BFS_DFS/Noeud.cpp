#include <iostream>

#include "Noeud.h"

using namespace std;

Noeud::Noeud(int v)
{
    this->val = v;
    this->left = NULL;
    this->right = NULL;
    this->height = 1;
}