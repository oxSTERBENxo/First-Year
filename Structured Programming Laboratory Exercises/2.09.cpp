/*Од стандарден влез се внесува големината на еден фудбалски терен MxN. Потоа се внесува локацијата на играчот на тој терен (x_igrac, y_igrac), 
па се внесува локацијата на топката (x_topka, y_topka) и локацијата на голот (x1_gol, y1_gol) (x2_gol, y2_gol). Од кога ќе се внесат овие вредности треба да се испечати
фудбалскиот терен, во фудбалскиот терен играчот е означен со карактер 'i', голот е означен со карактер ']' и топката е означена со 'o', се останато се означува со '-'.
Ваша задача е најпрво да го испечатите на екран фудбалскиот терен според внесените вредности. Потоа од стандарден влез се внесуваат две вредности за поместувањето
на топката за x координатата и поместувањето на топката за у координатата. По поместувањето на топката доколку се наоѓа во голот се печати GOAL, доколку се наоѓа надвор
од фудбалскиот терен се печати OUT и доколку се наоѓа во теренот, но не е гол се печати новата позиција на топката и фудбалскиот терен со новата позиција на топката. 
Напомена: За репрезентација на фудбалскиот терен користете матрица.*/

#include <iostream>
using namespace std;

int main() {
    int m, n, x_igrac, y_igrac, x_topka, y_topka, x1_gol, y1_gol, x2_gol, y2_gol, dx, dy;
    char field[100][100];
    cin >> m >> n;
    cin >> x_igrac >> y_igrac >> x_topka >> y_topka;
    cin >> x1_gol >> y1_gol >> x2_gol >> y2_gol;
    cin >> dx >> dy;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            field[i][j] = '-';
        }
    }
    if (x_igrac >= 0 && x_igrac < m && y_igrac >= 0 && y_igrac < n) {
        field[x_igrac][y_igrac] = 'i';
    }
    if (x_topka >= 0 && x_topka < m && y_topka >= 0 && y_topka < n) {
        field[x_topka][y_topka] = 'o';
    }
    if ((x1_gol >= 0 && x1_gol < m && y1_gol >= 0 && y1_gol < n) &&
        (x2_gol >= 0 && x2_gol < m && y2_gol >= 0 && y2_gol < n)) {
        field[x1_gol][y1_gol] = ']';
        field[x2_gol][y2_gol] = ']';
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << field[i][j]<<" ";
        }
        cout << endl;
    }
    cin >> dx >> dy;
    if (x_topka >= 0 && x_topka < m && y_topka >= 0 && y_topka < n) {
        field[x_topka][y_topka] = '-';
    }
    x_topka += dx;
    y_topka += dy;

    if (x_topka < 0 || x_topka >= m || y_topka < 0 || y_topka >= n) {
        cout << "OUT!" << endl;
    }
    else {
        field[x_topka][y_topka] = 'o';

        if ((x_topka == x1_gol && y_topka == y1_gol) ||
            (x_topka == x2_gol && y_topka == y2_gol)) {
            cout << "GOAL!" << endl;
        }
        else {
            cout<<"Novata pozicija na topkata e (";
            cout << x_topka << ", " << y_topka <<")"<< endl;

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    cout << field[i][j]<<" ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
