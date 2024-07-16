/*Да се имплементира апстрактна класа FudblaskaEkipa во која се чува:
- име на тренерот на екипата (максимум 100 знаци)
- бројот на постигнати голови на последните 10 натпревари, последниот натпревар е на позиција 9, предпоследниот на позиција 8, итн (поле од 10 цели броеви)
Од класата FudblaskaEkipa да се изведат класите Klub и Reprezentacija. 
За секој клуб дополнително се чува податок за името и бројот на титули што ги има освоено, а за репрезентацијата се чуваат податоци за името на државата и вкупен
број на меѓународни настапи. За овие класи да се имплементираат следните методи:
- соодветен конструктор 
- оператор << за печатење на стандарден излез во формат [IME_NA_KLUB/DRZHAVA]\n[TRENER]\n[USPEH]\n 
- преоптоварен оператор+= за додавање на голови од последниот натпревар (внимавајте секогаш се чуваат головите само од последните 10 натпревари) (10 поени)
- метод uspeh, за пресметување на успехот на тимот на следниот начин:
  За Klub се пресметува како збир од збирот на головите од последните 10 натпревари помножен со 3 и бројот на титули помножен со 1000 
  (на пр. голови = {2, 0, 1, 3, 2, 0, 1, 4, 2, 3} и број на титули = 3, достигнување = 18 * 3 + 3 * 1000 = 3054)
  За Reprezentacija како збир од збирот на головите од последните 10 натпревари помножен со 3 и бројот на меѓународни настапи помножен со 50 
  (на пр. голови = {2, 0, 1, 3, 2, 0, 1, 4, 2, 3} и број на меѓународни настапи=150, достигнување = 18 * 3 + 150 * 50 = 7554)
- преоптоварен оператор > за споредба на две фудбласки екипи од каков било вид (клубови или репрезентации) според успехот (5 поени)
- Да се имплементира функција najdobarTrener што на влез прима низа од покажувачи кон FudblaskaEkipa и големина на низата и го печати тимот со најголем успех. */

#include <iostream>
#include <cstring>
using namespace std;

class FudbalskaEkipa{
protected:
    char trener[100];
    int golovi[10];
public:
    FudbalskaEkipa(char *trener="", int *golovi=0){
        strcpy(this->trener,trener);
        for(int i=0;i<10;i++){
            this->golovi[i]=golovi[i];
        }
    }
    virtual int uspeh()const=0;
    friend ostream &operator<<(ostream &os, const FudbalskaEkipa &ekipa);
    bool operator>(const FudbalskaEkipa &dr) const {
        return dr.uspeh() < uspeh();
    }
    FudbalskaEkipa &operator+=(int gol){
        for(int i=0;i<9;i++){
            golovi[i]=golovi[i+1];
        }
        golovi[9]=gol;
        return *this;
    }
    const char *getTrener() const {
        return trener;
    }
};

class Klub:public FudbalskaEkipa{
private:
    char klub[100];
    int tituli;
public:
    Klub(char *trener="", int *golovi=0, char *klub="", int tituli=0) : FudbalskaEkipa(trener, golovi){
        strcpy(this->klub,klub);
        this->tituli=tituli;
    }
    friend ostream &operator<<(ostream &os, const Klub &klub) {
        os <<klub.klub<<endl;
        return os;
    }

    int uspeh() const override {
        int usp=0;
        for(int i=0;i<10;i++){
            usp=usp+golovi[i];
        }
        usp=usp*3+tituli*1000;
        return usp;
    }
};
class Reprezentacija:public FudbalskaEkipa{
private:
    char drzava[100];
    int nastapi;
public:
    Reprezentacija(char *trener="", int *golovi=0, char *drzava="", int nastapi=0) : FudbalskaEkipa(trener, golovi){
        strcpy(this->drzava,drzava);
        this->nastapi=nastapi;
    }
    friend ostream &operator<<(ostream &os, const Reprezentacija &reprezentacija) {
        os << reprezentacija.drzava<<endl;
        return os;
    }

    int uspeh() const override {
        int usp=0;
        for(int i=0;i<10;i++){
            usp=usp+golovi[i];
        }
        usp=usp*3+nastapi*50;
        return usp;
    }
};
ostream &operator<<(ostream &os, FudbalskaEkipa &ekipa) {
    Klub *k=dynamic_cast<Klub*>(&ekipa);
    Reprezentacija *r=dynamic_cast<Reprezentacija*>(&ekipa);
    if(k){
        os<<*k;
    }else{
        os<<*r;
    }
    os<<ekipa.getTrener()<<endl;
    os<<ekipa.uspeh()<<endl;
    return os;
}
void najdobarTrener(FudbalskaEkipa **pEkipa, int n) {
    FudbalskaEkipa *naj=pEkipa[0];
    for(int i=0;i<n;i++){
        if(naj->uspeh()<pEkipa[i]->uspeh()){
            naj=pEkipa[i];
        }
    }
    cout<<*naj;
}
int main() {
    int n;
    cin >> n;
    FudbalskaEkipa **ekipi = new FudbalskaEkipa*[n];
    char coach[100];
    int goals[10];
    char x[100];
    int tg;
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        cin.getline(coach, 100);
        cin.getline(coach, 100);
        for (int j = 0; j < 10; ++j) {
            cin >> goals[j];
        }
        cin.getline(x, 100);
        cin.getline(x, 100);
        cin >> tg;
        if (type == 0) {
            ekipi[i] = new Klub(coach, goals, x, tg);
        } else if (type == 1) {
            ekipi[i] = new Reprezentacija(coach, goals, x, tg);
        }
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== DODADI GOLOVI =====" << endl;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        cout << "dodavam golovi: " << p << endl;
        *ekipi[i] += p;
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== NAJDOBAR TRENER =====" << endl;
    najdobarTrener(ekipi, n);
    for (int i = 0; i < n; ++i) {
        delete ekipi[i];
    }
    delete [] ekipi;
    return 0;
}

