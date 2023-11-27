#include "pointCouleur.h"

PointCouleur::PointCouleur(int x, int y, string couleur)
{
    this->x = x;
    this->y = y;
    this->couleur = couleur;
}

void PointCouleur::afficher()
{
    cout << "point (" << this->x << "," << this->y << "," << this->couleur << ")";
}
