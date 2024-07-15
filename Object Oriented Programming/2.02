/*Да се дефинира класа Vozac во која се чуваат информации за:
- име (низа од максимум 100 знаци), возраст (цел број), број на трки (цел број), дали е ветеран (да/не).
Да се преоптоварат:
- операторот << за печатење кој ќе ги печати името, возраст, бројот на трки и дали е ветеран (се печати VETERAN)
- операторот == за споредување на два возачи според заработувачката по трка.
Од оваа класа да се изведат две нови класи Avtomobilist и Motociklist.
- За автомобилистот дополнително се чува: цена на автомобилот (децимален број).
- За мотоциклистот дополнително се чува: моќност на мотор (цел број).
Заработувачката по трка на возачите се пресметува како:
- за автомобилостот заработувачката по трка е $\frac{CENA_{AVTOMOBIL}}{5}$ // (cena_na_avtomobil/5)
- за мотоциклистот заработувачката по трка е $MOKJNOST_NA_MOTOR * 20$ // (mokjnost_na_motor*20)
Секој автомобилист плаќа данок на заработка. Да се напишат соодветни методи за пресметување данок:
- за автомобилисти: ако бројот на трки е поголем од 10 стапката на данок е 15% од заработката, инаку 10% од заработката.
- за мотоциклисти: ако е ветеран стапката на данок е 25% од заработката, инаку 20% од заработката.
Да се напше надворешна функција soIstaZarabotuvachka која како аргументи прима низа од покажувачи од класата Vocac, нивниот број, 
како и покажувач кон ојбект од возач и враќа како резултат бројот на возачи кои имаат иста заработувачка по трка со проследениот возач.*/

#include <iostream>
#include <cstring>
using namespace std;
class Vozac{
protected:
    char name[100];
    int age;
    int races;
    bool isV;
public:
    Vozac(char *name="", int age=0, int races=0, bool isV=0){
        strcpy(this->name, name);
        this->age=age;
        this->races=races;
        this->isV=isV;
    }

    friend ostream &operator<<(ostream &os, const Vozac &vozac) {
        os << vozac.name <<endl;
        os<< vozac.age <<endl;
        os << vozac.races<<endl;
        if(vozac.isV){
            cout<<"VETERAN"<<endl;
        }
        return os;
    }
    virtual double zarabotuvacka() =0;
    virtual double danok()=0;
    bool operator==(Vozac &rhs){
        return zarabotuvacka() == rhs.zarabotuvacka();
    }
};
class Avtomobilist:public Vozac{
private:
    float price;
public:
    Avtomobilist(char *name="", int age=0, int races=0, bool isV=0, float price=0) : Vozac(name, age, races, isV), price(price) {}
    double zarabotuvacka() override {
        double cena;
        cena=price/5;
        return cena;
    }
    double danok() override {
        double danok;
        if(races>10){
            danok=zarabotuvacka()*0.15;
        }else{
            danok=zarabotuvacka()*0.1;
        }
        return danok;
    }
};
class Motociklist: public Vozac{
private:
    int mokjnost;
public:
    Motociklist(char *name="", int age=0, int races=0, bool isV=0,int mokjnost=0) : Vozac(name, age, races, isV),mokjnost(mokjnost) {}

    double zarabotuvacka() override {
        double cena;
        cena=mokjnost*20.0;
        return cena;
    }

    double danok() override {
        double danok;
        if(isV){
            danok=zarabotuvacka()*0.25;
        }else{
            danok=zarabotuvacka()*0.2;
        }
        return danok;
    }
};

int soIstaZarabotuvachka(Vozac **pVozac, int n, Vozac *pVozac1) {
    int count=0;
    for(int i=0;i<n;i++){
        if(pVozac[i]->zarabotuvacka()==pVozac1->zarabotuvacka()){
            count++;
        }
    }
    return count;
}

int main() {
    int n, x;
    cin >> n >> x;
    Vozac **v = new Vozac*[n];
    char ime[100];
    int vozrast;
    int trki;
    bool vet;
    for(int i = 0; i < n; ++i) {
        cin >> ime >> vozrast >> trki >> vet;
        if(i < x) {
            float cena_avto;
            cin >> cena_avto;
            v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
        } else {
            int mokjnost;
            cin >> mokjnost;
            v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
        }
    }
    cout << "=== DANOK ===" << endl;
    for(int i = 0; i < n; ++i) {
        cout << *v[i];
        cout << v[i]->danok() << endl;
    }
    cin >> ime >> vozrast >> trki >> vet;
    int mokjnost;
    cin >> mokjnost;
    Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
    cout << "=== VOZAC X ===" << endl;
    cout << *vx;
    cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
    cout << soIstaZarabotuvachka(v, n, vx);
    for(int i = 0; i < n; ++i) {
        delete v[i];
    }
    delete [] v;
    delete vx;
    return 0;
}
