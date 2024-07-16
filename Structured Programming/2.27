/*Четиринасочник претставува матрица во која се испишани зборови хоризонотално и вертикално, одлево-надесно и оддесно-налево. Притоа секој елемент
од матрицата претставува буква од англиската азбука. пример скриени зборови: HAIR, OLE (прецртани), FISH, TOE (подвлечени) //SEE IN PICTURES

T H A I R E
E S N K N E
M I M J O L
M F S P S T
I F G E L O
X U T Y O E

Од стандарден влез се чита квадратна матрица од ред n (3 <= n <= 50), составена од знаци. Прво се чита бројот n - бројот на редици (колони) на матрицата, 
а потоа и самите елементи на матрицата (види пример). По читањето на матрицата, од стандарден влез се внесува збор составен од максимум 10 букви.
Ваша задача е да определите дали тој збор се наоѓа во четиринасочникот (хоризонтално или вертикално, одлево-надесно или оддесно-налево). Потребно е да се 
испечати локацијата (ред, колона) на првата и последната буква од зборот. Доколку зборот повеќепати се наоѓа во четеринасочникот, треба да се испечати првото 
појавување, гледано елемент по елемент како што се чита матрицата. Доколку не се пронајде зборот, тогаш се печати Not Found.*/


#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    char mat[50][50], zbor[10];
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    cin >> zbor;
    int bukva1 = zbor[0];

    // Horizontal left to right
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - strlen(zbor) + 1; j++) {
            if (bukva1 == mat[i][j]) {
                int k;
                for (k = 0; k < strlen(zbor); k++) {
                    if (mat[i][j + k] != zbor[k]) {
                        break;
                    }
                }
                if (k == strlen(zbor)) {
                    cout << i << ", " << j << " -> " << i << ", " << j + strlen(zbor) - 1 << endl;
                    return 0;
                }
            }
        }
    }

    // Horizontal right to left
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= strlen(zbor); j--) {
            if (bukva1 == mat[i][j]) {
                int k;
                for (k = 0; k < strlen(zbor); k++) {
                    if (mat[i][j - k] != zbor[k]) {
                        break;
                    }
                }
                if (k == strlen(zbor)) {
                    cout << i << ", " << j << " -> " << i << ", " << j - strlen(zbor) + 1 << endl;
                    return 0;
                }
            }
        }
    }

    // Vertical top to bottom
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - strlen(zbor) + 1; i++) {
            if (bukva1 == mat[i][j]) {
                int k;
                for (k = 0; k < strlen(zbor); k++) {
                    if (mat[i + k][j] != zbor[k]) {
                        break;
                    }
                }
                if (k == strlen(zbor)) {
                    cout << i << ", " << j << " -> " << i + strlen(zbor) - 1 << ", " << j << endl;
                    return 0;
                }
            }
        }
    }

    // Vertical bottom to top
    for (int j = 0; j < n; j++) {
        for (int i = n - 1; i >= strlen(zbor)-1 ; i--) {
            if (bukva1 == mat[i][j]) {
                int k;
                for (k = 0; k < strlen(zbor); k++) {
                    if (mat[i - k][j] != zbor[k]) {
                        break;
                    }
                }
                if (k == strlen(zbor)) {
                    cout << i << ", " << j << " -> " << i - strlen(zbor) + 1 << ", " << j << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Not Found" << endl;

    return 0;
}

       
