/*Од тастатура се внесуваат димензиите на една матрица (m, n <= 100), а потоа и елементите од матрицата. Да се генерира низа (со најмногу m) така што секој 
елемент од низата се добива со наоѓање на елементот во секоја редица од матрицата што е најоддалечен од аритметичката средина во рамки на таа редица. Ако постојат
повеќе елементи што се најоддалечени од аритметичката средина, тогаш се зема предвид првиот. Редоследот на запишување на елементите во низата одговара на редоследот
на редиците.

Пример:
Влез:
3 6
1 2 2 3 4 5
1 1 2 2 3 3
1 2 3 4 5 6
Излез:
5 1 1
*/


#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main() {
    int m,n,mat[100][100],niza[100];
    cin>>m>>n;
    for(int i=0;i<m;i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    for(int i=0;i<m;i++) {
        float as=0.0;
        int max=mat[i][0];
        for (int j = 0; j < n; j++) {
            as=as+mat[i][j];
        }
        as=as/n*1.0;
        for (int j = 0; j < n; j++) {
            if(fabs(mat[i][j]-as)>fabs(as-max)){
                max=mat[i][j];
            }
        }
        niza[i]=max;
        cout<<niza[i]<<" ";
    }

}
