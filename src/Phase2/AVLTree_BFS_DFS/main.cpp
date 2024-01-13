#include<iostream> 
#include "AVLtree.cpp"
#include <chrono>


using namespace std;
using namespace chrono; 

int main() 
{ 
	AVLtree tree;
	// Insertion dans AVLTree (arbres binaires de recherche automatiquement équilibrés)
	for(int i = 1 ; i <= 100000 ; i++ ) tree.root = tree.insert(tree.root,i); 


	//print 2D
    //tree.print2D();

	high_resolution_clock::time_point start,stop;
	seconds duration;

	start = high_resolution_clock::now();
	tree.BFS();
	stop = high_resolution_clock::now();
    duration = duration_cast<seconds>(stop - start);
    cout << "\nTime taken by BFS "<<duration.count()<< " seconds "<<endl;

	start = high_resolution_clock::now();
	tree.DFS_infixe(tree.root);
	stop = high_resolution_clock::now();
    duration = duration_cast<seconds>(stop - start);
    cout << "\nTime taken by DFS_infixe "<<duration.count()<< " seconds "<<endl;
	
	return 0; 
} 