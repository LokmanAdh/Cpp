#include <iostream>
#include <math.h>
#include <time.h>

#include "Matrice.cpp"

using namespace std;

int main()
{
  /*cout << "Matrice 1:" << endl;
  Matrice matrice1(2, 2);
  matrice1.saisie();
  matrice1.print();
  
  cout << "Matrice 2:" << endl;
  Matrice matrice2(2, 2);
  matrice2.saisie();
  matrice2.print();

  cout << "Matrice 3 = Matrice 1 + Matrice 2:" << endl;
  Matrice matrice3 = matrice1 + matrice2;
  matrice3.print();

  cout << "Matrice 4 = Matrice 1 - Matrice 2:" << endl;
  Matrice matrice4 = matrice1 - matrice2;
  matrice4.print();

  cout << "Matrice 5 = Matrice 1 * Matrice 2:" << endl;
  Matrice matrice5 = matrice1 * matrice2;
  matrice5.print();

  cout << "Matrice 6 = Matrice 1 * 2:" << endl;
  Matrice matrice6 = matrice1 * 2;
  matrice6.print();

  cout << "Matrice 7 = Matrice 1:" << endl;
  Matrice matrice7 = matrice1;
  matrice7.print();

  cout << "Matrice 8 = Matrice 1 ^ 1:" << endl;
  Matrice matrice8 = matrice1 ^ 1;
  matrice8.print();*/

  clock_t startTime = clock();
  Matrice matrice1(1000, 1000);
  for(int i = 0;i<1000;i++){
    for(int j = 0;j<1000;j++){
      matrice1.set(i,j,rand()%10);
    }
  }
  Matrice matrice2 = matrice1 ^ 10;
  cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
  

  return 0;
}