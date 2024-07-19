/* Да се дефинира класата Pesna во која се чуваат информации за:
име на песна (динамички алоцирано поле од знаци), времетраење на песната во минути, тип на песна кој може да биде: поп, рап или рок (енумерација tip).
Да се обезбедат сите потребни методи за класата за правилно функционирање на програмата. Дополнително за оваа класа да се дефинира методот:
- pecati() - функција во која ќе се печатат одделени со цртичка(-): името на песната во наводници и времетраењето на песната со постфикс min. (пр: "Happy"-5min )
Да се креира класата CD во која се чуваат информации за:
низа од песни снимени на CD-то (Поле од најмногу 10 објекти од класата Pesna ), број на песни снимени на CD-то, максимално времетраење на песните на CD-то (во минути)
Да се обезбедат сите потребни методи за класата за правилно функционирање на програмата. Дополнително за оваа класа да се дефинираат методите:
- dodadiPesna (Pesna p) - со кој се додава песната p на CDто, но само ако има доволно преостанато место (земајќи го предвид максималното времетраење на песните на CDто и времетраењата на песните на CD-то) и ако има помалку од 10 песни на CD-то.
- pecatiPesniPoTip(tip t) – со кој се печатат информациите за сите песни од тип t (поп, рап или рок).*/

#include <iostream>
#include <cstring>
using namespace std;
enum tip{
    pop,rap,rok
};
class Pesna{
private:
    char *name;
    int min;
    tip t;
public:
    Pesna(){
        name= nullptr;
        min=0;
        t=pop;
    }
    Pesna(char *name, int min, tip t){
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        this->min=min;
        this->t=t;
    }
    Pesna(const Pesna &dr){
        this->name=new char[strlen(dr.name)+1];
        strcpy(this->name,dr.name);
        this->min=dr.min;
        this->t=dr.t;
    }
    Pesna &operator=(const Pesna &dr){
        if(this!=&dr){
            delete [] name;
            this->name=new char[strlen(dr.name)+1];
            strcpy(this->name,dr.name);
            this->min=dr.min;
            this->t=dr.t;
        }
        return *this;
    }
    void pecati(){
        cout<<"\""<<name<<"\""<<"-"<<min<<"min"<<endl;
    }
    ~Pesna(){delete [] name;}

    int getMin(){
        return min;
    }
    tip getT(){
        return t;
    }
};
class CD{
private:
    Pesna pesni[10];
    int n;
    int vreme;
public:
    CD(int vreme){
        this->vreme=vreme;
        n=0;
    }
    CD(const CD &dr){
        this->n=dr.n;
        this->vreme=dr.vreme;
        for(int i=0;i<n;i++){
            this->pesni[i]=dr.pesni[i];// ne e dinamicko alocirana
        }
    }
    void dodadiPesna(Pesna dr){
        int potroseno=0;
        for(int i=0;i<n;i++){
            potroseno+=pesni[i].getMin();
        }
        if(potroseno+dr.getMin()<=vreme && n<10){
            pesni[n++]=dr;
        }
    }
    void pecatiPesniPoTip(tip t){
        for(int i=0;i<n;i++){
            if(pesni[i].getT()==t){
                pesni[i].pecati();
            }
        }
    }

    Pesna getPesna(int i){
        return pesni[i];
    }

    int getBroj(){
        return n;
    }
};

int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, minuti, kojtip;
    char ime[50];

    if(testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime,minuti,(tip)kojtip);
        p.pecati();
    } else if(testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i=0; i<n; i++)
            (omileno.getPesna(i)).pecati();
    }
    else if(testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i=0; i<omileno.getBroj(); i++)
            (omileno.getPesna(i)).pecati();
    }
    else if(testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }
    else if(testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }

    return 0;
}
