#include "PointCouleur.cpp"

class PointVert : public PointCouleur
{
public:
    PointVert(int x, int y) : PointCouleur(x, y, "vert")
    {
    }
};
