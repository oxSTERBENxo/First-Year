/*Дадена е дел од дефиницијата на класата Karticka. За секоја картичка се чуваат информации за:
трансакциска сметка (низа од 15 знаци) , пин код (цел број) и дали има повеќе пин кодови (булова променлива).
За секој картичка може да се пресмета тежината за пробивање на картичката. Тежината на пробивање е бројот на цифрите на пин кодот.
- Специјалните картички покрај еден задолжителен имаат уште неколку пин кодови . За овие корисници да се моделира соодветна класа SpecijalnaKaricka во која покрај
дополнителните пин кодови (динамичко алоцирана низа од цели броеви) се чува и бројот на пин кодовите (цел број). Со дополнителните пин кодови се менува и тежината
на пробивање на картичката и таа се зголемува за бројот на дополнителни пин кодови.
- Максималниот број на дополнителни пин кодови кој може да има било која картичка е P. P има фиксна вредност 4 за сите картички и оваа вредност не може да се промени.
Во класите Karticka и SpecijalnaKarticka треба да се имплементираат потребните конструктори, функции за поставување и преземање и деструктор.
За сите објекти од класите треба да се обезбедат следните функции:
- преоптоварен оператор << во кој се печатат информации за картичката во формат:    smetka: tezina 
- tezinaProbivanje() – ја пресметува тежината за пробивање на картичката
Во класата SpecijalnaKarticka дефинирај ја функцијата:
- преоптоварен оператор += за додавање на нов пин код
Ако се направи обид да се внесат повеќе од дозволениот број на пин кодови во безбедносниот код да се фрли исклучок (објект од класата OutOfBoundException). Фатете го 
исклучокот во главната функција каде што е потребно. Откако ќе го фатите отпечатете соодветна порака за грешка (Brojot na pin kodovi ne moze da go nadmine dozvolenoto) и 
справете се со исклучокот така да додадениот пин код не се зема предвид

Дадена е дел од дефиницијата на класата Banka во која се чуваат информаци за:
- името на банката (низа од 30 знаци) и за картичките издадени од банката (низа од 20 покажувачи кон класата Karticka) како и бројот на такви картички.
Велиме дека картичката издадена од банката може да се пробие ако тежината за пробивање е најмногуLIMIT. Вредноста LIMIT е членка на класата Banka, има почетна вредност 7
и истата може да се промени со функцијата setLimit(). За сите банки оваа вредност е иста.
Во класата Banka имплементирај ги функциите:
- функција pecatiKarticki() во која се печатат сите картички кои можат да се пробијат, секој во посебен ред. Претходно во првиот ред се печати: 
Vo bankata XXXXX moze da se probijat kartickite: 
- функција dodadiDopolnitelenPin(char * smetka, int novPin) во која на картичката со дадена трансакциона сметка се додава нов дополнителен пин код. Ако тоа не е можно
функцијата не прави ништо*/

#include<iostream>
#include<cstring>
using namespace std;

class OutOfBoundException{
public:
    void message(){
        cout<<"Brojot na pin kodovi ne moze da go nadmine dozvolenoto"<<endl;
    }
};

class Karticka{
protected:
    char smetka[16];
    int pin;
    bool povekjePin;
public:
    Karticka(char* smetka,int pin){
        strcpy(this->smetka,smetka);
        this->pin=pin;
        this->povekjePin=false;
    }
    Karticka(){
        povekjePin=false;
    }
    // дополниете ја класата
    virtual ~Karticka(){}
    virtual int tezinaProbivanje(){
        int tmp=pin,counter=0;
        while(tmp){
            tmp/=10;
            counter++;
        }
        return counter;
    }
    friend ostream &operator<<(ostream& os, Karticka &dr);
    char *getSmetka(){
        return smetka;
    }
    virtual bool getDopolnitelenPin(){
        return povekjePin;
    }
};
class SpecijalnaKarticka:public Karticka{
    int *dopolnitelniPinovi;
    int n;
    static int const P;
public:
    SpecijalnaKarticka(): Karticka(){
        dopolnitelniPinovi=0;
        n=0;
        povekjePin=true;
    }
    SpecijalnaKarticka(char* smetka,int pin):Karticka(smetka,pin){
        dopolnitelniPinovi=0;
        n=0;
        povekjePin=true;
    }
    ~SpecijalnaKarticka(){delete [] dopolnitelniPinovi;}
    SpecijalnaKarticka(const SpecijalnaKarticka &dr):Karticka(dr){
        n=dr.n;
        povekjePin=dr.povekjePin;
        dopolnitelniPinovi=new int[n];
        for(int i=0;i<n;i++){
            dopolnitelniPinovi[i]=dr.dopolnitelniPinovi[i];
        }
    }
    SpecijalnaKarticka &operator=(SpecijalnaKarticka &dr){
        if(this!=&dr){
            delete [] dopolnitelniPinovi;
            n=dr.n;
            povekjePin=dr.povekjePin;
            dopolnitelniPinovi=new int[n];
            for(int i=0;i<n;i++){
                dopolnitelniPinovi[i]=dr.dopolnitelniPinovi[i];
            }
            strcpy(this->smetka,dr.smetka);
            this->pin=dr.pin;
        }
        return *this;
    }
    int tezinaProbivanje(){
        return Karticka::tezinaProbivanje()+n;
    }
    SpecijalnaKarticka &operator+=(int novPin){
        if(n>=P) throw OutOfBoundException();
        int *tmp = new int[n+1];
        for(int i=0;i<n;i++){
            tmp[i]=dopolnitelniPinovi[i];
        }
        tmp[n++]=novPin;
        delete [] dopolnitelniPinovi;
        dopolnitelniPinovi=tmp;
        return *this;
    }
    bool getDopolnitelenPin(){
        return povekjePin;
    }
    friend ostream &operator<<(ostream &os, SpecijalnaKarticka &dr){
        os<<dr.smetka<<": "<<dr.tezinaProbivanje()<<endl;
        return os;
    }
};

const int SpecijalnaKarticka::P=4;

class Banka {
private:
    char naziv[30];
    Karticka *karticki[20];
    int broj;
    static int LIMIT;
public:
    Banka(char *naziv, Karticka** karticki,int broj ){
        strcpy(this->naziv,naziv);
        for (int i=0;i<broj;i++){
            //ako kartickata ima dopolnitelni pin kodovi
            if (karticki[i]->getDopolnitelenPin()){
                this->karticki[i]=new SpecijalnaKarticka(*dynamic_cast<SpecijalnaKarticka*>(karticki[i]));
            }
            else this->karticki[i]=new Karticka(*karticki[i]);
        }
        this->broj=broj;
    }
    ~Banka(){
        for (int i=0;i<broj;i++) delete karticki[i];
    }
    static void setLIMIT(int s){
        LIMIT=s;
    }
    void pecatiKarticki(){
        cout<<"Vo bankata "<<naziv<<" moze da se probijat kartickite:"<<endl;
        for(int i=0;i<broj;i++){
            if(karticki[i]->tezinaProbivanje()<=LIMIT){
                cout<<*karticki[i];
            }
        }
    }
    void dodadiDopolnitelenPin(char* smetka, int novPin){
        for(int i=0;i<broj;i++){
            if(strcmp(smetka,karticki[i]->getSmetka())==0 && karticki[i]->getDopolnitelenPin()){
                SpecijalnaKarticka *tmp=dynamic_cast<SpecijalnaKarticka *>(karticki[i]);
                *tmp+=novPin;
                karticki[i]=tmp;
            }
        }
    }
};

ostream &operator<<(ostream &os, Karticka &dr){
    SpecijalnaKarticka *tmp = dynamic_cast<SpecijalnaKarticka *>(&dr);
    if(tmp){
        os<<*tmp;
    } else {
        os<<dr.getSmetka()<<": "<<dr.tezinaProbivanje()<<endl;
    }
    return os;
}

int Banka::LIMIT=7;

int main(){

    Karticka **niza;
    int n,m,pin;
    char smetka[16];
    bool daliDopolnitelniPin;
    cin>>n;
    niza=new Karticka*[n];
    for (int i=0;i<n;i++){
        cin>>smetka;
        cin>>pin;
        cin>>daliDopolnitelniPin;
        if (!daliDopolnitelniPin)
            niza[i]=new Karticka(smetka,pin);
        else
            niza[i]=new SpecijalnaKarticka(smetka,pin);
    }

    Banka komercijalna("Komercijalna",niza,n);
    for (int i=0;i<n;i++) delete niza[i];
    delete [] niza;
    cin>>m;
    for (int i=0;i<m;i++){
        cin>>smetka>>pin;
        try{
            komercijalna.dodadiDopolnitelenPin(smetka,pin);
        }
        catch(OutOfBoundException e){
            e.message();
        }

    }

    Banka::setLIMIT(5);

    komercijalna.pecatiKarticki();

}
