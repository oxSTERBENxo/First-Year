/*Да се имплементира класа Trud во која се чуваат информации за:
- вид на труд (еден знак и тоа C за конференциски труд, J за труд во списание), година на издавање (цел број).
Да се имплементира класа Student во која се чува:
- името на студентот (низа од најмногу 30 карактери), индекс (цел број), година на упис (цел број), листа на оцени од положени предмети (низа од цели броеви)
број на положени предмети (цел број).
За оваа класа да се имплементираат следните методи:
- функција rang() што пресметува просек од положените испити на студентот 
- оператор << за печатење на студентот во формат: Индекс Име Година на упис ранг
Да се имплементира класа PhDStudent во која покрај основните информации за студентот дополнително се чува:
- листа од објавени трудови (динамички резервирана низа од објекти од класата Trud), бројот на трудови (цел број)
Во оваа класа да се препокрие соодветно функцијата rang() така што на просекот од положените испити ќе се додаде и збирот од поените од објавените трудови на PhD студентот. 
Во зависност од видот на трудот, секој универзитет има посебен начин на бодување на трудовите. Начинот на бодување е ист за сите PhD студенти. Иницијално да се смета 
дека конференциски труд се бодува со 1 поен, а труд во списание со 3 поени. Универзитетот има можност да ги менува вредностите на бодовите.
За оваа класа да се обезбеди:
- оператор += за додавање нов објект од класата Trud во листата. Ако се направи обид да се внесе труд што е издаден порано од годината на упис на студентот 
да се фрли исклучок (објект од класата Exception). Справувањето со исклучокот треба да се реализира во главната функција main каде што е потребно, но и во конструктор 
ако е потребно. Ако бил генериран исклучок треба да се отпечати соодветна порака за грешка "Ne moze da se vnese dadeniot trud", а новиот труд нема да се внесе во листата 
на трудови од студентот.
Сите променливи на класите се чуваат како приватни. Да се обезбедат сите потребни функции за правилно функционирање на програмата.*/

#include <iostream>
#include <cstring>
using namespace std;

class Trud{
private:
    static int konferenciski;
    static int spisanie;
    int godina;
    char vid;
public:
    Trud(){}
    Trud(char vid, int godina){
        this->vid=vid;
        this->godina=godina;
    }
    char getVid(){
        return vid;
    }
    int getGodina(){
        return godina;
    }
    friend istream &operator>>(istream &in, Trud &dr){
        in>>dr.vid>>dr.godina;
        return in;
    }
    static int getKonferenciski(){
        return konferenciski;
    }
    static int getSpisanie(){
        return spisanie;
    }
    static void setKonferenciski(int k){
        konferenciski=k;
    }
    static void setSpisanie(int s){
        spisanie=s;
    }
};
int Trud::konferenciski=1;
int Trud::spisanie=3;

class Student{
private:
    char ime[30];
    int indeks;
    int upis;
    int *oceni;
    int n;
public:
    Student(){
        oceni=0;
        n=0;
    }
    Student(char *ime, int indeks, int upis, int *oceni, int n){
        strcpy(this->ime,ime);
        this->indeks=indeks;
        this->upis=upis;
        this->n=n;
        this->oceni=new int[n];
        for(int i=0;i<n;i++){
            this->oceni[i]=oceni[i];
        }
    }
    Student(const Student &dr){
        strcpy(this->ime,dr.ime);
        this->indeks=dr.indeks;
        this->upis=dr.upis;
        this->n=dr.n;
        this->oceni=new int[n];
        for(int i=0;i<n;i++){
            this->oceni[i]=dr.oceni[i];
        }
    }
    Student &operator=(Student &dr){
        if(this!=&dr){
            delete [] oceni;
            strcpy(this->ime,dr.ime);
            this->indeks=dr.indeks;
            this->upis=dr.upis;
            this->n=dr.n;
            this->oceni=new int[n];
            for(int i=0;i<n;i++){
                this->oceni[i]=dr.oceni[i];
            }
        } return *this;
    }
    ~Student(){delete [] oceni;}
    virtual Student &operator+=(Trud &dr){}
    virtual double rang(){
        double prosek=0;
        for(int i=0;i<n;i++){
            prosek+=oceni[i];
        }
        return prosek/n;
    }
    friend ostream &operator<<(ostream& os, Student &dr){
        os<<dr.indeks<<" "<<dr.ime<<" "<<dr.upis<<" "<<dr.rang()<<endl;
        return os;
    }
    int getUpis(){
        return upis;
    }
    int getIndeks(){
        return indeks;
    }
};

class Exception{
public:
    Exception(){}
    void message(){
        cout<<"Ne moze da se vnese dadeniot trud"<<endl;
    }
};

class PhDStudent:public Student{
    Trud *trudovi;
    int ntrudovi;
public:
    PhDStudent():Student(){
        trudovi=0;
        ntrudovi=0;
    }
    PhDStudent(char* ime, int indeks, int upis, int* oceni, int n, Trud *trudovi, int ntrudovi)
    :Student(ime,indeks,upis,oceni,n){
        this->ntrudovi=ntrudovi;
        this->trudovi=new Trud[ntrudovi];
        for(int i=0;i<ntrudovi;i++){
            if(trudovi[i].getGodina()<getUpis()) throw Exception();
            this->trudovi[i]=trudovi[i];
        }
    }
    ~PhDStudent(){delete [] trudovi;}
    PhDStudent(const PhDStudent &dr):Student(dr){
        this->ntrudovi=dr.ntrudovi;
        for(int i=0;i<ntrudovi;i++){
            this->trudovi[i]=dr.trudovi[i];
        }
    }
    PhDStudent &operator=(PhDStudent &dr){
        if(this!=&dr){
            delete [] trudovi;
            this->ntrudovi=dr.ntrudovi;
            for(int i=0;i<ntrudovi;i++){
                this->trudovi[i]=dr.trudovi[i];
            }
        } 
        return *this;
    }
    double rang() override{
        double prosek=Student::rang();
        for(int i=0;i<ntrudovi;i++){
            if((trudovi[i].getVid()=='C') || (trudovi[i].getVid()=='c')){
                prosek+=Trud::getKonferenciski();
            } else prosek+=Trud::getSpisanie();
        }
        return prosek;
    }
    PhDStudent &operator+=(Trud &dr) override{
        if(dr.getGodina()<getUpis()) throw Exception();
        Trud *temp=new Trud[ntrudovi+1];
        for(int i=0;i<ntrudovi;i++){
            temp[i]=trudovi[i];
        }
        temp[ntrudovi++]=dr;
        delete [] trudovi;
        trudovi=temp;
        return *this;
    }
};

int main(){
    int testCase;
    cin >> testCase;

    int god, indeks, n, god_tr, m, n_tr;
    int izbor; //0 za Student, 1 za PhDStudent
    char ime[30];
    int oceni[50];
    char tip;
    Trud trud[50];

    if (testCase == 1){
        cout << "===== Testiranje na klasite ======" << endl;
        cin >> ime;
        cin >> indeks;
        cin >> god;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> oceni[j];
        Student s(ime, indeks, god, oceni, n);
        cout << s;

        cin >> ime;
        cin >> indeks;
        cin >> god;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> oceni[j];
        cin >> n_tr;
        for (int j = 0; j < n_tr; j++){
            cin >> tip;
            cin >> god_tr;
            Trud t(tip, god_tr);
            trud[j] = t;
        }
        PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
        cout << phd;
    }
    if (testCase == 2){
        cout << "===== Testiranje na operatorot += ======" << endl;
        Student **niza;
        cin >> m;
        niza = new Student *[m];
        for (int i = 0; i<m; i++){
            cin >> izbor;
            cin >> ime;
            cin >> indeks;
            cin >> god;
            cin >> n;
            for (int j = 0; j < n; j++)
                cin >> oceni[j];

            if (izbor == 0){
                niza[i] = new Student(ime, indeks, god, oceni, n);
            }
            else{
                cin >> n_tr;
                for (int j = 0; j < n_tr; j++){
                    cin >> tip;
                    cin >> god_tr;
                    Trud t(tip, god_tr);
                    trud[j] = t;
                }
                niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
            }
        }
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        // dodavanje nov trud za PhD student spored indeks
        Trud t;
        cin >> indeks;
        cin >> t;

        // vmetnete go kodot za dodavanje nov trud so pomos na operatorot +=
        int flag=0;
        for (int i = 0; i < m; i++){
            if(niza[i]->getIndeks()==indeks && dynamic_cast<PhDStudent *>(niza[i])){
                try{
                    *niza[i]+=t;
                    flag++;
                }
                catch (Exception e){
                    e.message();
                }
            }
        }
        if(!flag){
            cout<<"Ne postoi PhD student so indeks "<<indeks<<endl;
        }

            // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }
    if (testCase == 3){
        cout << "===== Testiranje na operatorot += ======" << endl;
        Student **niza;
        cin >> m;
        niza = new Student *[m];
        for (int i = 0; i<m; i++){
            cin >> izbor;
            cin >> ime;
            cin >> indeks;
            cin >> god;
            cin >> n;
            for (int j = 0; j < n; j++)
                cin >> oceni[j];

            if (izbor == 0){
                niza[i] = new Student(ime, indeks, god, oceni, n);
            }
            else{
                cin >> n_tr;
                for (int j = 0; j < n_tr; j++){
                    cin >> tip;
                    cin >> god_tr;
                    Trud t(tip, god_tr);
                    trud[j] = t;
                }
                niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
            }
        }
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        // dodavanje nov trud za PhD student spored indeks
        Trud t;
        cin >> indeks;
        cin >> t;

        // vmetnete go kodot za dodavanje nov trud so pomos na operatorot += od Testcase 2
        for (int i = 0; i < m; i++){
            if(niza[i]->getIndeks()==indeks){
                *niza[i]+=t;
            }
        }

        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }
    if (testCase == 4){
        cout << "===== Testiranje na isklucoci ======" << endl;
        cin >> ime;
        cin >> indeks;
        cin >> god;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> oceni[j];
        cin >> n_tr;
        for (int j = 0; j < n_tr; j++){
            cin >> tip;
            cin >> god_tr;
            Trud t(tip, god_tr);
            trud[j] = t;
        }
        try{
            PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
            cout<<phd;
        }
        catch (Exception e){
            e.message();
            int j=0;
            for(int i=0;i<n_tr;i++){
                if (trud[i].getGodina()>=god){
                    trud[j++]=trud[i];
                }
            }
            n_tr=j;
            PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
            cout<<phd;
        }
    }
    if (testCase == 5){
        cout << "===== Testiranje na isklucoci ======" << endl;
        Student **niza;
        cin >> m;
        niza = new Student *[m];
        for (int i = 0; i<m; i++){
            cin >> izbor;
            cin >> ime;
            cin >> indeks;
            cin >> god;
            cin >> n;
            for (int j = 0; j < n; j++)
                cin >> oceni[j];

            if (izbor == 0){
                niza[i] = new Student(ime, indeks, god, oceni, n);
            }
            else{
                cin >> n_tr;
                for (int j = 0; j < n_tr; j++){
                    cin >> tip;
                    cin >> god_tr;
                    Trud t(tip, god_tr);
                    trud[j] = t;
                }
                try{
                    niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
                }
                catch(Exception e){
                    e.message();
                }
            }
        }
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        // dodavanje nov trud za PhD student spored indeks
        Trud t;
        cin >> indeks;
        cin >> t;

        // vmetnete go kodot za dodavanje nov trud so pomos na operatorot += i spravete se so isklucokot
        for (int i = 0; i < m; i++){
            if(niza[i]->getIndeks()==indeks){
                try{
                    *niza[i]+=t;
                }
                catch(Exception e){
                    e.message();
                }
            }
        }
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }
    if (testCase == 6){
        cout << "===== Testiranje na static clenovi ======" << endl;
        Student **niza;
        cin >> m;
        niza = new Student *[m];
        for (int i = 0; i<m; i++){
            cin >> izbor;
            cin >> ime;
            cin >> indeks;
            cin >> god;
            cin >> n;
            for (int j = 0; j < n; j++)
                cin >> oceni[j];

            if (izbor == 0){
                niza[i] = new Student(ime, indeks, god, oceni, n);
            }
            else{
                cin >> n_tr;
                for (int j = 0; j < n_tr; j++){
                    cin >> tip;
                    cin >> god_tr;
                    Trud t(tip, god_tr);
                    trud[j] = t;
                }
                niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
            }
        }
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        int conf, journal;
        cin >> conf;
        cin >> journal;

        //postavete gi soodvetnite vrednosti za statickite promenlivi 
        Trud::setKonferenciski(conf);
        Trud::setSpisanie(journal);
        // pecatenje na site studenti
        cout << "\nLista na site studenti:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }

    return 0;
}
