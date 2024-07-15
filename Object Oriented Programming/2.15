/*Дадена е дел од дефиниција на класата StudentKurs. За секој студент кој слуша некој курс се чуваат информации за:
- неговото име (низа од знаци), оценка од писмен дел (цел број) и дали студентот сака да биде испрашуван и усно (булова променлива).
Оцената за писмениот дел е вредност од 1 до МАX. MAX има почетна вредност 10 која е иста е за сите и може да се промени со соодветна функција setMAX().
Кај оние студенти кои сакаат да бидат испрашувани усно и добиваат и описна оценка. Имплементирај соодветна класа StudentKursUsno во која се чуваат дополнителни информации за:
- описна оценка на усното испрашување (динамичко алоцирана низа од знаци). Описни оценки може да бидат: odlicen, dobro, losho.... Ако описната оценка е odlicen тогаш 
оцената ќе биде најмногу за оценки 2 повисока од оценката од писмениот дел, ако е dobro оценката ќе биде најмногу за 1 повисока, а ако е losho за 1 пониска. Ако студентот
добие некоја друга описна оценка, неговата оценка ќе остане иста со оценката од писмениот дел.
Во класите StudentKurs и StudentKursUsno треба да се имплементираат потребните конструктори, функции за поставување и преземање и деструктор.
За сите објекти од класите треба да се обезбедат следните функции:
- преоптоварен оператор << во кој се печатат информации за студентот на курсот во формат: Ime --- ocenka 
- оcenka() – ја враќа оценката на студентот на курсот 
Во класата StudentKursUsno дефинирај ја функцијата:
- преоптоварен оператор += за поставување на описна оценка на студентот(5 поени)
Ако се направи обид да се внесе описна оценка во која покрај букви има и други знаци треба да се фрли исклучок (објект од класата BadInputException). Фатете го исклучокот 
во главната функција каде што е потребно. Откако ќе го фатите отпечатете соодветна порака за грешка (Greshna opisna ocenka) и справете се со исклучокот така што тие знаци
ќе отстранат од стрингот со описната оценка (ако описната оценка била dо1ba0r ќе се промени во dоbar).
Дадена е дел од дефиницијата на класата KursFakultet во која се чуваат информаци за:
- името на курсот (низа од 30 знаци) и за студентите запишани на курсот (низа од 20 покажувачи кон класата StudentKurs) како и бројот на студенти запишани на курсот.
Еден студент кој запишал некој курс ќе го положи курсот ако има барем MINOCENKA. Вредноста MINOCENKA е членка на класата StudentKurs и има фиксна вредност 6 која не 
може да се промени.
Во класата KursFakultet имплементирај ги функциите:
- функција pecatiStudenti() во која се печатат сите студенти кои го положиле курсот, секој во посебен ред. Претходно во првиот ред се печати: Kursot XXXXX go polozile: 
- функција postaviOpisnaOcenka(char * ime, char* opisnaOcenka) во која на студентот на курсот со даденото име му се поствува описна оценка. Ако тоа не е можно 
функцијата не прави ништо. */

#include<iostream>
#include<cstring>
using namespace std;

class BadInputException{
public:
    BadInputException(){}
    void msg(){
        cout<<"Greshna opisna ocenka"<<endl;
    }
};
class StudentKurs{
protected:
    char ime[30];
    int ocenka;
    bool daliUsno;
    static int MAX;
    static const int MINOCENKA;
public:
    StudentKurs(char *ime,int finalenIspit){
        strcpy(this->ime,ime);
        this->ocenka=finalenIspit;
        this->daliUsno=false;
    }
    StudentKurs(){}
    StudentKurs(const StudentKurs &dr){
        strcpy(this->ime,dr.ime);
        this->ocenka=dr.ocenka;
        this->daliUsno=dr.daliUsno;
    }
    virtual ~StudentKurs(){};
    virtual StudentKurs& operator+=(const char *dr){}
    static void setMAX(int max){
        MAX=max;
    }
    static int getMAX(){
        return MAX;
    }
    friend ostream &operator<<(ostream &os, StudentKurs &dr){
        os<<dr.ime<<" --- "<<dr.getOcenka()<<endl;
        return os;
    }
     char *getIme(){
        return ime;
    }

    virtual int getOcenka(){
        return ocenka;
    }

    bool getDaliUsno(){
        return daliUsno;
    }

    static const int getMINOCENKA() {
        return MINOCENKA;
    }
};

int StudentKurs::MAX=10;
const int StudentKurs::MINOCENKA=6;

class StudentKursUsno : public StudentKurs{
    char* usno;
public:
    StudentKursUsno(): StudentKurs(){
        usno=0;
        daliUsno=true;
    }
    StudentKursUsno(char *ime,int finalenIspit): StudentKurs(ime,finalenIspit){
        usno=0;
        daliUsno=true;
    }
    ~StudentKursUsno(){delete [] usno;}
    StudentKursUsno &operator=(StudentKursUsno &dr){
        if(this!=&dr){
            delete [] usno;
            usno=new char[strlen(dr.usno)+1];
            strcpy(usno,dr.usno);
            strcpy(this->ime,dr.ime);
            this->ocenka=dr.ocenka;
            this->daliUsno=dr.daliUsno;
        } 
        return *this;
    }
    int getOcenka(){
        if(strcmp(usno,"odlicen")==0) {
            if(StudentKurs::getOcenka()+2<=MAX){
                return StudentKurs::getOcenka()+2;
            }
            else{
                return StudentKurs::getOcenka();
            }
        }
        else if(strcmp(usno,"dobro")==0){
            if(StudentKurs::getOcenka()+1<=MAX){
                return StudentKurs::getOcenka()+1;
            }
            else{
                return StudentKurs::getOcenka();
            }
        }
        else if(strcmp(usno,"losho")==0){
            return StudentKurs::getOcenka()-1;
        }
        else{
            return StudentKurs::getOcenka();
        }
    }
    StudentKursUsno &operator+=(char *dr){
        for(int i=0;i<strlen(dr);i++){
            if(dr[i]<'a'||dr[i]>'z') throw BadInputException();
        }
        usno=new char[strlen(dr)+1];
        strcpy(usno,dr);
        return *this;
    }
};

class KursFakultet{
private:
    char naziv[30];
    StudentKurs *studenti[20];
    int broj;

public:
    KursFakultet(char *naziv, StudentKurs** studenti,int broj ){
        strcpy(this->naziv,naziv);
        for (int i=0;i<broj;i++){
            if (studenti[i]->getDaliUsno()){
                this->studenti[i]=new StudentKursUsno(*dynamic_cast<StudentKursUsno*>(studenti[i]));
            }
            else this->studenti[i]=new StudentKurs(*studenti[i]);
        }
        this->broj=broj;
    }
    ~KursFakultet(){
        for (int i=0;i<broj;i++) delete studenti[i];
    }
    void pecatiStudenti(){
        cout<<"Kursot "<<naziv<<" go polozile: "<<endl;
        for(int i=0;i<broj;i++){
            if(studenti[i]->getOcenka()>=StudentKurs::getMINOCENKA()){
                cout<<*studenti[i];
            }
        }
    }

    void postaviOpisnaOcenka(char* ime, char* opisnaOcenka){
        for(int i=0;i<broj;i++){
            if(strcmp(ime,studenti[i]->getIme())==0){
                StudentKursUsno *s = dynamic_cast<StudentKursUsno *>(studenti[i]);
                *s+=opisnaOcenka;
                studenti[i]=s;
            }
        }
    }
};
int main(){

    StudentKurs **niza;
    int n,m,ocenka;
    char ime[30],opisna[10];
    bool daliUsno;
    cin>>n;
    niza=new StudentKurs*[n];
    for (int i=0;i<n;i++){
        cin>>ime;
        cin>>ocenka;
        cin>>daliUsno;
        if (!daliUsno)
            niza[i]=new StudentKurs(ime,ocenka);
        else
            niza[i]=new StudentKursUsno(ime,ocenka);
    }

    KursFakultet programiranje("OOP",niza,n);
    for (int i=0;i<n;i++) delete niza[i];
    delete [] niza;
    cin>>m;

    for (int i=0;i<m;i++){
        cin>>ime>>opisna;
        try{
            programiranje.postaviOpisnaOcenka(ime,opisna);
        }
        catch(BadInputException e){
            e.msg();
            char *tmp = new char[strlen(opisna)+1];
            int j=0;
            for(int i=0;i<strlen(opisna);i++){
                if(opisna[i]<'a'|| opisna[i]>'z'){

                }
                else {
                    tmp[j++]=opisna[i];
                }
            }
            programiranje.postaviOpisnaOcenka(ime,tmp);
        }
    }

    StudentKurs::setMAX(9);

    programiranje.pecatiStudenti();

}

