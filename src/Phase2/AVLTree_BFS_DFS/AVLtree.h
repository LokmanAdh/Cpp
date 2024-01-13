#ifndef AVLTREE_H
#define AVLTREE_H

#include "Noeud.cpp"


class AVLtree 
{ 
	public: 
	Noeud *root; 

    AVLtree();
    ~AVLtree();
    Noeud* clear(Noeud*);
    int height(Noeud*);
    int max(int , int);
    Noeud *rightRotate(Noeud*);
    Noeud *leftRotate(Noeud*);
    int getBalance(Noeud*);
    Noeud* insert(Noeud*, int);
    void print2D();
    void print2DUtil(Noeud*,int);
    void BFS();
    void DFS_prefixe(Noeud*);
    void DFS_infixe(Noeud*);
    void DFS_postfixe(Noeud*);
}; 

#endif