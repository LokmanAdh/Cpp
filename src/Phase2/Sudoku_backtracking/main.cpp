#include <iostream>
#include <chrono>


using namespace std;
using namespace chrono;


void AfficherMatrice(int Matrice[9][9]) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {

            cout << "------+-------+------" << endl;
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {

                cout << "| ";
            }
            cout << Matrice[i][j] << " ";
        }
        cout << endl;
    }
}

// Teste la possibilite de poser le num dans la cellule
bool isSafe(int Matrice[9][9], int row, int col, int num) {


    // test si num est introuvable dans collumn et row
    for (int x = 0; x < 9; x++) {
        if (Matrice[row][x] == num || Matrice[x][col] == num) {
            return false;
        }
    }

    // test si num est introuvable dans 3*3 subMatrice
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Matrice[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Resoudre Sudoku en utilisant backtracking
bool ResoudreSudoku(int Matrice[9][9]) {
    int row, col;

    // Trouver une cellule vide
    bool isEmpty = false;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (Matrice[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    // si tous les cellules sont pleine donc le sudoku est resolu
    if (!isEmpty) {
        return true;
    }

    // on test l'utilisation du nombre de 1 jusqu a 9 dans la cellule
    for (int num = 1; num <= 9; num++) {
        if (isSafe(Matrice, row, col, num)) {
            // si c'est safe on place le nombre dans la cellule
            Matrice[row][col] = num;

            // en utilisant la recursivite en resoudre le reste
            if (ResoudreSudoku(Matrice)) {
                return true;
            }

            // si le nombre ne revient aucune solution on utilise le backtracking et on passe a l'autre nombre
            Matrice[row][col] = 0;
        }
    }

    // aucun nombre ne doit etre placee dans la cellule courante
    return false;
}

int main() {

    int Matrice[9][9];

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            Matrice[i][j]=0;
        }
    }
    Matrice[0][1] = 4;Matrice[0][2] = 3;Matrice[0][3] = 7;Matrice[0][7] = 6;Matrice[0][8] = 5;
    Matrice[1][0] = 5;Matrice[1][6] = 2;
    Matrice[2][4] = 6;Matrice[2][6] = 1;
    Matrice[3][2] = 7;Matrice[3][5] = 9;
    Matrice[4][0] = 3;Matrice[4][4] = 2;Matrice[4][7] = 8;Matrice[4][8] = 4;
    Matrice[5][6] = 5;
    Matrice[6][7] = 1;
    Matrice[7][1] = 8;Matrice[7][3] = 2;
    Matrice[8][0] = 4;Matrice[8][4] = 8;Matrice[8][7] = 3;Matrice[8][8] = 6;

    cout << "Matrice Avant Solution:" << endl;
    AfficherMatrice(Matrice);

    auto start = high_resolution_clock::now();

    bool resolu = ResoudreSudoku(Matrice);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << "\nTime taken by function ResoudreSudoku is : "<<duration.count()<< " seconds "<<endl;

    if (resolu) {

        cout << "Solution:" << endl;
        AfficherMatrice(Matrice);

    } else cout << "Le sudoku n a aucune solution" << endl;

    return 0;
}
