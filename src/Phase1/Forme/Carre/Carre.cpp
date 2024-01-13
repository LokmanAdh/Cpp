#include "Carre.h"

using namespace std;

Carre::Carre(float cote) : Forme2D(), cote(cote){};
Carre::Carre(float x, float y, float cote) : Forme2D(x, y), cote(cote){};

void Carre::afficher()
{
    cout << "le centre du carre est (" << this->x << "," << this->y << "),la longeur de son cote est :" << this->cote << endl;
}

double Carre::surface()
{
    return (this->cote * this->cote);
}