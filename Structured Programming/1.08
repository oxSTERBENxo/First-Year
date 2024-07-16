/*Од стандарден влез се внесуваат два цели броја N и Х. Да се најде најблискот број помал од N коj е тотално различен од бројот Х.
Еден број е тотално различен од друг ако и само ако во него не се појавува ниту една од цифрите на другиот број.
Задачата да се реши без употреба на низи и матрици.*/


#include <iostream>
using namespace std;
int main() {
    int n,x;
    cin>>n>>x;
    for(int i=n-1;i<=n;i--){
        int tempi=i;
        bool flag=true;
        while(tempi){
            int tempx=x;
            int e=tempi%10;
            tempi=tempi/10;
            while(tempx){
                int e1=tempx%10;
                tempx=tempx/10;
                if(e==e1){
                    flag=false;
                }
            }
        }
        if(flag){
        cout<<i<<endl;
        return 0;
        }
    }
}
