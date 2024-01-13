#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
//normalement mingw64 contient library "boost" mais si il ya une erreur installer boost d'apres msys : "pacman -S mingw-w64-x86_64-boost"
#include <chrono>


using namespace std;
using namespace chrono;

using namespace boost::multiprecision;


vector<vector<cpp_int>> multiplyMatrix(const vector<vector<cpp_int>>& matrix1, const vector<vector<cpp_int>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int cols2 = matrix2[0].size();

    vector<vector<cpp_int>> result(rows1, vector<cpp_int>(cols2, 0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}


vector<vector<cpp_int>> powerMatrix(const vector<vector<cpp_int>>& matrix, int n) {
    int size = matrix.size();


    if (n == 1) {
        return matrix;
    }


    if (n % 2 == 0) {
        vector<vector<cpp_int>> halfPower = powerMatrix(matrix, n / 2);
        return multiplyMatrix(halfPower, halfPower);
    } else {
        vector<vector<cpp_int>> halfPower = powerMatrix(matrix, (n - 1) / 2);
        return multiplyMatrix(multiplyMatrix(halfPower, halfPower), matrix);
    }
}


cpp_int fibonacci(int n) {

    if (n == 0) return 0;
    if (n == 1) return 1;


    vector<vector<cpp_int>> fibMatrix = {{1, 1}, {1, 0}};


    vector<vector<cpp_int>> resultMatrix = powerMatrix(fibMatrix, n - 1);


    return resultMatrix[0][0];
}

int main() {
    int n;
    cout << "Entrer la valeur de n pour le nombre de fibonacci :";
    cin >> n;

    auto start = high_resolution_clock::now();

    cout << fibonacci(n);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << "\nTime taken by function "<<duration.count()<< " seconds "<<endl;

    return 0;
}
