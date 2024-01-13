#include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
//normalement mingw64 contient library "boost" mais si il ya une erreur installer boost d'apres msys : "pacman -S mingw-w64-x86_64-boost"
#include <chrono>



using namespace std;
using namespace chrono;

using namespace boost::multiprecision;



cpp_int fibonacciIterative (int n)
{
  if (n == 0)
    return 0;
  
  if (n == 1)
    return 1;

  cpp_int result = 0;
  cpp_int val1 = 0;
  cpp_int val2 = 1;

  for (int i = 2; i <= n; i++)
  {
    result = val1 + val2;
    val1 = val2;
    val2 = result;    
  }

  return result;
}



int main()
{
  int n;
  cout << "Entrer la valeur de n pour le nombre de fibonacci :";
  cin >> n;
  
  auto start = high_resolution_clock::now();

  cout << fibonacciIterative(n);

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<seconds>(stop - start);
  cout << "\nTime taken by function "<<duration.count()<< " seconds "<<endl;  
  

  return 0;
}
