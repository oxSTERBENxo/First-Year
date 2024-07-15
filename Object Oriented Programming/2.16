/*Туристичка агенција нуди различни понуди за транспорт на патници. За секоја понуда се чуваат податоци за:
- дестинацијата (низа од знаци), основна цена (цел број) и податок за растојанието до дестинацијата изразено во km (цел број).
Од класата Transport да се изведат класите AvtomobilTransport и KombeTransport за моделирање на понудите за транспорт кои нудат транспорт со автомобил или комбе, соодветно. 
За секоја понуда за транспорт со автомобил се чува податок за тоа дали во понудата има платен шофер (булова променлива), 
а за транспорт со комбе бројот на луѓе кои може да се превезат во комбето (цел број).
За секој објект од двете изведени класи треба да бидат на располагање следниве методи:
- конструктор со аргументи што одговараат на податочните членови и set и get методи за податочните членови
- метод cenaTransport, за пресметување на цената на понудата на следниот начин:
  За транспорт со автомобил - основната цена се зголемува за 20% ако има платен шофер
  За транспорт со комбе - основната цена ќе се намали зависно од бројот на патници во комбето. За секој патник во комбето цената се намалува за 200
- преоптоварен оператор < за споредба на две понуди за транспорт на патник според растојанието до дестинацијата. (5 поени)
- Да се имплементира функција pecatiPoloshiPonudi што на влез прима низа од понуди за транспорт на патник, бројот на елементите од низата и една понуда T. Функцијата ја 
печати дестинацијата, растојанието до дестинацијата и цената за понудите од низата кои се поскапи од понудата T сортирани во растечки редослед по растојанието до
дестинацијата (погледни го повикот на функцијата).*/

#include <iostream>
#include <cstring>
using namespace std;

class Transport{
protected:
    char destinacija[20];
    int cena;
    int rastojanie;
public:
    Transport(){}
    Transport(char* destinacija, int cena, int rastojanie){
        strcpy(this->destinacija,destinacija);
        this->cena=cena;
        this->rastojanie=rastojanie;
    }
    virtual double cenaTransport() = 0;
    bool operator<(const Transport &rhs) const {
        return rastojanie < rhs.rastojanie;
    }
    friend ostream &operator<<(ostream &os, Transport &dr){
        os<<dr.destinacija<<" "<<dr.rastojanie<<" "<<dr.cenaTransport()<<endl;
        return os;
    }
    virtual ~Transport(){}
};

class AvtomobilTransport :public Transport{
    bool shofer;
public:
    AvtomobilTransport():Transport(){}
    AvtomobilTransport(char* destinacija, int cena, int rastojanie, bool shofer)
            :Transport(destinacija, cena, rastojanie){
        this->shofer=shofer;
    }
    double cenaTransport(){
        double c=cena;
        if(shofer) {
            c = cena * 1.2;
            return c;
        }
        return c;
    }
};

class KombeTransport: public Transport{
    int luge;
public:
    KombeTransport():Transport(){}
    KombeTransport(char* destinacija, int cena, int rastojanie, int luge)
            :Transport(destinacija, cena, rastojanie){
        this->luge=luge;
    }
    double cenaTransport(){
        double c=cena;
        c = cena - 200 * luge;
        return c;
    }
};

void pecatiPoloshiPonudi(Transport** ponudi, int n, Transport &t){
    int counter=0;
    for(int i=0;i<n;i++){
        if(ponudi[i]->cenaTransport()>t.cenaTransport()){
            counter++;
        }
    }
    int j=0;
    Transport **temp=new Transport * [counter];
    for(int i=0;i<n;i++) {
        if (t.cenaTransport()<ponudi[i]->cenaTransport() ) {
            temp[j++]=ponudi[i];
        }
    }
    for(int i=0; i < counter; i++){
        for(j=0; j < counter-1; j++){
            if(*temp[i]<*temp[j]){
                swap(temp[i],temp[j]);
            }
        }
    }
    for(int i=0; i < counter; i++){
        cout<<*temp[i];
    }
}

int main(){

    char destinacija[20];
    int tip,cena,rastojanie,lugje;
    bool shofer;
    int n;
    cin>>n;
    Transport  **ponudi;
    ponudi=new Transport *[n];

    for (int i=0;i<n;i++){

        cin>>tip>>destinacija>>cena>>rastojanie;
        if (tip==1) {
            cin>>shofer;
            ponudi[i]=new AvtomobilTransport(destinacija,cena,rastojanie,shofer);

        }
        else {
            cin>>lugje;
            ponudi[i]=new KombeTransport(destinacija,cena,rastojanie,lugje);
        }


    }

    AvtomobilTransport nov("Ohrid",2000,600,false);
    pecatiPoloshiPonudi(ponudi,n,nov);

    for (int i=0;i<n;i++) delete ponudi[i];
    delete [] ponudi;
    return 0;
}
