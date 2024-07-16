/*Да се дефинира класа Пица за која ќе се чуваат податоци за:
име на пицата (низа од 15 знаци), цена (цел број), состојки (динамички алоцирана низа од знаци)
намалување на цената во проценти (цел број) - ако пицата не е на промоција намалувањето има вредност нула, во спротивно, вредност поголема од нула и не поголема од 100.
За потребите на оваа класа да се креираат потребните конструктори и да се напише соодветен деструктор. Дополнително за оваа класа да се дефинира функцијата:
-pecati() - функција во која ќе се печатат податоците за пицата во следниот формат: име - состојки, цена.
-istiSe(Pica p) - функција за споредба на две пици според состојките.
Да се дефинира класа Picerija во која се чуваат:
име (низа од максимум 15 знаци), динмички алоцирана низа од објекти од класата Pica, број на пици (цел број).
За потребите на оваа класа да се дефинираат потребните конструктори и да се напише соодветен деструктор. Да се имплементираат и следниве методи:
- dodadi(Pica P) - за додавање нова пица во пицеријата, но само ако не постои иста во низата (нема пица со исти состојки со пицата што треба да се додаде).
- void piciNaPromocija() - се печатат сите пици од пицеријата што се на промоција во формат : име - состојки, цена, цена со попуст.*/

#include <iostream>
#include <cstring>
using namespace std;

class Pica{
    char ime[15];
    int cena;
    char *sostojki;
    int procent;
public:
    Pica(char *ime="", int cena=0, char *sostojki="", int procent=0){
        strcpy(this->ime,ime);
        this->cena=cena;
        this->sostojki=new char[strlen(sostojki)+1];
        strcpy(this->sostojki,sostojki);
        this->procent=procent;
    }
    ~Pica(){delete [] sostojki;}
    Pica(const Pica &dr){
        strcpy(this->ime,dr.ime);
        this->cena=dr.cena;
        this->sostojki=new char[strlen(dr.sostojki)+1];
        strcpy(this->sostojki,dr.sostojki);
        this->procent=dr.procent;
    }
    Pica &operator=(const Pica &dr){
        if(this!=&dr){
            strcpy(this->ime,dr.ime);
            this->cena=dr.cena;
            delete [] sostojki;
            this->sostojki=new char[strlen(dr.sostojki)+1];
            strcpy(this->sostojki,dr.sostojki);
            this->procent=dr.procent;
        }
        return *this;
    }
    void pecati(){
        cout<<ime<<" - "<<sostojki<<", "<<cena;
    }
    bool istiSe(Pica p){
        return(strcmp(sostojki,p.sostojki)==0);
    }
    int getNamaluvanje(){
        return procent;
    }
    int getCena(){
        return cena;
    }
};
class Picerija{
    char ime[15];
    Pica *pici;
    int n;
public:
    Picerija(char *ime="",Pica *pici=0,int n=0){
        strcpy(this->ime,ime);
        this->n=n;
        this->pici=new Pica[n];
        for(int i=0;i<n;i++){
            this->pici[i]=pici[i];
        }
    }
    ~Picerija(){delete [] pici;}
    Picerija(const Picerija &dr){
        strcpy(ime,dr.ime);
        pici=new Pica[dr.n];
        n=dr.n;
        for(int i=0;i<n;i++){
            this->pici[i]=dr.pici[i];
        }
    }
    Picerija &operator=(const Picerija &dr){
        if(this!=&dr){
            delete [] pici;
            strcpy(ime,dr.ime);
            n=dr.n;
            pici=new Pica[dr.n];
            for(int i=0;i<n;i++){
                this->pici[i]=dr.pici[i];
            }
        }
        return *this;
    }
    void dodadi(Pica p){
        Pica *temp=new Pica[n+1];
        int flag=0;
        for(int i=0;i<n;i++){
            if(p.istiSe(pici[i])){
                flag=1;
            }
        }
        if(!flag){
            for(int i=0;i<n;i++){
                temp[i]=pici[i];
            }
            temp[n++]=p;
            delete []pici;
            pici=temp;
        }

    }
    void piciNaPromocija(){
        for(int i=0;i<n;i++){
            if(pici[i].getNamaluvanje()!=0){
                float nova=pici[i].getCena()-(float(pici[i].getNamaluvanje())/100*pici[i].getCena());
                pici[i].pecati();
                cout<<" "<<nova<<endl;
            }
        }
    }
    char *getIme(){
        return ime;
    }
    void *setIme(char *i){
        strcpy(ime,i);
    }
};
int main() {

    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    Picerija p1(ime);
    for (int i = 0; i < n; i++){
        char imp[100];
        cin.get();
        cin.getline(imp, 100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki, 100);
        int popust;
        cin >> popust;
        Pica p(imp, cena, sostojki, popust);
        p1.dodadi(p);
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp, 100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki, 100);
    int popust;
    cin >> popust;
    Pica p(imp, cena, sostojki, popust);
    p2.dodadi(p);

    cout << p1.getIme() << endl;
    cout << "Pici na promocija:" << endl;
    p1.piciNaPromocija();

    cout << p2.getIme() << endl;
    cout << "Pici na promocija:" << endl;
    p2.piciNaPromocija();

    return 0;
}
