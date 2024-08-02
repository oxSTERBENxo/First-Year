/*Од стандарден влез да се прочита квадратна матриција со број на редици и колони N. Прво се вчитува бројот N а потоа и N*N елементите на матрицата.
Ваша задача е да го пронајдете минималниот елемент во секој непарен ред и да ја додадете оваа минимална вредност на секој елемент во следниот (парен) ред.
-------------------------------------------------------------------------------------------------------
Read a square matrix with number of rows and columns N from standard input. First the number N is loaded and then the N*N elements of the matrix. 
Your task is to find the minimum element in each odd-numbered row and add this minimum value to every element in the subsequent (even-numbered) row.*/

#include <iostream>
using namespace std;

int main() {
    int n, mat[100][100];;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < n; i += 2) { 
        int min = mat[i][0];
        for (int j = 1; j < n; j++) {
            if (mat[i][j] < min) {
                min = mat[i][j];
            }
        }
        if (i + 1 < n) { 
            for (int j = 0; j < n; j++) {
                mat[i + 1][j] += min;
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
