#ifndef FORME3D_H
#define FORME3D_H

#include "../Forme/Forme.cpp"

class Forme3D : public Forme
{
protected:
    float z;
public:
    Forme3D(float = 0, float = 0, float = 0);
    virtual void afficher() = 0;
    virtual double surface() = 0;
};

#endif
