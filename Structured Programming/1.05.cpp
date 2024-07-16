/*Од тастатура се читаат 2 позитивни цели броеви. Доколку се внесе барем еден негативен број или 0 треба да се печати „Invalid input“.
Треба да се определи дали помалиот број “е парен еквивалент” од поголемиот број.
Еден број “е парен еквивалент” на друг број, ако и само ако неговите цифри се наоѓаат на парните позиции од другиот број, во истиот редослед. 
Соодветно да се испечатат пораки „PAREN“ и „NE“.
Позициите треба да се сметаат оддесно-налево (најмалку значајната цифра е на позиција 1)*/


#include <iostream>
using namespace std;
int main(){
    int a,b,count=0;
    bool flag;
    cin>>a>>b;
    if(a<=0 || b<=0){
        cout<<"Invalid input";
        return 0;
    }
    else{
        if(a<b){
           int temp=a;
           a=b;
           b=temp;
        }
        int tempa=a;
        while(tempa){
            tempa=tempa/10;
            count++;
        }
        int tempb=b;
        while(count){
            if(tempb%10==(a/10)%10){
                tempb=tempb/10;
                a=a/100;
                flag=true;
                count--;
            }
            else{
                flag=false;
                break;
            }
        }
        if(flag){cout<<"PAREN";}
        else{cout<<"NE";}
    }
    
}
