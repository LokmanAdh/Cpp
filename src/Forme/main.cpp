#include "Carre/Carre.cpp"
#include "Rectangle/Rectangle.cpp"
#include "Cercle/Cercle.cpp"
#include "Cube/Cube.cpp"

int main()
{
    Forme *list[6];

    list[0] = new Rectangle(5, 8);
    list[1] = new Cercle(5);
    list[2] = new Carre(6);
    list[3] = new Cube(6);

    for (int i = 0; i < 4; i++)
    {
        list[i]->afficher();
        cout << "Surface :" << list[i]->surface() << endl;
    }

    return 0;
}