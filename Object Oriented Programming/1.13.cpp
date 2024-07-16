/*Да се креира класата Zichara во која ќе се чуваат информации за:
место (динамичко алоцирано поле од знаци), цена на дневна карта (цел број)
Да се креира класа PlaninarskiDom во која се чуваат информации за:
- име (статичко поле од најмногу 15 знаци), 
- цени по сезони (поле од 2 цели броеви кои ја претставуваат цената за спиење за еден ден во планинарскиот дом во двете различни сезони.Секој планинарски дом 
има две сезони: летна и зимска.Летната сезона почнува на 1ви април и завршува до 1ви сепмтември. На пример цената за престој на 24ти Јули ќе биде сместена во
полето со индекс 0 - каде е сместена цената за летната сезона)
- класа на планинарскиот дом (еден знак кој може да има вредност од A до F, каде A е најдобра класа)
- дали има жичара (bool-тип)
- жичарата на планинарскиот дом (покажувач кон објект од класата Zichara)
За дадените класи дефинирајте ги потребните: конструктори, деструктори, set и get методи. Оптоварете го соодветно операторот =.
Да се оптоварат:
- операторот -- (префискен) за намалување на класата на планинарскиот дом (во класата PlaninarskiDom). Да се запази дека за планинарскиот дом најмала класа е F.
- операторот << за печатење на објект одPlaninarskiDom.
- операторот <= за одредување дали планинарскиот дом има класа помала или еднаква со дадениот знак (споредба на планинарски дом со знак).
Формат на печатење на информации за еден планинарски дом:
   Pelister klasa:A so zichara //ако има жичара
   Korab klasa:B //ако нема жичара
Во класата PlaninarskiDom да се имплементира функција со име presmetajDnevenPrestoj со која се пресметува цената за дневен престој во планинарскиот дом за даден ден
и месец во годината. Ако планинарскиот дом има жичара во цената за дневен престој влегува и дневната карта за жичарата. Функцијата враќа void (не враќа ништо). 
Првиот аргумент на функцијата е денот (1-31), а вториот е месецот (1-12) за кои се пресметува цената. Третиот аргумент е цената за дневен престој која ќе се пресмета
во функцијата. Доколку денот или месецот се невалидни да се фрли соодветен исклучок со кој се справуваме во main-функцијата. Да се земе дека секој месец има 31 ден.
Дадена е main-функција во која се користат класите Zichara и PlaninarskiDom. Без таа да се менува креирајте ги опишаните класи.*/

#include<iostream>
#include<string.h>
using namespace std;

struct cena{
    int letna;
    int zimska;
};

class Zichara{
private:
    char *mesto;
    int cena;
public:
    Zichara(char *mesto="", int cena=0){
        this->mesto = new char[strlen(mesto) + 1];
        strcpy(this->mesto, mesto);
        this->cena = cena;
    }
    Zichara(const Zichara &dr){
        this->mesto = new char[strlen(dr.mesto) + 1];
        strcpy(this->mesto, dr.mesto);
        this->cena = dr.cena;
    }
    ~Zichara(){delete [] mesto;}
    Zichara &operator=(const Zichara &dr){
        if(this != &dr){
            delete [] mesto;
            mesto = new char[strlen(dr.mesto) + 1];
            strcpy(mesto, dr.mesto);
            cena = dr.cena;
        }
        return *this;
    }
    int getCena()const{
        return cena;
    }
};
class PlaninarskiDom {
    char ime[15];
    cena ceni;
    char klasa;
    bool ima;
    Zichara *zicara;
public:
    PlaninarskiDom(const char *ime = "", const int *ceni=nullptr, char klasa = 'A') {
        strcpy(this->ime, ime);
        if(ceni != nullptr) {
            this->ceni.letna = ceni[0];
            this->ceni.zimska = ceni[1];
        }
        this->klasa = klasa;
        this->ima = false;
        this->zicara = new Zichara[0];
    }
    PlaninarskiDom(const PlaninarskiDom &dr){
        strcpy(ime, dr.ime);
        ceni.letna = dr.ceni.letna;
        ceni.zimska = dr.ceni.zimska;
        klasa = dr.klasa;
        ima = dr.ima;
        if (dr.ima) {
            zicara = new Zichara(*(dr.zicara));
        } else {
            zicara = nullptr;
        }
    }
    ~PlaninarskiDom(){delete zicara;}
    PlaninarskiDom &operator=(const PlaninarskiDom &dr){
        if(this!=&dr) {
            delete[]zicara; 
            strcpy(ime,dr.ime);
            ceni.letna = dr.ceni.letna;
            ceni.zimska = dr.ceni.zimska;
            klasa = dr.klasa;
            ima = dr.ima;
            if (ima) {
                zicara = new Zichara(*(dr.zicara));
            } else {
                zicara = nullptr;
            }
        }
        return *this;
    }

    void setZichara(const Zichara &dr){
        ima = true;
        zicara = new Zichara(dr);
    }

    PlaninarskiDom operator--(){
        if(klasa != 'F')
            klasa = klasa + 1;
        return *this;
    }

    friend ostream& operator<<(ostream &os, const PlaninarskiDom &dr){
        if(dr.ima)
            os << dr.ime << " klasa:" << dr.klasa << " so Zichara" << endl;
        else
            os << dr.ime << " klasa:" << dr.klasa << endl;
        return os;
    }

    bool operator<=(const char znak){
        if(this->klasa >= znak)
            return 1;
        return 0;
    }

    void presmetajDnevenPrestoj(int den, int mesec, int &cena){
        if(mesec > 12 || mesec < 1 || den < 1 || den > 31)
            throw 1;
        if(mesec > 3 && mesec < 9){
            cena = ceni.letna;
            if(this->ima)
                cena += this->zicara->getCena();
        }
        else
        {
            cena = ceni.zimska;
            if(this->ima)
                cena += this->zicara->getCena();
        }
    }
};


int main(){

    PlaninarskiDom p;
    //во следниот дел се вчитуваат информации за планинарскиот дом
    char imePlaninarskiDom[15],mestoZichara[30],klasa;
    int ceni[12];
    int dnevnakartaZichara;
    bool daliZichara;
    cin>>imePlaninarskiDom;
    for (int i=0;i<2;i++) cin>>ceni[i];
    cin>>klasa;
    cin>>daliZichara;

    //во следниот дел се внесуваат информации и за жичарата ако постои
    if (daliZichara) {
        cin>>mestoZichara>>dnevnakartaZichara;
        PlaninarskiDom pom(imePlaninarskiDom,ceni,klasa);
        Zichara r(mestoZichara,dnevnakartaZichara);
        pom.setZichara(r);
        p=pom;
    }
    else{
        PlaninarskiDom *pok=new PlaninarskiDom(imePlaninarskiDom,ceni,klasa);
        p=*pok;
    }

    //се намалува класата на планинарскиот дом за 2
    --p;
    --p;

    int cena;
    int den,mesec;
    cin>>den>>mesec;
    try{
        p.presmetajDnevenPrestoj(den,mesec,cena); //тука се користи функцијата presmetajDnevenPrestoj
        cout<<"Informacii za PlaninarskiDomot:"<<endl;
        cout<<p;
        if (p<='D')
            cout<<"Planinarskiot dom za koj se vneseni informaciite ima klasa poniska ili ista so D\n";

        cout<<"Cenata za "<<den<<"."<<mesec<<" e "<<cena; //се печати цената за дадениот ден и месец
    }
    catch (int){
        cout<<"Mesecot ili denot e greshno vnesen!";
    }
}
