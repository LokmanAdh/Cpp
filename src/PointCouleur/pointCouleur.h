#include <iostream>

using namespace std;

class PointCouleur
{
protected:
    int x;
    int y;
    string couleur;

public:
    PointCouleur(int, int, string);
    void afficher();
    void setX(int);
    void setY(int);
};