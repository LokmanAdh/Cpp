
#include<iostream> 
#include <queue>
#include "AVLtree.h"

using namespace std; 


AVLtree::AVLtree()
{
	this->root = NULL;
}

AVLtree::~AVLtree()
{
	this->root = clear(this->root);
}

Noeud* AVLtree::clear(Noeud *N)
{
	if(!N) return NULL;
	if(N->left)N->left = clear(N->left);
	if(N->right)N->right = clear(N->right);

	delete N;
	return NULL;
}

int AVLtree::height(Noeud *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 

int AVLtree::max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 


Noeud* AVLtree::rightRotate(Noeud *y) 
{ 
	Noeud *x = y->left; 
	Noeud *T2 = x->right; 

	x->right = y; 
	y->left = T2; 

	y->height = max(height(y->left), height(y->right)) + 1; 
	x->height = max(height(x->left), height(x->right)) + 1; 

	return x; 
} 

Noeud* AVLtree::leftRotate(Noeud *x) 
{ 
	Noeud *y = x->right; 
	Noeud *T2 = y->left; 

	y->left = x; 
	x->right = T2; 

	x->height = max(height(x->left),height(x->right)) + 1; 
	y->height = max(height(y->left),height(y->right)) + 1; 

	return y; 
} 

int AVLtree::getBalance(Noeud *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 

Noeud* AVLtree::insert(Noeud* noeud, int val) 
{ 

	if (noeud == NULL)return (new Noeud(val)); 
		

	if (val < noeud->val) 
		noeud->left = insert(noeud->left, val); 
	else if (val > noeud->val) 
		noeud->right = insert(noeud->right, val); 
	else
		return noeud; 

	noeud->height = 1 + max(height(noeud->left),height(noeud->right)); 

	int balance = getBalance(noeud); 

	// Left Left Case 
	if (balance > 1 && val < noeud->left->val) 
		return rightRotate(noeud); 

	// Right Right Case 
	if (balance < -1 && val > noeud->right->val) 
		return leftRotate(noeud); 

	// Left Right Case 
	if (balance > 1 && val > noeud->left->val) 
	{ 
		noeud->left = leftRotate(noeud->left); 
		return rightRotate(noeud); 
	} 

	// Right Left Case 
	if (balance < -1 && val < noeud->right->val) 
	{ 
		noeud->right = rightRotate(noeud->right); 
		return leftRotate(noeud); 
	} 

	return noeud; 
} 

void AVLtree::print2DUtil(Noeud* root, int space)
{

    if (root == NULL)
        return;
 
    space += 10;
 
    print2DUtil(root->right, space);
 

    cout << endl;
    for (int i = 10; i < space; i++)
        cout << " ";
    cout << root->val << "\n";
 
    print2DUtil(root->left, space);
}
 
void AVLtree::print2D()
{
    print2DUtil(this->root, 0);
}

void AVLtree::BFS()
{
    
    if (!root) return;
 
    queue<Noeud*> q;
    q.push(root);
 
    while (q.empty() == false) {
         
        Noeud* n = q.front();
        cout << n->val << " ";
        q.pop();
        
        if (n->left!= NULL)
            q.push(n->left);
        
        if (n->right != NULL)
            q.push(n->right);
    }

}

void AVLtree::DFS_prefixe(Noeud* root)
{
    
    if(root){
		cout<<root->val<<" ";
        DFS_prefixe(root->left);
        DFS_prefixe(root->right);
	}

}

void AVLtree::DFS_infixe(Noeud* root)
{
    
    if(root){
		
        DFS_infixe(root->left);
		cout<<root->val<<" ";
        DFS_infixe(root->right);
	}

}


void AVLtree::DFS_postfixe(Noeud* root)
{
    
    if(root){
		
        DFS_postfixe(root->left);
        DFS_postfixe(root->right);
		cout<<root->val<<" ";
	}

}


 
