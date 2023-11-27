#include "Individu.cpp"

class Employe : public Individu
{
private:
    float salaire;

public:
    Employe(string, string, int, float);
    Employe(const Employe &);
    void affiche();
};

Employe::Employe(string nom = " ", string prenom = " ", int age = 0, float _salaire = 3000) : Individu(nom, prenom, age), salaire(_salaire)
{
}

Employe::Employe(const Employe &E) : Individu(E)
{
    this->salaire = E.salaire;
}

void Employe::affiche()
{
    Individu::affiche();
    cout << " | Salaire : " << this->salaire << "MAD";
}
