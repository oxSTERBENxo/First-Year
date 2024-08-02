/*На стандарден влез се внесува број N за димензии на матрица NxN, потоа се внесуваат елементите на матрицата. По внесување на матрицата се внесува и вредност за 
колоната и редицата Y. Да се направи трансформација на матрицата така што главната дијагонала се заменува со колоната Y, а колоната и редицата Y се заменуваат со
главната дијагонала.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
On standard input, a number N is entered for an NxN dimensional matrix, then the elements of the matrix are entered. After entering the matrix, a value for the Y 
column and Y row is also entered. Transform the matrix so that the main diagonal is replaced by the Y column, and the Y column and Y row are replaced by the main diagonal.*/

#include <iostream>
using namespace std;

int main() {
    int n, matrix[100][100], Y, diagonal[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    cin >> Y;
    for (int i = 0; i < n; i++) {
        diagonal[i] = matrix[i][i];
    }
    for (int i = 0; i < n; i++) {
        matrix[i][i] = matrix[i][Y];
    }
    for (int i = 0; i < n; i++) {
        matrix[i][Y] = diagonal[i];
    }
    for (int i = 0; i < n; i++) {
        matrix[Y][i] = diagonal[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
