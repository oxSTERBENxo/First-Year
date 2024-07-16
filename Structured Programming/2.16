/*Да се напише рекурзивна функција за наоѓање на максималната цифра од даден цел број.
Од стандарден влез се внесуваат непознат број цели броеви се додека не се внесе нешто што не е број. За секој од нив да се испечати максималната цифра во посебен ред.
Не користи глобални променливи.*/



#include <iostream>
using namespace std;

int maksimalna_cifra(int n,int maks){
    if(n==0){
        return maks;
    }else{
        int cifra=n%10;
        if(maks<cifra){
        maks=cifra;
            }
        return maksimalna_cifra(n/10,maks);
    }
}
int main(){
   int n;
   while(cin>>n){
       cout<<maksimalna_cifra(n,n%10)<<endl;
   }
}
