#ifndef CARRE_H
#define CARRE_H

#include "../Form2D/Forme2D.cpp"

class Carre : public Forme2D
{
protected:
    float cote;

public:
    Carre(float);
    Carre(float, float, float);
    void afficher();
    double surface();
};
#endif