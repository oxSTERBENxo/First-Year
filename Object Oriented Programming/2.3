/*Дадена е класа Kurs во која се чуваат информации за:
- име на курс (низа од знаци) и број на кредити (цел број).
Дадена е класа Student што содржи инфомрации за: 
- индекс на студентот (цел број), низа од оценки на студентот (динамички алоцирана низа на оценките кои претставуваат броеви од 5 до 10) и број на оценки.
Дадена е класа Predavach што содржи инфомрации за: 
- име на предавачот (динамички алоцирана низа од знаци), листа од курсеви кои ги предава предавачот (низа од објекти од класата Kurs) и број на курсеви (цел број).
Да се креира класа Demonstrator, со која се претставуваат студентите држат лабораториските вежби на некои курсеви. Објектите од оваа класа треба да содржат инфомрации за: 
- индекс на студентот, оценки на студентот, број на оценки, име на демонстраторот, листа од курсеви, број на курсеви чии лабораторисски вежби ги држи студентот 
и број на часови во неделата кога студентот држи лабораториски вежби (цел број).
За секој студент да се овозможат следните функции:
- getBodovi() - која враќа цел број кој го претставува број на бодови за даден студент. Студентите кои не се демонстратори имаат бодови кои го претставуваат процентот
на преодни оценки на студентот. (На пример студент со оценки: 5 6 7 ќе има 66 бодови (цел дел од 66.666...) затоа што во 66% од оценките има оценка поголема од 5 ).
Кај секој демонстратор на овие бодовите од оценките се додаваат бодовите од лабораториските вежби: (20*C)/N, каде N e бројот на курсеви кои ги држи, C бројот на часови
во неделата кога студентот држи лабораториски вежби. Во случај кога некој демонстратор не држи ниту еден курс се фрла исклучокот NoCourseException. Справување со исклучокот
треба да реализира онаму каде што е потребно и притоа да се испечати соодветна порака за грешка 
"Demonstratorot so indeks XXXX ne drzi laboratoriski vezbi", каде XXXX е индексот на демонстраторот.
- pecati()- во која се печати само индексот на студентот ако студентот не е демонстратор, а во случај кога студентот е демонстратор во продолжение се печатат информации 
за курсевите чии лабораториски вежби ги држи демонстраторот. Форматот за печатење е: Indeks: ime (Kurs1 Krediti1 ECTS, Kurs2 Krediti2 ECTS,...)
Да се имплементираат следните глобални функции:
- Student& vratiNajdobroRangiran(Student ** studenti, int n ) што враќа референца кон студентот кој има најмногу бодови од листата на дадените n студенти (studenti).
Да забележиме дека оние демонстратори кои не држат лабораториски вежби ќе земеме дека имаат 0 бодови. Да забележиме и дека во примерите секогаш има точно еден студент 
кој има најголем број на бодови.
- void pecatiDemonstratoriKurs (char* kurs, Student** studenti, int n) - која од дадена листа на студенти, ќе ги испечати само оние кои држат лабораториски вежби на курсот kurs.
Да забележиме дека веќе постоечките класи Kurs, Student и Predavach може да се дополнуваат и менуваат. Погледнете ги дадените класи. Во нив покрај конструкторите 
дадени се и други функциите кои можат да се користат.*/

#include<iostream>
#include<string.h>
using namespace std;
class NoCourseException{
    int indeks;
public:
    NoCourseException(int indeks){
        this->indeks=indeks;
    }
    void msg(){
        cout<<"Demonstratorot so indeks "<<indeks<<" ne drzi laboratoriski vezbi"<<endl;
    }
};
class Kurs{
private:
    char ime[20];
    int krediti;
public:
    Kurs (char *ime,int krediti){
        strcpy(this->ime,ime);
        this->krediti=krediti;
    }
    Kurs (){
        strcpy(this->ime,"");
        krediti=0;
    }
    bool operator==(const char *ime) const{
        return strcmp(this->ime,ime)==0;
    }
    char const * getIme()const{
        return ime;
    }
    char *getIme(){
        return ime;
    }
    virtual void pecati ()const{cout<<ime<<" "<<krediti<<"ECTS";}
};

class Student{
protected:
    int *ocenki;
    int brojOcenki;
    int indeks;
public:
    Student(){}
    Student(int indeks,int *ocenki, int brojOcenki){
        this->indeks=indeks;
        this->brojOcenki=brojOcenki;
        this->ocenki=new int[brojOcenki];
        for (int i=0;i<brojOcenki;i++) this->ocenki[i]=ocenki[i];
    }
    Student(const Student &dr){
        this->indeks=dr.indeks;
        this->brojOcenki=dr.brojOcenki;
        this->ocenki=new int[dr.brojOcenki];
        for (int i=0;i<dr.brojOcenki;i++){
            this->ocenki[i]=dr.ocenki[i];
        }
    }
    Student &operator=(const Student &dr){
        if (this!=&dr){
            delete [] ocenki;
            this->indeks=dr.indeks;
            this->brojOcenki=dr.brojOcenki;
            this->ocenki=new int[dr.brojOcenki];
            for (int i=0;i<dr.brojOcenki;i++) this->ocenki[i]=dr.ocenki[i];
            return *this;
        }
        return *this;
    }
    ~Student(){delete [] ocenki;}
    virtual int getBodovi(){
        double preodni=0;
        for(int i=0;i<brojOcenki;i++){
            if(ocenki[i]>5){
                preodni++;
            }
        }
        return int(preodni/brojOcenki*100);
    }
    virtual void pecati(){
        cout<<indeks;
    }
    bool operator<(Student &dr){
        return getBodovi()<dr.getBodovi();
    }
};
class Predavach{
protected:
    int brojKursevi;
    char *imeIPrezime;
    Kurs kursevi[10];
public:
    Predavach(){}
    Predavach(char *imeIPrezime,Kurs *kursevi,int brojKursevi){
        this->brojKursevi=brojKursevi;
        for (int i=0;i<brojKursevi;i++) this->kursevi[i]=kursevi[i];
        this->imeIPrezime=new char[strlen(imeIPrezime)+1];
        strcpy(this->imeIPrezime,imeIPrezime);
    }
    Predavach(const Predavach &dr){
        this->brojKursevi=dr.brojKursevi;
        for (int i=0;i<dr.brojKursevi;i++) this->kursevi[i]=dr.kursevi[i];
        this->imeIPrezime=new char[strlen(dr.imeIPrezime)+1];
        strcpy(this->imeIPrezime,dr.imeIPrezime);
    }
    Predavach &operator=(const Predavach &dr){
        if (this!=&dr){
        delete [] imeIPrezime;
        this->brojKursevi=dr.brojKursevi;
        for (int i=0;i<dr.brojKursevi;i++) this->kursevi[i]=dr.kursevi[i];
        this->imeIPrezime=new char[strlen(dr.imeIPrezime)+1];
        strcpy(this->imeIPrezime,dr.imeIPrezime);
        }
        return *this;
    }
    ~Predavach(){delete [] imeIPrezime;}
    int getBrojKursevi()const {
        return brojKursevi;
    }
    char * const getImeIPrezime()const {
        return imeIPrezime;
    }
    Kurs operator[](int i) const {
        if (i<brojKursevi&&i>=0)
            return kursevi[i];
        else return Kurs();
    }
    void pecati() const  {
        cout<<imeIPrezime<<" (";
        for (int i=0;i<brojKursevi;i++){
            kursevi[i].pecati();
            if (i<brojKursevi-1) cout<<", ";  else cout<<")";
        }
    }
};
class Demonstrator:public Student, public Predavach{
    int brCasevi;
public:
    Demonstrator():Student(),Predavach(){}
    Demonstrator(int indeks,int *ocenki, int brojOcenki, char *imeIPrezime,Kurs *kursevi,int brojKursevi, int brCasovi):
            Student(indeks,ocenki,brojOcenki), Predavach(imeIPrezime,kursevi,brojKursevi){
        this->brCasevi=brCasovi;
        if(brojKursevi==0) throw(NoCourseException(indeks));
    }
    int getBodovi(){
        int bodovi=Student::getBodovi();
        if(getBrojKursevi()==0){
            throw (NoCourseException(indeks));
        }
        bodovi+=(20*brCasevi)/getBrojKursevi();
        return bodovi;
    }
    void pecati(){
        Student::pecati();
        cout<<": "<<imeIPrezime<<" (";
        for (int i=0;i<getBrojKursevi();i++){
            kursevi[i].pecati();
            if (i<getBrojKursevi()-1) cout<<", ";  else cout<<")";
        }

    }
    Kurs getKursevi(int i){
        return kursevi[i];
    }
};

Student &vratiNajdobroRangiran(Student** studenti, int n){
    Student *max=studenti[0];
    int indeks=0;
    for(int i=0;i<n;i++){
        if(max<studenti[i]){
            max=studenti[i];
            indeks=i;
        }
    }
    return *studenti[indeks];
}

void pecatiDemonstratoriKurs(char* kurs, Student** studenti, int n){
    for(int i=0;i<n;i++){
        Demonstrator *d = dynamic_cast<Demonstrator *>(studenti[i]);
        if(d){
            for(int i=0;i<d->getBrojKursevi();i++){
                if(strcmp(d->getKursevi(i).getIme(),kurs)==0){
                    d->pecati();
                    cout<<endl;
                }
            }
        }
    }
}
int main(){

    Kurs kursevi[10];
    int indeks,brojKursevi, ocenki[20],ocenka,brojOcenki,tip,brojCasovi,krediti;
    char ime[20],imeIPrezime[50];

    cin>>tip;

    if (tip==1) //test class Demonstrator
    {
        cout<<"-----TEST Demonstrator-----"<<endl;
        cin>>indeks>>brojOcenki;
        for (int i=0;i<brojOcenki;i++){
            cin>>ocenka;
            ocenki[i]=ocenka;
        }
        cin>>imeIPrezime>>brojKursevi;
        for (int i=0;i<brojKursevi;i++){
            cin>>ime>>krediti;
            kursevi[i]=Kurs(ime,krediti);
        }
        cin>>brojCasovi;

        Demonstrator d(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
        cout<<"Objekt od klasata Demonstrator e kreiran";

    } else if (tip==2) //funkcija pecati vo Student
    {
        cout<<"-----TEST pecati-----"<<endl;
        cin>>indeks>>brojOcenki;
        for (int i=0;i<brojOcenki;i++){
            cin>>ocenka;
            ocenki[i]=ocenka;
        }

        Student s(indeks,ocenki,brojOcenki);
        s.pecati();

    } else if (tip==3) //funkcija getVkupnaOcenka vo Student
    {
        cout<<"-----TEST getVkupnaOcenka-----"<<endl;
        cin>>indeks>>brojOcenki;
        for (int i=0;i<brojOcenki;i++){
            cin>>ocenka;
            ocenki[i]=ocenka;
        }
        Student s(indeks,ocenki,brojOcenki);
        cout<<"Broj na bodovi: "<<s.getBodovi()<<endl;

    } else if (tip==4) //funkcija getVkupnaOcenka vo Demonstrator
    {
        cout<<"-----TEST getVkupnaOcenka-----"<<endl;
        cin>>indeks>>brojOcenki;
        for (int i=0;i<brojOcenki;i++){
            cin>>ocenka;
            ocenki[i]=ocenka;
        }
        cin>>imeIPrezime>>brojKursevi;
        for (int i=0;i<brojKursevi;i++){
            cin>>ime>>krediti;
            kursevi[i]=Kurs(ime,krediti);
        }
        cin>>brojCasovi;

        Demonstrator d(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
        cout<<"Broj na bodovi: "<<d.getBodovi()<<endl;

    } else if (tip==5) //funkcija pecati vo Demonstrator
    {
        cout<<"-----TEST pecati -----"<<endl;
        cin>>indeks>>brojOcenki;
        for (int i=0;i<brojOcenki;i++){
            cin>>ocenka;
            ocenki[i]=ocenka;
        }
        cin>>imeIPrezime>>brojKursevi;
        for (int i=0;i<brojKursevi;i++){
            cin>>ime>>krediti;
            kursevi[i]=Kurs(ime,krediti);
        }
        cin>>brojCasovi;

        Demonstrator d(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
        d.pecati();

    } else if (tip==6) //site klasi
    {
        cout<<"-----TEST Student i Demonstrator-----"<<endl;
        cin>>indeks>>brojOcenki;
        for (int i=0;i<brojOcenki;i++){
            cin>>ocenka;
            ocenki[i]=ocenka;
        }
        cin>>imeIPrezime>>brojKursevi;
        for (int i=0;i<brojKursevi;i++){
            cin>>ime>>krediti;
            kursevi[i]=Kurs(ime,krediti);
        }
        cin>>brojCasovi;

        Student *s=new Demonstrator(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
        s->pecati();
        cout<<"\nBroj na bodovi: "<<s->getBodovi()<<endl;
        delete s;


    } else if (tip==7) //funkcija vratiNajdobroRangiran
    {
        cout<<"-----TEST vratiNajdobroRangiran-----"<<endl;
        int k, opt;
        cin>>k;
        Student **studenti=new Student*[k];
        for (int j=0;j<k;j++){
            cin>>opt; //1 Student 2 Demonstrator
            cin>>indeks>>brojOcenki;
            for (int i=0;i<brojOcenki;i++)
            {
                cin>>ocenka;
                ocenki[i]=ocenka;
            }
            if (opt==1){
                studenti[j]=new Student(indeks,ocenki,brojOcenki);
            }else{
                cin>>imeIPrezime>>brojKursevi;
                for (int i=0;i<brojKursevi;i++){
                    cin>>ime>>krediti;
                    kursevi[i]=Kurs(ime,krediti);
                }
                cin>>brojCasovi;
                try{
                    studenti[j]=new Demonstrator(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
                }
                catch(NoCourseException e){
                    e.msg();
                }
            }
        }
        Student& najdobar=vratiNajdobroRangiran(studenti,k);
        cout<<"Maksimalniot broj na bodovi e:"<<najdobar.getBodovi();
        cout<<"\nNajdobro rangiran:";
        najdobar.pecati();

        for (int j=0;j<k;j++) delete studenti[j];
        delete [] studenti;
    } else if (tip==8) //funkcija pecatiDemonstratoriKurs
    {
        cout<<"-----TEST pecatiDemonstratoriKurs-----"<<endl;
        int k, opt;
        cin>>k;
        Student **studenti=new Student*[k];
        for (int j=0;j<k;j++){
            cin>>opt; //1 Student 2 Demonstrator
            cin>>indeks>>brojOcenki;
            for (int i=0;i<brojOcenki;i++)
            {
                cin>>ocenka;
                ocenki[i]=ocenka;
            }
            if (opt==1){
                studenti[j]=new Student(indeks,ocenki,brojOcenki);
            }else{
                cin>>imeIPrezime>>brojKursevi;
                for (int i=0;i<brojKursevi;i++)
                {
                    cin>>ime>>krediti;
                    kursevi[i]=Kurs(ime,krediti);
                }
                cin>>brojCasovi;
                studenti[j]=new Demonstrator(indeks,ocenki,brojOcenki,imeIPrezime,kursevi,brojKursevi,brojCasovi);
            }
        }
        char kurs[20];
        cin>>kurs;
        cout<<"Demonstratori na "<<kurs<<" se:"<<endl;
        pecatiDemonstratoriKurs (kurs,studenti,k);
        for (int j=0;j<k;j++) delete studenti[j];
        delete [] studenti;

    }


    return 0;
}

