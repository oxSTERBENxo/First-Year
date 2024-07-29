/*Од стандарден влез да се прочита квадратна матрица со број на редици и колони N. Прво се вчитува бројот N а потоа и N*N елементите на матрицата.
Ваша задача е да ја пронајдете колоната со максимална сума на елементите и таа сума да ја додадете на секој елемент на таа колона.
На крај испечатете ја трансформираната матрица.
*Доколку има 2 колони со иста максимална сума, да се чува таа што е прва најдена*/

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
    int maxSum = -1, idx = 0;
    for (int j = 0; j < n; j++) {
        int columnSum = 0;
        for (int i = 0; i < n; i++) {
            columnSum += mat[i][j];
        }
        if (columnSum > maxSum) {
            maxSum = columnSum;
            idx = j;
        }
    }
    for (int i = 0; i < n; i++) {
        mat[i][idx] += maxSum;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
