#ifndef FORME_H
#define FORME_H
#include <iostream>

class Forme
{
protected:
    // Cordonnées de centre de la forme
    float x;
    float y;

public:
    Forme(float x = 0, float y = 0);
    virtual void afficher() = 0;
    virtual double surface() = 0;
};
#endif