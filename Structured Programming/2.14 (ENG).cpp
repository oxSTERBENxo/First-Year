/*Read a square binary matrix from standard input. First the dimension N is entered (1 < N <= 100) and then the elements of the matrix (either 0 or 1) by rows.
Write a program that will calculate the smallest number of necessary changes of the elements in order to transform the matrix to zero diagonal symmetrical matrix. 
Any transition of an element form 0 to 1 or form 1 to 0 is counts as a single change. After the conversion all the elements of the main diagonal should be 0,
and the matrix should be symmetrical with respect to the main diagonal. Print the minimal number of transitions required.
For example for the input:
4
1 0 0 1
1 1 1 1
0 1 1 1
0 0 0 0
the output should be:
7*/

#include <iostream>
using namespace std;

int main() {
    int n,matrix[100][100],counter=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                counter++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] != 0) {
            counter++;
        }
    }
    cout << counter << endl;
    return 0;
}
