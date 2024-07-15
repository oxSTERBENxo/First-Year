/*Потребно е да се моделира продажба на карти за прикажување на претстави во некој културен центар. За таа цел, да се направи класа DELO. 
За класата се чуваат следните атрибути:
- Име на делото (низа од 50 знаци), Година кога е напишано (цел број), Земја на потекло (низа од 50 знаци).
За класата да се направат потребниот конструктор, get и set методи. 
- За класата DELO да се преоптовари операторот == кој ќе споредува дали две дела се исти (две дела се исти ако имаат исто име).

Да се дефинира класа PRЕTSTAVA. За класата се чуваат информации за:
- Делото кое се прикажува (објект од класата DELO), Број на продадени карти (цел број), Дата на прикажување (низа од 15 знаци).
За класата да се дефинира потребниот конструктор, set и get методите.
- За класата PRETSTAVA да се напише метода cena која треба да ја врати цената на една карта. Цената зависи од староста на делото и од земјата на потекло и се пресметува 
по следната формула: Цена = N + М, каде М = 50ден. ако делото е напишано во 20 или 21 век, М = 75ден. ако делото е напишано во 19 век и М = 100ден. ако делото е напишано 
пред 19 век. N = 100ден ако делото е од Италија, N = 150ден ако делото е од Русија. Делата од останатите земји имаат N = 80ден.
Претставите можат да бидат опера и балет. 
- За балетите се чува дополнителен атрибут за цената на балетот која се додава на оригиналната цена на картата и таа вредност е иста за сите балетски претстави. На почеток 
изнесува 150 денари, со можност да се променува ако така одлучи менаџментот на културниот центар.
- Да се дефинира надворешна функција prihod која како аргумент прима низа од покажувачи кон претстави кои се прикажале во еден месец и големина на низата, а како резултат 
треба да го пресмета и врати вкупниот приход на културниот центар.
- Да се дефинира надворешна функција brojPretstaviNaDelo која како аргумент прима низа од покажувачи кон претстави кои се прикажале во еден месец, големина на низата 
и едно дело. Оваа функција пресметува на колку од дадените претстави е прикажано даденото дело.
(Напомена: Во низата од претстави која се проследува како аргумент во функциите prihod и brojPretstaviNaDelo може да имаме повеќе претстави за едно исто дело)*/

#include<iostream>
#include<string.h>
using namespace std;

class Delo{
    char ime[50];
    int godina;
    char poteklo[50];
public:
    Delo(char *ime="", int godina=0, char *poteklo=""){
        strcpy(this->ime,ime);
        this->godina=godina;
        strcpy(this->poteklo,poteklo);
    }

    bool operator==(const Delo &rhs) const {
        return strcmp(ime,rhs.ime)==0;
    }

    const char *getIme() const {
        return ime;
    }

    int getGodina() const {
        return godina;
    }

    const char *getPoteklo() const {
        return poteklo;
    }
};
class Pretstava{
protected:
    Delo dela;
    int n;
    char data[15];
public:
    Pretstava(){}
    Pretstava(Delo dela, int n, char *data){
        this->n=n;
        strcpy(this->data,data);
        this->dela=dela;

    }
    virtual double cena(){
        double c=0.0;
        if(dela.getGodina()>1899 && dela.getGodina()<2100){
            c=50;
            if(strcmp(dela.getPoteklo(),"Italija")==0){
                c+=100;
            }else if(strcmp(dela.getPoteklo(),"Rusija")==0){
                c+=+150;
            }
            else{
                c+=80;
            }
        }else if(dela.getGodina()>1799 && dela.getGodina()<1900){
            c=75;
            if(strcmp(dela.getPoteklo(),"Italija")==0){
                c+=100;
            }else if(strcmp(dela.getPoteklo(),"Rusija")==0){
                c+=+150;
            }else{
                c+=80;
            }
        }else if(dela.getGodina()<1800){
            c=100;
            if(strcmp(dela.getPoteklo(),"Italija")==0){
                c+=100;
            }else if(strcmp(dela.getPoteklo(),"Rusija")==0){
                c+=+150;
            }else{
                c+=80;
            }
        }
        return c;
    }

    const Delo &getDela() const {
        return dela;
    }

    int getN() const {
        return n;
    }

    const char *getData() const {
        return data;
    }

};

class Opera:public Pretstava{
public:
    Opera(Delo dela=0, int n=0, char *data="") : Pretstava(dela, n, data) {}
    double cena(){
        return Pretstava::cena();
    }
};

class Balet: public Pretstava{
    static double dopCena;
public:
    Balet(Delo dela=0, int n=0, char *data=0): Pretstava(dela, n, data){}
    static void setCenaBalet(double dopCena){
        Balet::dopCena=dopCena;
    }
    double cena(){
        double bazna=Pretstava::cena();
        return bazna+dopCena;
    }
};

double Balet::dopCena=150;

double prihod(Pretstava **pPretstava, int n) {
    double c=0.0;
    for(int i=0;i<n;i++){
        c+=pPretstava[i]->cena()*pPretstava[i]->getN();
    }
    return c;
}
int brojPretstaviNaDelo(Pretstava **pPretstava, int n, Delo delo) {
    int count = 0;
    for (int i = 0; i < n; i++){
            if (pPretstava[i]->getDela()==delo) {
                count++;
            }
        }
    return count;
}

//citanje na delo
Delo readDelo(){
    char ime[50];
    int godina;
    char zemja[50];
    cin>>ime>>godina>>zemja;
    return Delo(ime,godina,zemja);
}
//citanje na pretstava
Pretstava* readPretstava(){
    int tip; //0 za Balet , 1 za Opera
    cin>>tip;
    Delo d=readDelo();
    int brojProdadeni;
    char data[15];
    cin>>brojProdadeni>>data;
    if (tip==0)  return new Balet(d,brojProdadeni,data);
    else return new Opera(d,brojProdadeni,data);
}
int main(){
    int test_case;
    cin>>test_case;

    switch(test_case){
    case 1:
    //Testiranje na klasite Opera i Balet
    {
        cout<<"======TEST CASE 1======="<<endl;
        Pretstava* p1=readPretstava();
        cout<<p1->getDela().getIme()<<endl;
        Pretstava* p2=readPretstava();
        cout<<p2->getDela().getIme()<<endl;
    }break;

    case 2:
    //Testiranje na  klasite Opera i Balet so cena
    {
        cout<<"======TEST CASE 2======="<<endl;
        Pretstava* p1=readPretstava();
        cout<<p1->cena()<<endl;
        Pretstava* p2=readPretstava();
        cout<<p2->cena()<<endl;
    }break;

    case 3:
    //Testiranje na operator ==
    {
        cout<<"======TEST CASE 3======="<<endl;
        Delo f1=readDelo();
        Delo f2=readDelo();
        Delo f3=readDelo();

        if (f1==f2) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;
        if (f1==f3) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;

    }break;

    case 4:
    //testiranje na funkcijata prihod
    {
        cout<<"======TEST CASE 4======="<<endl;
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();

        }
        cout<<prihod(pole,n);
    }break;

    case 5:
    //testiranje na prihod so izmena na cena za 3d proekcii
    {
        cout<<"======TEST CASE 5======="<<endl;
        int cenaBalet;
        cin>>cenaBalet;
        Balet::setCenaBalet(cenaBalet);
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        }
        cout<<prihod(pole,n);
        }break;

    case 6:
    //testiranje na brojPretstaviNaDelo
    {
        cout<<"======TEST CASE 6======="<<endl;
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        }

        Delo f=readDelo();
        cout<<brojPretstaviNaDelo(pole,n,f);
    }break;

    };


return 0;
}

