//If you know this one you will pass the exam.

/*Фирмата FINKI Cloud има потреба од решение за управување со image датотеките од различните оперативни системи кои ги користат при сетирање на нови сервери. 
За таа цел потребно е да се дефинираат следниве класи:

o OperativenSistem
Во класата OperativenSistem треба да се чуваат следниве податоци:
- име на оперативниот систем (динамички алоцирана низа од знаци), верзија (float), тип (енумерација со можни вредности LINUX, UNIX, WINDOWS), големина (во GB) (float)
Дополнително, во рамките на класата потребно е да се дефинира:
- конструктори со и без параметри, copy constructor, destructor
- преоптоварување на операторот =
- метод за печатење на информациите - void pecati() (видете го излезот од тест примерите за структурата)
- метод за проверка на еднаквост помеѓу два оперативни системи (два оперативни системи се еднакви ако имаат исто име, верзија, тип и големина) - bool ednakviSe(const OperativenSistem &os)
- метод за споредба на верзии помеѓу два оперативни система - int sporediVerzija(const OperativenSistem &os), 
кој ќе враќа 0 доколку верзиите се исти, -1 доколку верзијата на оперативниот систем од аргументот е поголема и 1 во преостанатиот случај.
- метод за проверка дали два оперативни системи се од иста фамилија. Два оперативни системи се од иста фамилија доколку имаат исто име и се 
од ист тип. bool istaFamilija(const OperativenSistem &sporedba)

o Repozitorium
Во класата Repozitorium треба да се чуваат следниве податоци:
- име на репозиториумот (низа од 20 знака), динамички алоцирана низа од OperativenSistem, број на оперативни системи кои моментално се наоѓаат во репозиториумот (int)
Дополнително, во рамките на класата потребно е да се дефинира:
- конструктор Repozitorium(const char *ime), деструктор
- метод void pecatiOperativniSistemi() кој ќе ги печати сите оперативни системи кои се дел од репозиториумот
- метод void izbrishi(const OperativenSistem &operativenSistem) кој ќе го избрише оперативниот систем проследен како аргумент, 
доколку тој се наоѓа во репозиториумот. Да се користи методот ednakviSe за споредба на два оперативни система.
- метод за додавање на оперативен систем (void dodadi(const OperativenSistem &nov)) кој ќе го има следново однесување:
Доколку веќе постои оперативен систем од иста фамилија (да се користи методот за проверка на фамилија) кој е постар од проследениот оперативен систем, 
тогаш постоечкиот оперативен систем се заменува со новиот.
Во секој друг случај, проследениот оперативен систем се додава како дополнителен во репозиториумот.*/

#include <iostream>
#include <cstring>
using namespace std;

enum Tip{
    LINUX,UNIX,WINDOWS
};
class OperativenSistem{
    char *ime;
    float verzija;
    Tip t;
    float golemina;
public:
    OperativenSistem(){
        ime = nullptr;
    }
    OperativenSistem(char *ime, float verzija=0.0, Tip t=LINUX, float golemina=0.0){
        this->ime = new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        this->verzija=verzija;
        this->t=t;
        this->golemina=golemina;
    }
    ~OperativenSistem(){delete [] ime;}
    OperativenSistem(const OperativenSistem &dr){
        this->ime = new char[strlen(dr.ime)+1];
        strcpy(this->ime,dr.ime);
        this->verzija=dr.verzija;
        this->t=dr.t;
        this->golemina=dr.golemina;
    }
    OperativenSistem &operator=(const OperativenSistem &dr){
        if(this!=&dr){
            delete [] ime;
            this->ime = new char[strlen(dr.ime)+1];
            strcpy(this->ime,dr.ime);
            this->verzija=dr.verzija;
            this->t=dr.t;
            this->golemina=dr.golemina;
        }
        return *this;
    }
    void pecati(){
        cout<<"Ime: "<<ime<<" Verzija: "<<verzija<<" Tip: "<<t<<" Golemina:"<<golemina<<"GB"<<endl;
    }
    bool ednakviSe(const OperativenSistem &dr){
        return ((strcmp(ime,dr.ime)==0)&&(verzija==dr.verzija)&&(t==dr.t)&&(golemina==dr.golemina));
    }
    int sporediVerzija(const OperativenSistem &dr){
        if(verzija==dr.verzija){return 0;}
        else if(verzija<dr.verzija){return -1;}
        else {return 1;}
    }
    bool istaFamilija(const OperativenSistem &dr){
        return ((strcmp(ime,dr.ime)==0)&&(t==dr.t));
    }
};
class Repozitorium{
    char ime[20];
    OperativenSistem *os;
    int n;
public:
    Repozitorium(char *ime){
        strcpy(this->ime,ime);
        os=nullptr;
        n=0;
    }
    ~Repozitorium(){delete [] os;}
    Repozitorium(const Repozitorium &dr){
        strcpy(this->ime,dr.ime);
        this->n=dr.n;
        os = new OperativenSistem[n];
        for(int i=0;i<n;i++){
            this->os[i]=dr.os[i];
        }
    }
    Repozitorium &operator=(const Repozitorium &dr){
        if(this!=&dr){
            delete [] os;
            strcpy(this->ime,dr.ime);
            this->n=dr.n;
            os = new OperativenSistem[n];
            for(int i=0;i<n;i++){
                this->os[i]=dr.os[i];
            }
        }
        return *this;
    }
    void pecatiOperativniSistemi(){
        cout<<"Repozitorium: "<<ime<<endl;
        for(int i=0;i<n;i++){
            os[i].pecati();
        }
    }
    void izbrishi(OperativenSistem &dr){
        OperativenSistem *temp=new OperativenSistem[n];
        int j=0;
        for(int i=0;i<n;i++){
            if(!dr.ednakviSe(os[i])){
                temp[j]=os[i];
                j++;
            }
        }
        n=j;
        delete [] os;
        os=temp;
    }
    void dodadi(OperativenSistem &dr){
        OperativenSistem *temp=new OperativenSistem[n+1];
        int flag=0;
        for(int i=0;i<n;i++){
            if(os[i].istaFamilija(dr)){
                if(os[i].sporediVerzija(dr)==-1){
                    temp[i]=dr;
                    flag=1;
                }else
                    temp[i]=os[i];
            }else
                temp[i]=os[i];
        }
        if(flag==0)
            temp[n++]=dr;
        delete [] os;
        os=temp;
    }
};

int main() {
    char repoName[20];
    cin>>repoName;
    Repozitorium repozitorium=Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin>>brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i<brojOperativniSistemi; i++){
        cin>>ime;
        cin>>verzija;
        cin>>tip;
        cin>>golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
    cin>>ime;
    cin>>verzija;
    cin>>tip;
    cin>>golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
    cout<<"=====Brishenje na operativen sistem====="<<endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}
