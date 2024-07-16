/*Од тастатура се читаат непознат број на позитивни цели броеви (со максимум 5 цифри) се додека не се внесе нешто различно од број. 
За секој број треба да се најде позицијата (од десно на лево) на првото појавување на најголемата цифра во составот на бројот (цифрата на единици се наоѓа на позиција 0). 
Потоа, да се испечати статистика за позициите на најдените цифри со максимална вредност во следниот формат:
[позиција]: [вкупно броеви чија максимална цифра се наоѓа на таа позиција]
0: 2
1: 3
2: 1
3: 1
4: 1
за броевите 97654 48654 12345 12343 1263 12443 12643 12777*/


#include <iostream>
using namespace std;
int main(){
    int n;
    int poz0=0,poz1=0,poz2=0,poz3=0,poz4=0;
    while(cin>>n){
        int max=0,counter=0,count=0;
        int tempn=n;
        while(tempn){
            tempn=tempn/10;
            count++;
        }
        tempn=n;
        while(tempn) {
                if (tempn % 10 > max) {
                    max = tempn%10;
                }
                tempn = tempn / 10;
        }
        tempn=n;
        for(int i=0;i<count;i++){
            if(tempn%10!=max){
                tempn=tempn/10;
                counter++;
            }
            else{break;}
        }
        if(counter==0){poz0++;}
        if(counter==1){poz1++;}
        if(counter==2){poz2++;}
        if(counter==3){poz3++;}
        if(counter==4){poz4++;}
        counter=0;
    }
    cout<<"0: "<<poz0<<endl;
    cout<<"1: "<<poz1<<endl;
    cout<<"2: "<<poz2<<endl;
    cout<<"3: "<<poz3<<endl;
    cout<<"4: "<<poz4<<endl;
}
