/*Од стандарден влез да се прочита квадратна матриција со број на редици и колони N. Прво се вчитува бројот N а потоа и N*N елементите на матрицата.
Вашате задача е треба да ги замените сите парни елементи во матрицата со збирот на нивните индекси на редови и колони. На крај испечатете ја изменетата матрица.
-------------------------------------------------------------------------------------------------------
Read a square matrix with number of rows and columns N from standard input . First the number N is loaded and then the N*N elements of the matrix.
Your task is to replace all even elements in the matrix with the sum of their row and column indices. Finally, print the modified matrix.*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int mat[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] % 2 == 0) {
                mat[i][j] = i + j; 
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
