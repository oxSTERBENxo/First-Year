/*Да се напише програма која чита две целобројни матрици со димензија mxn, а потоа печати колку колони од првата матрица се наоѓаат во втората матрица.*/

#include <iostream>
using namespace std;

int main() {
    int m, n, mat1[100][100], mat2[100][100], counter=0;
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
    for (int col1 = 0; col1 < n; col1++) {
        bool found = false;
        for (int col2 = 0; col2 < n; col2++) {
            bool isti = true;
            for (int i = 0; i < m; i++) {
                if (mat1[i][col1] != mat2[i][col2]) {
                    isti = false;
                    break;
                }
            }
            if (isti) {
                found = true;
                break;
            }
        }
        if (found) {
            counter++;
        }
    }
    cout << counter << endl;
    return 0;
}
