/*Од стандарден влез се чита цел број N (N<=100) и потоа N низи од знаци. Низите знаци содржат букви, цифри и специјални знаци (без знаци за празно место), а секоја 
од нив не е подолга од 80 знаци. Да се напише програма со која што на стандарден излез ќе се отпечати најдолгата низа, којашто е палиндром 
(се чита исто од од лево на десно и од десно на лево) и што содржи барем еден специјален знак. Ако нема такви низи, се печати "Nema!". Ако има две или повеќе низи 
што го задоволуваат овој услов, се печати првата низа којашто го задоволува условот.
Влез:
9
a!bcdedcb!a
Kfd?vsvv98_89vvsv?dfK
Ccsvsdvdfv
342425vbbcb
352!2353696969625
gdg??dfg!!
5336346644747
8338736767867
12344321
Излез:
Kfd?vsvv98_89vvsv?dfK*/



#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
bool palindrom(char niza[],int len){
 for(int start=0,end=len-1;start<end;start++,end--){
     if(niza[start]!=niza[end]){
         return 0;
     }
 }
    return 1;
}
bool ima_spec(char niza[],int len){
 for(int i=0;i<len;i++){
     if(!isalnum(niza[i])){
         return 1;
     }
 }
 return 0;
}
int main() {
    int n;
    cin>>n;

    char longest[81];
    bool flag=0;

    while(n){
        char niza[80];
        cin>>niza;
        n--;
        int len=strlen(niza);
        if(palindrom(niza,len) && ima_spec(niza,len)){
            if(!flag || len>strlen(longest)){
                strcpy(longest,niza);
                flag=true;
            }
        }
    }

    if(flag){
        cout<<longest;
    }else{
        cout<<"Nema!";
    }
}
