/*Од стандарден влез да се прочита квадратна матриција со број на редици и колони N. Прво се вчитува бројот N а потоа и N*N елементите на матрицата.
Да се промени знакот на елементите од главната дијагонала на матрицата (позитивните да станат негативни и обратно). */

#include <iostream>
using namespace std;

int main() {
    int n, matrix[100][100];;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        matrix[i][i] = -matrix[i][i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
