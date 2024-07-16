/*Read from standard input the dimensions of a matrix (m < 100 and n < 100) which contains only zeros and ones. Then read the elements of the matrix.
Read the coordinates of one element of the matrix. If the element of the read position is 0, then it should become 1 and:
all zeros above that element to the first element with value 1 or to the start of the column,
all zeros bellow that element to the first element with value 1 or to the end of the column,
all zeros left from that element to the first element with value 1 or to the begin of the row and
all zeros right from that element to the first element with value 1 or to the end of the row.
If the element of the given position is 1 than the matrix stays unchanged.
Print the changed matrix.*/

#include <iostream>
using namespace std;

void updateMatrix(int matrix[100][100], int m, int n, int row, int col) {
    if (matrix[row][col] == 1) {
        return;
    }
    for (int i = row - 1; i >= 0 && matrix[i][col] == 0; i--) {
        matrix[i][col] = 1;
    }
    for (int i = row + 1; i < m && matrix[i][col] == 0; i++) {
        matrix[i][col] = 1;
    }
    for (int j = col - 1; j >= 0 && matrix[row][j] == 0; j--) {
        matrix[row][j] = 1;
    }
    for (int j = col + 1; j < n && matrix[row][j] == 0; j++) {
        matrix[row][j] = 1;
    }
    matrix[row][col] = 1;
}

int main() {
    int m, n;
    int matrix[100][100];
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    int row, col;
    cin >> row >> col;
    updateMatrix(matrix, m, n, row, col);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

