/*Од стандарден влез се читаат низи од знаци се додека не се прочита знакот #. Да се напише програма во која од за секој прочитан ред ќе се отпечати бројот на 
цифри во тој ред, знакот :, па самите цифри подредени според ASCII кодот во растечки редослед. Низите од знаци не се подолги од 100 знаци.*/



#include <iostream>
#include <cstring>
using namespace std;
int main(){
    while(true){
        char b[100]="";
        int count=0;
        char niza[100];
        cin.getline(niza,100);
        if(niza[0]=='\0'){
            continue;
        }
        if(niza[0]=='#'){
            break;
        }
        for(int i=0,j=0;i<strlen(niza);i++){
            if(niza[i]>='0' && niza[i]<='9'){
                count++;
                b[j++]=niza[i];
            }
            
        }
        for(int i=0;i<strlen(niza);i++){
            for(int j=0;j<strlen(niza)-1-i;j++){
                if(niza[j]>niza[j+1]){
                    swap(niza[j],niza[j+1]);
                }
            }
        }
        cout<<count<<":";
        for(int i=0;i<strlen(b);i++){
            cout<<niza[i];
        }
        cout<<endl;
    }
}
