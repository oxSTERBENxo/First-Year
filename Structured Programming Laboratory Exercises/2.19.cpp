/*На стандарден влез се читаат два броја a и b. Ваша задача е да ја најдете најголемата непарна цифра на секој број во опсег [a,b]. Функцијата за наоѓање на
најголема непарна цифра мора да е рекурзивна. Напомена: ако бројот нема непарни цифри се печати 0. Печатење на секој број и негова цифра е во формат: број -> цифра*/

#include <iostream>
using namespace std;
int najgolemaNeparnaCifra(int n){
    if(n<10){
        if(n%2!=0){
            return n;
        }else{
            return 0;
        }
    }else{
        int cifra=n%10;
        if(cifra%2==0){
            return najgolemaNeparnaCifra(n/10);
        }else{
            if(cifra<najgolemaNeparnaCifra(n/10)){
                return najgolemaNeparnaCifra(n/10);
            }else{
                return cifra;
            }
        }

    }
}
int main(){
int a,b;
cin>>a>>b;
for(int i=a;i<=b;i++){
    cout<<i<<" -> "<<najgolemaNeparnaCifra(i)<<endl;
}
}
