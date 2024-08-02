/*Write a program that reads matrix with dimensions MxN (max. 100x100). At the beginning the dimensions are read, and then the elements of the matrix with
values 0 or 1. Your program should count and print on SO the number of rows and columns with at least 3 consecutive appearance of elements with value 1.
Example:
1 1 1 1
0 0 1 1
0 0 1 1
1 row + 1 column = 2*/

#include <iostream>
using namespace std;

int countConsecutiveOnes(int arr[], int size) {
    int consecutiveCount = 0;
    int maxConsecutive = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 1) {
            consecutiveCount++;
            if (consecutiveCount >= 3) {
                if (consecutiveCount > maxConsecutive) {
                    maxConsecutive = consecutiveCount;
                }
            }
        } else {
            consecutiveCount = 0;
        }
    }
    return maxConsecutive;
}

int main() {
    int M, N;
    int matrix[100][100];
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    int rowsWithConsecutiveOnes = 0;
    for (int i = 0; i < M; i++) {
        if (countConsecutiveOnes(matrix[i], N) >= 3) {
            rowsWithConsecutiveOnes++;
        }
    }
    int columnsWithConsecutiveOnes = 0;
    for (int j = 0; j < N; j++) {
        int consecutiveCount = 0;
        for (int i = 0; i < M; i++) {
            if (matrix[i][j] == 1) {
                consecutiveCount++;
                if (consecutiveCount >= 3) {
                    columnsWithConsecutiveOnes++;
                    break;
                }
            } else {
                consecutiveCount = 0;
            }
        }
    }

    cout<<columnsWithConsecutiveOnes+rowsWithConsecutiveOnes<<endl;
    return 0;
}
