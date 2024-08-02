/*Од стандарден влез да се прочита квадратна матрица со број на редици и колони N. Прво се вчитува бројот N а потоа и N*N елементите на матрицата.
Ваша задача е да ги пронајдете минималниот и максималниот број од секоја редица и соодветно да ги промените во 0 и 1 (min=0, max=1)
Доколку најмалиот или најголемиот број се повторуваат повеќе пати треба сите да се променат.
На крај испечатете ја трансформираната матрица.*/

#include <iostream>
using namespace std;

void transformMatrix(int matrix[][100], int n) {
    for (int i = 0; i < n; i++) {
        int min = matrix[i][0];
        int max = matrix[i][0];

        for (int j = 1; j < n; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }

        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == min) {
                matrix[i][j] = 0;
            }
            if (matrix[i][j] == max) {
                matrix[i][j] = 1;
            }
        }
    }
}


int main() {
    int n,mat[100][100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    transformMatrix(mat, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
