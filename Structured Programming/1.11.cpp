/*Цик-цак е број за кој важи дека за секој пар соседни цифри во бројот важи дека едната е помала од 5, а другата е поголема или еднаква на 5. 
На пример, ако бројот x е составен од цифрите a, b, c и d, тогаш за нив важи:
a<5, b>=5, c<5, d>=5 или a>=5, b<5, c>=5, d<5
Пр.  508294, 2638, 81
Од тастатура се читаат непознат број на цели броеви поголеми од или еднакви на 10 (броевите помали од 10 се игнорираат). 
Читањето завршува во моментот кога ќе се прочита знак што не е цифра. Да се испечатат сите цик-цак броеви.*/



#include <iostream>
using namespace std;
int main(){
    int x;
   while(cin>>x){
       if(x>=10){
           int tempx=x;
           bool niza1=true;
           bool niza2=true;
           int brojac=1;
           while(tempx){
               int cifra=tempx%10;
               if(brojac%2==1){
                   if(cifra<5){
                       niza1=false;
                   }
                   else{niza2=false;}
               }
               else{
                   if(cifra<5){
                       niza2=false;
                   }
                   else{
                       niza1=false;
                   }
               }
               brojac++;
               tempx=tempx/10;
           }
       if(niza1||niza2){cout<<x<<endl;}
      }
   }
}
