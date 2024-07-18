/*Write a program where a matrix A read from SI (maximum value of dimensions of the matrix is 100) is transformed to a new matrix B. Each element of 
the new matrix B is sum of positive neighbors of the corresponding element of the matrix A. Print the new matrix B on the standard output.
Input A:
1 2 3
4 -1 -2
-3 -4 10
1 2 10
Output B:
6 4 2 
1 6 13
5 12 10
2 11 12*/

#include <iostream>
using namespace std;
void calculatePositiveNeighbors(int A[100][100], int B[100][100], int n, int m) {

    int dirRow[] = {-1, 1, 0, 0};
    int dirCol[] = {0, 0, -1, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int k = 0; k < 4; k++) {
                int ni = i + dirRow[k];
                int nj = j + dirCol[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && A[ni][nj]>0) {
                    sum += A[ni][nj];
                }
            }
            B[i][j] = sum;
        }
    }
}

int main() {
    int n, m;
    int A[100][100];
    int B[100][100];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    calculatePositiveNeighbors(A, B, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << B[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}

