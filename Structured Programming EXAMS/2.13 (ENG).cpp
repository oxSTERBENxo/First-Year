/*Read a square matrix of integers from standard input. First the dimension N is entered (2 < N <= 100) and then the elements of the matrix by rows.
Transform the matrix in a way that all the elements ABOVE the main diagonal will be set to the value of the maximal element found above the main diagonal, 
while all the elements BELOW the main diagonal will be set to the value of the minimal element found below the main diagonal. Print out the transformed matrix.*/

#include <iostream>
using namespace std;

void transformMatrix(int matrix[100][100], int n) {
    int maxAboveDiagonal = matrix[0][1];
    int minBelowDiagonal = matrix[1][0];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] > maxAboveDiagonal) {
                maxAboveDiagonal = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] < minBelowDiagonal) {
                minBelowDiagonal = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {
                matrix[i][j] = maxAboveDiagonal;
            } else if (i > j) {
                matrix[i][j] = minBelowDiagonal;
            }
        }
    }
}
int main() {
    int n, matrix[100][100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    transformMatrix(matrix, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
