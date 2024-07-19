/*Read the dimension N (with a maximum value of 100) and the values (possible values are only 1 and 0) of one square matrix $A_ {NxN}$ from the standard input. 
Create a new matrix $B_ {NxN}$ in the following way: For each element in B, write the value of the same corresponding element from A. During this procedure, 
if in the neighborhood of one element of A (neighbors are the elements above it or below it, on the left or right side of it) there are minimum 3 elements with
a value of 1, then that element in the matrix B gets a value of 1 (although in A the corresponding value was zero). Print the newly obtained matrix B.
Example:
Matrix А:       Matrix B:
1 0 0 1 0       1 0 0 1 0
1 1 0 1 0       1 1 1 1 0 
1 1 1 1 1       1 1 1 1 1
0 1 0 0 1       1 1 1 1 1
1 0 1 1 0       1 1 1 1 0
*/


#include <iostream>
using namespace std;

int neighbors(int A[100][100], int i, int j, int n) {
    int count = 0;
    if (i > 0 && A[i-1][j] == 1) count++;       //up
    if (i < n - 1 && A[i + 1][j] == 1) count++; //down
    if (j > 0 && A[i][j-1] == 1) count++;       //left
    if (j < n - 1 && A[i][j + 1] == 1) count++; //right
    return count;
}

int main() {
    int n, A[100][100], B[100][100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            B[i][j] = A[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 0) {
                if (neighbors(A, i, j, n) >= 3) {
                    B[i][j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
