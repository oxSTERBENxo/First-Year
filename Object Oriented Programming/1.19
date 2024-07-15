/*Да се дефинира класа IceCream во која се чуваат податоци за:
- име (динамичка низа од знаци), состав (низа од знаци, најмногу 100), цена (децимален број), попуст (цел број, изразен во проценти) иницијална вредност 0.
За потребите на класата да се имплементираат:
- соодветни конструктори и деструктор (да се погледнат повиците во функцијата main)
- оператор << за печатење на податоците за сладоледот во следниов формат:   име: состав цена [цена на попуст]
делот „цена на попуст“ се печати само ако за сладоледот се нуди попуст (вредноста на попустот е поголема од нула)
- оператор ++ во префикс нотација за зголемување на попустот за 5
- оператор + за собирање на објект од класата IceCream со низа од знаци. Собирањето се реализира на начин што името на новиот сладолед се добива со спојување 
на името на сладоледот и низата од знаци одделени со „ + “. Цената на новиот сладолед се зголемува за 10, а попустот и составот на сладоледот остануваат исти.
- метод void setDiscount(int discount) со кој може да се смени вредноста на попустот. Дозволените вредности на попустот се во интервалот [0,100]
- метод void setName(char* name) со кој се менува името на сладоледот.
Да се креира класа IceCreamShop во која се чува:
- име на продавницата (низа од знаци, најмногу 50), динамички резервирано поле од објекти од класата IceCream, број на сладоледи во полето (цел број).
За оваа класа да се обезбедат:
- соодветни конструктори и деструктор (погледнете ги повиците во main функцијата)
- оператор += за додавање нов објект од класата IceCream во полето
- оператор << за печатење на листа од сите сладоледи во продавницата. Прво се печати името на продавницата, а потоа се печатат податоците за сите сладоледи одделени со нов ред.
*/

#include <iostream>
#include <cstring>
using namespace std;
class IceCream{
private:
    char *ime;
    char sostav[100];
    float cena;
    int popust;
public:
    IceCream(){
        ime=0;
        popust=0;
    }
    IceCream(char *ime, char *sostav, float cena, int popust=0){
        this->ime=new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        strcpy(this->sostav,sostav);
        this->cena=cena;
        this->popust=popust;
    }
    IceCream(const IceCream &dr){
        this->ime=new char[strlen(dr.ime)+1];
        strcpy(this->ime,dr.ime);
        strcpy(this->sostav,dr.sostav);
        this->cena=dr.cena;
        this->popust=dr.popust;
    }
    IceCream &operator=(const IceCream &dr){
        if(this!=&dr){
            delete [] ime;
            this->ime=new char[strlen(dr.ime)+1];
            strcpy(this->ime,dr.ime);
            strcpy(this->sostav,dr.sostav);
            this->cena=dr.cena;
            this->popust=dr.popust;
        }
        return *this;
    }
    ~IceCream(){delete [] ime;}
    friend ostream &operator<<(ostream &out, IceCream &dr){
        out<<dr.ime<<": "<<dr.sostav<<" "<<dr.cena;
        if(dr.popust>0){
            double pop=dr.cena-(dr.cena*dr.popust/100);
            out<<" ("<<pop<<")";
        }
        return out;
    }
    IceCream &operator++(){
        popust+=5;
        return *this;
    }
    IceCream operator+(const char *dr){
        char *temp = new char[strlen(ime)+1];
        strcpy(temp,ime);
        delete [] ime;
        ime = new char [strlen(temp)+2+ strlen(dr)+1];
        strcpy(ime,temp);
        strcat(ime," + ");
        strcat(ime,dr);
        return IceCream(ime,sostav,cena+10,popust);
    }
    void setName(char *name){
        ime=new char[strlen(name)+1];
        strcpy(ime,name);
    }
    void setDiscount(int d){
        if(d>=0 && d<=100){
            popust=d;
        }
    }
};
class IceCreamShop{
private:
    char ime[50];
    IceCream *sladoledi;
    int n;
public:
    IceCreamShop(){
        sladoledi= nullptr;
        n=0;
    }
    IceCreamShop(char *ime){
        strcpy(this->ime,ime);
        sladoledi=0;
        n=0;
    }
    ~IceCreamShop(){delete [] sladoledi;}
    IceCreamShop(const IceCreamShop &dr){
        strcpy(this->ime,dr.ime);
        n=dr.n;
        sladoledi = new IceCream[dr.n];
        for(int i=0;i<n;i++){
            sladoledi[i]=dr.sladoledi[i];
        }
    }
    IceCreamShop &operator=(const IceCreamShop &dr){
        if(this!=&dr){
            delete [] sladoledi;
            strcpy(this->ime,dr.ime);
            n=dr.n;
            sladoledi = new IceCream[dr.n];
            for(int i=0;i<n;i++){
                sladoledi[i]=dr.sladoledi[i];
            }
        }
        return *this;
    }
    IceCreamShop &operator+=(IceCream &dr){
        IceCream *temp = new IceCream[n+1];
        for(int i=0;i<n;i++){
            temp[i]=sladoledi[i];
        }
        temp[n++]=dr;
        delete [] sladoledi;
        sladoledi=temp;
        return *this;
    }
    friend ostream &operator<<(ostream& out, IceCreamShop &dr){
        out<<dr.ime<<endl;
        for(int i=0;i<dr.n;i++){
            out<<dr.sladoledi[i]<<endl;
        }
        return out;
    }
};

int main() {
    char name[100];
    char ingr[100];
    float price;
    int discount;

    int testCase;

    cin >> testCase;
    cin.get();
    if(testCase == 1) {
        cout << "====== TESTING IceCream CLASS ======" << endl;
        cin.getline(name,100);
        cin.getline(ingr,100);
        cin >> price;
        cin >> discount;
        cout << "CONSTRUCTOR" << endl;
        IceCream ic1(name, ingr, price);
        ic1.setDiscount(discount);
        cin.get();
        cin.getline(name,100);
        cin.getline(ingr,100);
        cin >> price;
        cin >> discount;
        IceCream ic2(name, ingr, price);
        ic2.setDiscount(discount);
        cout << "OPERATOR <<" << endl;
        cout << ic1 << endl;
        cout << ic2 << endl;
        cout << "OPERATOR ++" << endl;
        ++ic1;
        cout << ic1 << endl;
        cout << "OPERATOR +" << endl;
        IceCream ic3 = ic2 + "chocolate";
        cout << ic3 << endl;
    } else if(testCase == 2) {
        cout << "====== TESTING IceCream CONSTRUCTORS ======" << endl;
        cin.getline(name,100);
        cin.getline(ingr,100);
        cin >> price;
        //cin >> discount;
        cout << "CONSTRUCTOR" << endl;
        IceCream ic1(name, ingr, price);
        cout << ic1 << endl;
        cout << "COPY CONSTRUCTOR" << endl;
        IceCream ic2(ic1);
        cin.get();
        cin.getline(name,100);
        ic2.setName(name);
        cout << ic1 << endl;
        cout << ic2 << endl;
        cout << "OPERATOR =" << endl;
        ic1 = ic2;
        cin.getline(name,100);
        ic2.setName(name);
        cout << ic1 << endl;
        cout << ic2 << endl;

        cin >> discount;
        ic1.setDiscount(discount);


    } else if(testCase == 3) {
        cout << "====== TESTING IceCreamShop ======" << endl;
        char icsName[50];
        cin.getline(icsName,100);
        cout << "CONSTRUCTOR" << endl;
        IceCreamShop ics(icsName);
        int n;
        cin >> n;
        cout << "OPERATOR +=" << endl;
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,100);
            cin.getline(ingr,100);
            cin >> price;
            IceCream ic(name, ingr, price);
            ics += ic;
        }
        cout << ics;
    } else if(testCase == 4) {
        cout << "====== TESTING IceCreamShop CONSTRUCTORS ======" << endl;
        char icsName[50];
        cin.getline(icsName,100);
        IceCreamShop ics(icsName);
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,100);
            cin.getline(ingr,100);
            cin >> price;
            IceCream ic(name, ingr, price);
            ics += ic;
        }
        IceCream x("FINKI fruits", "strawberry ice cream, raspberry ice cream, blueberry ice cream", 60);
        IceCreamShop icp = ics;
        ics+=x;
        cout << ics << endl;
        cout << icp << endl;
    }


    return 0;
}
