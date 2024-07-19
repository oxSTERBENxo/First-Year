Да се креира класа Patnik во која се чуваат податоци за патниците на еден воз и тоа: име (низа од максимум 100 знаци),
класа на вагон во која се вози (цел број 1 или 2) и велосипед (булова променлива).
За оваа класа да се преоптоварат:
Оператор << - за печатење на информациите за патникот во формат:
Име на патник
Бројот на класата (1 или 2)
Дали има велосипед?
Потоа да се креира клaса Voz во која се чува:
крајна дестинација (низа од максимум 100 знаци), динамички алоцирана низа од објекти од класата Patnik, како и број на елементи во низата (цел број),
број на дозволени велосипеди (цел број).
За класата да се обезбедат:
Оператор += – за додавање нов патник во воз. Патник со велосипед ќе може да се качи во воз само ако возот го дозволува тоа.
Оператор << - за печатење на крајната дестинација до која вози и листата на патници
Функција со потпис: patniciNemaMesto(). Со оваа функција се пресметува вкупниот број на патници (од 1-ва класа и 2-ра класа) за кои нема место да влезат во возот со велосипед.
Притоа треба да се внимава дека во пресметувањето на вкупниот број патници со велосипеди кои ќе влезат во возот прво треба да се земат предвид патниците од 1-ва класа,
а потоа се дозволува да влегуваат патниците од 2-ра класа се додека не се достигне максималниот број на дозволени велосипеди во возот. 
На крај се печати бројот на патници со велосипеди кои остануваат (не влегуваат во возот) од 1-ва класа, а потоа од 2-ра класа.

#include<iostream>
#include<cstring>
using namespace std;
class Patnik{
private:
    char ime[100];
    int klasa;
    bool velosiped;
public:
    Patnik(char *ime="", int klasa=0, bool velosiped=0){
        strcpy(this->ime,ime);
        this->klasa=klasa;
        this->velosiped=velosiped;
    }
    Patnik(const Patnik &dr){
        strcpy(this->ime,dr.ime);
        this->klasa=dr.klasa;
        this->velosiped=dr.velosiped;
    }
    friend ostream &operator<<(ostream &out,Patnik &dr){
        out<<dr.ime<<endl;
        out<<dr.klasa<<endl;
        out<<dr.velosiped<<endl;
        out<<endl;
        return out;
    }

    char *getIme(){
        return ime;
    }

    int getKlasa(){
        return klasa;
    }

    bool getVelosiped(){
        return velosiped;
    }
};
class Voz{
private:
    char destinacija[100];
    Patnik *patnici;
    int n;
    int capacity;
public:
    Voz(char *destinacija, int capacity){
        n=0;
        patnici= nullptr;
        this->capacity=capacity;
        strcpy(this->destinacija,destinacija);
    }
    ~Voz(){delete [] patnici;}
    Voz(const Voz &dr){
        this->n=dr.n;
        this->capacity=dr.capacity;
        strcpy(this->destinacija,dr.destinacija);
        this->capacity=dr.capacity;
        this->patnici =new Patnik[dr.n];
        for (int i = 0; i < n; i++) {
            this->patnici[i]=dr.patnici[i];
        }
    }
    Voz &operator=(const Voz &dr){
        if(this!=&dr){
            delete [] patnici;
            this->n=dr.n;
            this->capacity=dr.capacity;
            strcpy(this->destinacija,dr.destinacija);
            this->capacity=dr.capacity;
            this->patnici =new Patnik[dr.n];
            for (int i = 0; i < n; i++) {
                this->patnici[i]=dr.patnici[i];
            }
        }
        return *this;
    }
    Voz &operator+=(Patnik &dr){
        if(dr.getVelosiped() && capacity==0){
            return *this;
        }
        Patnik *temp = new Patnik[n+1];
        for(int i=0;i<n;i++){
            temp[i]=patnici[i];
        }
        temp[n++]=dr;
        delete [] patnici;
        patnici=temp;
        return *this;
    }
    friend ostream &operator<<(ostream &out, Voz &dr){
        out<<dr.destinacija<<endl;
        for(int i=0;i<dr.n;i++){
            out<<dr.patnici[i];
        }
        return out;
    }
    void patniciNemaMesto(){
        int prva=0, vtora=0;
        for(int i=0;i<n;i++){
            if(patnici[i].getVelosiped()){
            if(patnici[i].getKlasa()==1){
                prva++;
            }else{
                vtora++;
            }
        }
        }
        if(capacity-prva>=0){
            if(capacity-prva-vtora>=0){
                vtora=0;
            }else{
                vtora=abs(capacity-prva-vtora);
            }
            prva=0;
        }else{
            prva= abs(capacity-prva);
        }
        cout<<"Brojot na patnici od 1-va klasa koi ostanale bez mesto e: "<<prva<<endl;
        cout<<"Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: "<<vtora<<endl;
    }
};
int main()
{
    Patnik p;
    char ime[100], destinacija[100];
    int n;
    bool velosiped;
    int klasa;
    int maxv;
    cin >> destinacija >> maxv;
    cin >> n;
    Voz v(destinacija, maxv);
    //cout<<v<<endl;
    for (int i = 0; i < n; i++){
        cin >> ime >> klasa >> velosiped;
        Patnik p(ime, klasa, velosiped);
        //cout<<p<<endl;
        v += p;
    }
    cout << v;
    v.patniciNemaMesto();

    return 0;
}
