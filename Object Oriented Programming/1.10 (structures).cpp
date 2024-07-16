//The main function isn't given
/*Да се креира структура Igrac во која се чуваат податоци за еден играч на компјутерската игра. За играчот се чуваат информации за: 
корисничкото име на играчот (низа од 15 знаци), број на ниво до кој играчот е стигнат (цел број), број на освоени поени (цел број).
Потоа да се креирa структура KompjuterskaIgra во која се чуваат податоци за: 
името на играта (низа од 20 знаци), низа од играчи кои ја играат играта (најмногу 30) и бројот на играчи.
Треба да се направи функција со потпис void najdobarIgrac(KompjuterskaIgra *lista, int n).
Оваа функција треба да го испечати името на најдобриот играч на онаа игра која има најголема популарност (ја играат наjголем број на играчи). 
Најдобар играч е играчот кој има најголем број на освоени поени. Ако има повеќе играчи со ист максимален број на освоени поени, 
најдобар е играчот кој има достигнато најголемо ниво. Печатењето е во форматот: 
"Najdobar igrac e igracot so korisnicko ime XXXXX koj ja igra igrata YYYYYY". 
(XXXXXX е корисничкото име на најдобриот играч,а YYYYY е името на играта која ја играат најголем број на играчи)
(Забелешка: секогаш ќе има точно еден најдобар играч)*/

#include<iostream>
using namespace std;
struct Igrac {
    char korisnickoIme[15];
    int nivo;
    int poeni;
};
struct KompjuterskaIgra {
    char ime[20];
    Igrac lista[30];
    int n;
};
void najdobarIgrac(KompjuterskaIgra *igri,int n) {
    int indeksNajmnoguIgraci=0;
    for (int i=1; i<n; i++) {
        if (igri[i].n>igri[indeksNajmnoguIgraci].n)
            indeksNajmnoguIgraci=i;
    }
    int indeksmax=0;
    KompjuterskaIgra najpopularna=igri[indeksNajmnoguIgraci];
    for (int i=1; i<najpopularna.n; i++) {
        if (najpopularna.lista[i].poeni>najpopularna.lista[indeksmax].poeni)
            indeksmax=i;
        else if (najpopularna.lista[i].poeni==najpopularna.lista[indeksmax].poeni) {
            if (najpopularna.lista[i].nivo>najpopularna.lista[indeksmax].nivo)
                indeksmax=i;
        }
    }
    cout<<"Najdobar igrac e igracot so korisnicko ime ";
    cout<<najpopularna.lista[indeksmax].korisnickoIme;
    cout<<" koj ja igra igrata ";
    cout<<najpopularna.ime;
}
int main() {
    int n;
    char ime[20];
    cin>>n;
    KompjuterskaIgra igri[100];
    for (int i=0; i<n; i++) {
        KompjuterskaIgra nova;
        cin>>nova.ime>>nova.n;
        Igrac igraci[100];
        for (int j=0; j<nova.n; j++) {
            Igrac nov;
            cin>>nov.korisnickoIme>>nov.nivo>>nov.poeni;
            nova.lista[j]=nov;
        }
        igri[i]=nova;
    }

    najdobarIgrac(igri,n);
    return 0;
}
