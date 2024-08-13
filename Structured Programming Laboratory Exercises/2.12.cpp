/*Од стандарден влез се вчитува матрица сo n редици и n колони. Прво се вчитува бројот n потоа и елементите на матрицата. Матрицата треба да се трансформира така што
секој елемент што се наоѓа десно од споредната дијагонала од истата редица и е помал од просекот на елементите лево од споредната дијагонала од истата редица треба да 
се замени со -1. Вака трансформираната матрица да се испечати на екран.
Објаснување на примерот:
2 3 5 9
7 8 4 2
4 2 3 5
7 10 9 2
Пример за втората редица, елементот од споредната дијагонала е 4, лево од него се 7 и 8, нивен просек е 7.5 , десно од него е 2, 2 е помал од 7.5 и затоа се заменува со -1.*/

#include <iostream>
using namespace std;

void transformMatrix(int matrix[100][100], int n) {
    for (int i = 0; i < n; i++) {
        int sumLeft = 0, countLeft = 0;

        for (int j = 0; j < n - i - 1; j++) {
            sumLeft += matrix[i][j];
            countLeft++;
        }

        double averageLeft;
        if (countLeft > 0) {
            averageLeft = (double)sumLeft / countLeft;
        } else {
            averageLeft = 0;
        }

        for (int j = n - i; j < n; j++) {
            if (matrix[i][j] < averageLeft) {
                matrix[i][j] = -1;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int matrix[100][100];
    
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
