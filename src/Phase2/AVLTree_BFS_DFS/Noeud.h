#ifndef NOEUD_H
#define NOEUD_H

class Noeud 
{ 
	public: 
		int val; 
		Noeud *left; 
		Noeud *right;
		int height;
	public:
		Noeud(int); 
}; 

#endif