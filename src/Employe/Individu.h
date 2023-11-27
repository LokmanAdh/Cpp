#include <iostream>
#include <string>

using namespace std;

class Individu
{
protected:
    int _age;
    string _nom;
    string _prenom;

public:
    Individu(string nom, string, int);
    Individu(const Individu &); // constructeur de copie
    string nom(void);           // retourne le nom
    string prenom(void);        // retourne le prenom
    void affiche(void);         // affiche la totale
    int age(void);              // retourne l'age
};