/*Да се дефинира класа Ucesnik за учесник во маратон за кој ќе се чуваат информации за:
име (динамички алоцирана низа од знаци), пол (bool), возраст (цел број).
За потребите на оваа класа да се преоптоварат потребните конструктори и да се напише соодветен деструктор. (10 поени)
Дополнително за оваа класа да се преоптоварат:
- оператор за споредување > (споредува двајца учесници според возраста)
- операторот за проследување на излезен тек << кој ќе ги печати името, полот (машки/женски) и возраста, секој во посебен ред.
Да се дефинира класа Maraton за кој се чуваат:
локација (низа од максимум 100 знаци), низа од Ucesnik објекти (динмички алоцирана низа од објекти од класата Ucesnik), број на учесници (цел број).
За потребите на оваа класа да се преоптоварат потребните конструктори и да се напише соодветен деструктор. Исто така да се имплементираат следните методи:
- оператор += за додавање нов Ucesnik на маратонот Maraton.
- prosecnoVozrast() вреќа просечена возраст на учесниците на маратонот
- pecatiPomladi(Ucesnik &u) ги печати сите учесници помлади од учесникот проследен како аргумент на методот.*/

#include <iostream>
#include <cstring>
using namespace std;
class Ucesnik{
private:
    char *name;
    bool gender;
    int age;
public:
    Ucesnik() {
        name=0;
    }
    Ucesnik(char *name, bool gender=false, int age=0){
        this->name = new char [strlen(name)+1];
        strcpy(this->name,name);
        this->gender=gender;
        this->age=age;
    }
    ~Ucesnik(){delete [] name;}
    Ucesnik(const Ucesnik &dr){
        this->name = new char [strlen(dr.name)+1];
        strcpy(this->name,dr.name);
        this->gender=dr.gender;
        this->age=dr.age;
    }
    Ucesnik &operator=(const Ucesnik &dr){
     if(this!=&dr){
         delete [] name;
         this->name = new char [strlen(dr.name)+1];
         strcpy(this->name,dr.name);
         this->gender=dr.gender;
         this->age=dr.age;
     }
     return *this;
    }
    bool operator>(const Ucesnik &dr){
        return dr.age < age;
    }
    friend ostream &operator<<(ostream &out,Ucesnik &dr){
        out<<dr.name<<endl;
        if(dr.gender){
            out<<"mashki"<<endl;
        }else{
            out<<"zhenski"<<endl;
        }
        out<<dr.age;
        return out;
    }

    int getAge(){
        return age;
    }
};
class Maraton{
private:
    char location[100];
    Ucesnik *ucesnici;
    int n;
public:
     Maraton(char *location){
        strcpy(this->location,location);
        ucesnici= nullptr;
        n=0;
    }
    ~Maraton(){delete [] ucesnici;};
     Maraton(const Maraton &dr){
         strcpy(this->location,dr.location);
         this->n=dr.n;
         this->ucesnici= new Ucesnik[dr.n];
         for (int i = 0; i < n; ++i) {
             this->ucesnici[i]=dr.ucesnici[i];
         }
     }
     Maraton &operator=(const Maraton &dr){
         if(this!=&dr){
             delete [] ucesnici;
             strcpy(this->location,dr.location);
             this->n=dr.n;
             this->ucesnici= new Ucesnik[dr.n];
             for (int i = 0; i < n; ++i) {
                 this->ucesnici[i]=dr.ucesnici[i];
             }
         }
         return *this;
     }
     Maraton &operator+=(Ucesnik &dr){
         Ucesnik *temp=new Ucesnik[n+1];
         for(int i=0;i<n;i++){
             temp[i]=ucesnici[i];
         }
         temp[n++]=dr;
         delete[]ucesnici;
         ucesnici=temp;
         return *this;
     }
     double prosecnoVozrast(){
         double vozrast=0.0;
         for(int i=0;i<n;i++){
             vozrast+=ucesnici[i].getAge();
         }
         return double(vozrast/n);
     }
     void pecatiPomladi(Ucesnik &dr){
         for(int i=0;i<n;i++){
             if(ucesnici[i].getAge()<dr.getAge()){
                 cout<<ucesnici[i]<<endl;
             }
         }
     }
};
int main() {
    char ime[100];
    bool maski;
    int vozrast, n;
    cin >> n;
    char lokacija[100];
    cin >> lokacija;
    Maraton m(lokacija);
    Ucesnik **u = new Ucesnik*[n];
    for(int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
        u[i] = new Ucesnik(ime, maski, vozrast);
        m += *u[i];
    }
    m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for(int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete [] u;
    return 0;
}
