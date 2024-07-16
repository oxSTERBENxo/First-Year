/*Од стаднарден влез се читаат N низи од знаци (стрингови) не подолги од 80 знаци. На почетокот на програмата се читаат два цели броеви:
N - бројот на низи од знаци кои ќе се читаат и
X - поместување.
Секоја од вчитаните низи од знаци треба да се трансформира на тој начин што секоја од малите и големите букви (a-z, A-Z) се заменува со истата буква 
поместена X места понапред во азбуката (a-z). Ако се надмине опсегот на буквите во азбуката, се продолжува циклично од почетокот на азбуката. Трансформираната 
низа да се отпечати на СИ.
Трансформацијата да се имплементира со посебна рекурзивна функција.
Пример:
Welcome -> трансформирано со поместување 5 -> Bjqhtrj*/



#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n,x;
    cin>>n;
    cin.ignore();
    cin>>x;
    cin.ignore();
    char baza;
   while(n){
       n--;
       char niza[80];
       cin.getline(niza,80);
       if(niza[0]=='\0'){
           continue;
       }
       for(int i=0;i<strlen(niza);i++){
           if(!isalpha(niza[i])){
               continue;
           }
           if(niza[i]>='A' && niza[i]<='Z'){
               baza='A';
           }
           if(niza[i]>='a' && niza[i]<='z'){
               baza='a';
           }
           int pomesteno=(niza[i]-baza+x)%26 +baza;

           niza[i]=pomesteno;
       }
       for(int i=0;i<strlen(niza);i++){
           cout<<niza[i];
       }
       cout<<endl;
   }
}
