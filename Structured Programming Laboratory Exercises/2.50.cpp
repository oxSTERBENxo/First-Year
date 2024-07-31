/*Да се напише програма која чита две целобројни матрици со димензија m x n, а потоа печати колку колони од првата матрица се наоѓаат во втората матрица.*/

#include <iostream>
using namespace std;

bool colExistsInMat(int mat[100][100], int col[], int m, int n) {
    for (int j = 0; j < n; j++) {
        bool found = true;
        for (int i = 0; i < m; i++) {
            if (mat[i][j] != col[i]) {
                found = false;
                break;
            }
        }
        if (found) return true;
    }
    return false;
}
int main() {
    int m, n, mat1[100][100], mat2[100][100];
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat1[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat2[i][j];
        }
    }
    int count = 0;
    for (int col = 0; col < n; col++) {
        int column[100];
        for (int row = 0; row < m; row++) {
            column[row] = mat1[row][col];
        }
        if (colExistsInMat(mat2, column, m, n)) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
