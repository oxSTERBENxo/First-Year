/*Eден природен e „интересен“ ако неговиот обратен број е делив со неговиот број на цифри. Обратен број е бројот составен од истите цифри,
но во обратен редослед (на пример, 653 е обратен број на бројот 356). Од тастатура се внесува природен број n ( n > 9). Да се најде и отпечати најголемиот
природен број помал од n кој што е „интересен“. Ако внесениот број не е валиден, да се отпечати соодветна порака (Brojot ne e validen). */


#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int temp1=n-1;
    if(n<10){
        cout<<"Brojot ne e validen"<<endl;
    }
    else{
        while(temp1){
            int temp=temp1;int obraten=0,count=0;
            while(temp){
                int c=temp%10;
                count++;
                temp=temp/10;
                obraten=obraten*10+c;
            }
            if(obraten%count==0){cout<<temp1;return 0;}
            temp1--;
        }
    }
}
