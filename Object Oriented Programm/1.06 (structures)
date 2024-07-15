/*Да се креира структура Воз во која се чуваат податоци за:
- релацијата по која се движи возот(низа од најмногу 50 знаци), предвиден бројот на километри што треба да се поминат (реален број), 
како и бројот на патници во возот (цел број).
Потоа да се креирa структура ZeleznickaStanica во која се чуваат податоци за:
- градот во кој се наоѓа (низа од 20 знаци), низа од возови што поаѓаат од станицата (најмногу 30) и бројот на возови (цел број).
Треба да се направи функција со потпис void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad) во која се печати релацијата и бројот на километри на возот
што поминува најкратка релација (најмалку километри), а поаѓа од железничката станица од градот што се проследува како влезен аргумент. Ако има повеќе возови со ист
најмал број на километри, да се испечати релацијата на последниот таков.*/

#include <iostream>
#include <cstring>
using namespace std;
typedef struct Voz{
    char relacija[50];
    float kilometri;
    int patnici;
}Voz;
typedef struct ZeleznickaStanica{
    char grad[20];
    Voz vozovi[30];
    int br;
}ZeleznickaStanica;
void najkratkaRelacija(ZeleznickaStanica *zs, int n, char *grad){
    for(int i=0;i<n;i++){
        if(strcmp(zs[i].grad,grad)==0){
            Voz minv=zs[i].vozovi[0];
            for(int j=0;j<zs[i].br;j++){
                if(zs[i].vozovi[j].kilometri<=minv.kilometri){
                    minv=zs[i].vozovi[j];
                }
            }
            cout<<"Najkratka relacija: "<<minv.relacija<<" ("<<minv.kilometri<<" km)"<<endl;
        }
    }
}
int main(){
    int n;
    cin>>n; //se cita brojot na zelezlnichki stanici
    
    ZeleznickaStanica zStanica[100];
    for (int i=0;i<n;i++){
     //se citaat infomracii za n zelezlnichkite stanici i se zacuvuvaat vo poleto zStanica
        char relacija[50],grad[20];
        int kilometri,patnici,br;
        cin>>grad;
        cin>>br;
        for(int j=0;j<br;j++){
            cin>>relacija>>kilometri>>patnici;
            strcpy(zStanica[i].vozovi[j].relacija,relacija);
            zStanica[i].vozovi[j].kilometri=kilometri;
            zStanica[i].vozovi[j].patnici=patnici;
        }
        strcpy(zStanica[i].grad,grad);
        zStanica[i].br=br;
    }

    char grad[25];
    cin>>grad;

    najkratkaRelacija(zStanica,n,grad);
    return 0;
}
