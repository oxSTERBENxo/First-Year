/*Од стандарден влез се вчитуваат 2 броја M и N, кои ја означуваат димензијата на матрицата, MxN и потоа се внесуваат елементите во матрицата. 
Вашате задача е последниот елемент во секој од редовите на матрицата, да го замените со максималниот елемент од таа редица. На крај испечатете ја
изменетата матрица и во нов ред среданта свредност на изменетата матицата.*/

#include <iostream>
using namespace std;

int main() {
    int m,n;
    cin >> m >> n;
    int mat[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        int max = mat[i][0];
        for (int j = 1; j < n; j++) {
            if (mat[i][j] > max) {
                max = mat[i][j];
            }
        }
        mat[i][n - 1] = max;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum += mat[i][j];
        }
    }
    double average = (double)sum / (m * n);
    cout << average << endl;
    return 0;
}
