#include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
//normalement mingw64 contient library "boost" mais si il ya une erreur installer boost d'apres msys : "pacman -S mingw-w64-x86_64-boost"
#include <chrono>



using namespace std;
using namespace chrono;

using namespace boost::multiprecision;


cpp_int fibonacciRecursive(int n)
{
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}



int main()
{
  int n;
  cout << "Entrer la valeur de n pour le nombre de fibonacci :";
  cin >> n;

  auto start = high_resolution_clock::now();

  cout << fibonacciRecursive(n);

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<seconds>(stop - start);
  cout << "\nTime taken by function "<<duration.count()<< " seconds "<<endl;  
  

  return 0;
}