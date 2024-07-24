/*Напишете програма за читање елементи во матрица и проверете дали дадената матрица е симетрична матрица или не. Од стандаред влез се внесуваат димензиите на матрицата
M и N соодветно и потоа се внесуваат елементите на матрицата. Ваша задача е доколку матрицата е симетрична да испечатете на екран 1, доколку не е симетрична да испечатете -1,
потоа се печати самата матрица на екран.*/

#include <iostream>
using namespace std;

int main() {
    int m, n, matrix[100][100];
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    bool symm = true;
    if (m != n) {
        symm = false; 
    } else {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != matrix[j][i]) {
                    symm = false;
                    break;
                }
            }
            if (!symm) {
                break;
            }
        }
    }
    if (symm) {
        cout << 1 << endl;
    } else {
        cout << -1 << endl;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
