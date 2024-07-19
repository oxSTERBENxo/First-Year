/*Да се напише програма која вчитува матрица со димензии MxN (макс. 100x100). На почетокот се внесуваат димензиите на матрицата, а потоа и 
елементите на матрицата кои се само вредностите 1 и 0. Програмата треба да изброи и отпечати на СИ во колку од редиците и колоните има барем 3 
последователни елементи со вредност 1.

Пример:
1111
0011
0011
 
1 ред + 1 колона = 2*/



#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int m,n,mat[100][100];
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]== 1 && mat[i][j+1]==1 && mat[i][j+2]==1){
                count++;
                break;
            }
        }
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            if(mat[i][j]== 1 && mat[i+1][j]==1 && mat[i+2][j]==1){
                count++;
                break;
            }
        }
    }
    cout<<count;
}
