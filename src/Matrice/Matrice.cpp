#include <iostream>

#include "Matrice.h"

using namespace std;

Matrice::Matrice(int n, int m)
{
  this->n = n;
  this->m = m;
  this->matrice = new int *[n];
  for (int i = 0; i < n; i++)
  {  
    this->matrice[i] = new int[m];
    for (int j = 0; j < m; j++)
      this->matrice[i][j] = 0;
  }
}

Matrice::Matrice(int n)
{
  this->n = n;
  this->m = n;
  this->matrice = new int *[n];
  for (int i = 0; i < n; i++)
  {  
    this->matrice[i] = new int[n];
    for (int j = 0; j < m; j++){
      if(i == j) this->matrice[i][j] = 1;
      else this->matrice[i][j] = 0;
    }
  }
}

Matrice::Matrice(const Matrice &M)
{
  this->n = M.n;
  this->m = M.m;
  this->matrice = new int *[this->n];
  for (int i = 0; i < this->n; i++)
  {
    this->matrice[i] = new int[this->m];
    for (int j = 0; j < this->m; j++)
      this->matrice[i][j] = M.matrice[i][j];
  }
}

Matrice::~Matrice()
{
  for (int i = 0; i < this->n; i++)
    delete[] this->matrice[i];
  delete[] this->matrice;
}

void Matrice::saisie()
{
  for (int i = 0; i < this->n; i++)
    for (int j = 0; j < this->m; j++)
    {
      cout << "matrice[" << i << "][" << j << "] = ";
      cin >> this->matrice[i][j];
    }
}

void Matrice::set(int i, int j, int value)
{
  if ((0 <= i ) && (i < this->n) && (0 <= j) && (j < this->m))
    this->matrice[i][j] = value;
}

int Matrice::get(int i, int j)
{
  if ((0 <= i) && (i < this->n) && (0 <= j) && (j < this->m))
    return this->matrice[i][j];
  cout << "Invalid index" << endl;
  return -1;
}

int Matrice::getN()
{
  return this->n;
}

int Matrice::getM()
{
  return this->m;
}

void Matrice::print()
{
  for (int i = 0; i < this->n; i++)
  {
    for (int j = 0; j < this->m; j++)
      cout << this->matrice[i][j] << "\t";
    cout << endl;
  }
}

Matrice Matrice::operator+(const Matrice &M)
{
  if ((this->n != M.n) || (this->m != M.m))
  {
    cout << "Invalid operation" << endl;
    return *this;
  }
  Matrice result(this->n, this->m);
  for (int i = 0; i < this->n; i++)
    for (int j = 0; j < this->m; j++)
      result.matrice[i][j] = this->matrice[i][j] + M.matrice[i][j];
  return result;
}

Matrice Matrice::operator-(const Matrice &M)
{
  if ((this->n != M.n) || (this->m != M.m))
  {
    cout << "Invalid operation" << endl;
    return *this;
  }
  Matrice result(this->n, this->m);
  for (int i = 0; i < this->n; i++)
    for (int j = 0; j < this->m; j++)
      result.matrice[i][j] = this->matrice[i][j] - M.matrice[i][j];
  return result;
}

Matrice Matrice::operator*(const Matrice &M)
{
  if (this->m != M.n)
  {
    cout << "Invalid operation" << endl;
    return *this;
  }
  Matrice result(this->n, M.m);
  for (int i = 0; i < this->n; i++)
    for (int j = 0; j < M.m; j++)
      for (int k = 0; k < this->m; k++)
        result.matrice[i][j] += this->matrice[i][k] * M.matrice[k][j];
  return result;
}

Matrice Matrice::operator*(const int &value)
{
  Matrice result(this->n, this->m);
  for (int i = 0; i < this->n; i++)
    for (int j = 0; j < this->m; j++)
      result.matrice[i][j] = this->matrice[i][j] * value;
  return result;
}


void Matrice::operator=(const Matrice &M)
{
  this->n = M.n;
  this->m = M.m;
  this->matrice = new int *[this->n];
  for (int i = 0; i < this->n; i++)
  {
    this->matrice[i] = new int[this->m];
    for (int j = 0; j < this->m; j++)
      this->matrice[i][j] = M.matrice[i][j];
  }
}

Matrice Matrice::operator^(const int &value)
{
  if(this->m != this->n)
  {
    cout<< "C 'est pas une matrice carre"<<endl;
    return Matrice(this->n,this->m);
  }else{
    if(value == 0) return Matrice(this->n);
    Matrice result(*this);
    for(int i = 1; i<value;i++) result = result * (*this);
    return result;
  }
}
