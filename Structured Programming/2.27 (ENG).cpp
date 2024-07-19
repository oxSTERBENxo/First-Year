/*Read the dimensions M and N (not bigger than 100) and the values (whole numbers) of one matrix A_ {MxN} from the standard input. 
Print out the index of the first column that has the smallest sum of all of its elements.*/

#include <iostream>
using namespace std;

int main() {
    int n, m, mat[100][100];
    cin >> m >> n;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }
    int minSum = 0,minIndex = 0;
    for (int i = 0; i < m; ++i) {
        minSum += mat[i][0];
    }
    for (int j = 1; j < n; ++j) {
        int sum = 0;
        for (int i = 0; i < m; ++i) {
            sum += mat[i][j];
        }
        if (sum < minSum) {
            minSum = sum;
            minIndex = j;
        }
    }
    cout<<minIndex<<endl;
    return 0;
}
