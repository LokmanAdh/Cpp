#include "Individu.h"

Individu::Individu(string nom = " ", string prenom = " ", int age = 0)
{
    this->_nom = nom;
    this->_prenom = prenom;
    this->_age = age;
}

Individu::Individu(const Individu &I)
{
    this->_nom = I._nom;
    this->_prenom = I._prenom;
    this->_age = I._age;
}

string Individu::nom(void)
{
    return this->_nom;
}

string Individu::prenom(void)
{
    return this->_prenom;
}

int Individu::age(void)
{
    return this->_age;
}

void Individu::affiche(void)
{
    cout << "\nNom : " << this->_nom << " | Prenom : " << this->_prenom << " | Age : " << this->_age;
}