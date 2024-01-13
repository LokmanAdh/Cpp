#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle(float lng, float lrg) : Forme2D(), longueur(lng), largeur(lrg){};
Rectangle::Rectangle(float x, float y, float lng, float lrg) : Form2D(x, y), longeur(lng), largeur(lrg){};
void Rectangle::afficher()
{
    cout << "le centre du Rectangle est (" << this->x << "," << this->y << "),Sa longeur est :" << this->longueur << ", Sa longeur est :" << this->largeur << endl;
}

double Rectangle::surface()
{
    return (this->largeur * this->longueur);
}