/*Да се креира класа за опишување на еден сервис за мобилни уреди. За секој мобилен телефон се чуваат податоци за:
- модел (низа од 100 знаци), тип на уред (смартфон или компјутер), потребни часови за основна проверка (децимален број), година на производство (цел број).
Сите уреди имаат исто времетраење за основна проверка и истата изнесува 1 час. Оваа вредност може да се смени со одлука на сервисот. Дополнително, уредите кои се понови 
од 2015 година имаат потреба од дополнителени 1.5 часа за проверка. При проверка, лаптопите имаат потреба од дополнителни 2 часа за софтверска дијагностика.
За оваа класа да се имплементира оператор << за печатење на уред во формат:
[modelnauredotl]
[tipnaured] [casovizaproverka]
Каде часовите за проверка се оние од основната проверка+ дополнителни 2 часа доколку уредот е понов од 2015 + 2 часа доколу уредот е лаптоп.

Да се креира класа MobileServis во која се чува:
- адреса (низа од 100 знаци), низа од уреди (динамички алоцирана низа) и број на уреди.
За класата да се обезбедат:
- operatoror+= за додавање на нов уред во сервисот.(5 поени) Не смее да се дозволи годината на производство на уредот да биде поголема од 2019 или помала од 2000. 
Ако се направи обид за додавање на уред со невалидна година, треба да се генерира исклучок InvalidProductionDate.
- Функција pecatiUredi со која се печатат сите уреди со времето потребно за нивната проверка во сервисот (5 поени).
Да се обезбедат сите дополнителни методи потребни за правилно функционирање на програмата.*/

#include <iostream>
#include <cstring>
using namespace std;
enum tip{
    smartfon,kompjuter
};
class Device{
protected:
    char podatoci[100];
    tip t;
    static float casovi;
    int godina;
public:
    Device(){}
    Device(char *podatoci, tip t, int godina){
        strcpy(this->podatoci,podatoci);
        this->t=t;
        this->godina=godina;
    }
    static void setPocetniCasovi(float casovi) {
        Device::casovi = casovi;
    }
    double vkCasovi()const {
        double c=casovi;
        if(godina>2015){
            c+=2;
        }
        if(t){
            c+=2;
        }
        return c;
    }

    friend ostream &operator<<(ostream &os, const Device &device) {
        os <<device.podatoci <<endl;
        if(device.t==0) {
            os << "Mobilen ";
        }
        if(device.t==1) {
            os << "Laptop ";
        }
        os<<device.vkCasovi()<<endl;
        return os;
    }

    int getGodina() const {
        return godina;
    }
};

class InvalidProductionDate{
public:
    InvalidProductionDate() {
    }
    void msg(){
        cout<<"Невалидна година на производство"<<endl;
    }
};
class MobileServis{
    char adresa[100];
    Device *uredi;
    int n;
public:
    MobileServis(){
        uredi= nullptr;
        n=0;
    }
    MobileServis(char *adresa){
        strcpy(this->adresa,adresa);
        uredi= nullptr;
        n=0;
    }
    ~MobileServis(){delete[]uredi;}
    MobileServis(const MobileServis &dr){
        strcpy(adresa,dr.adresa);
        n=dr.n;
        uredi=new Device[dr.n];
        for(int  i=0;i<dr.n;i++){
            uredi[i]=dr.uredi[i];
        }
    }
    MobileServis &operator=(const MobileServis &dr){
        if(this!=&dr){
            delete [] uredi;
            strcpy(adresa,dr.adresa);
            n=dr.n;
            uredi=new Device[dr.n];
            for(int  i=0;i<dr.n;i++){
                uredi[i]=dr.uredi[i];
            }
        }
        return *this;
    }
    MobileServis &operator+=(const Device &dr){
        if(dr.getGodina()>2019 || dr.getGodina()<2000){
            throw InvalidProductionDate();
        }
        Device *temp=new Device[n+1];
        for(int i=0;i<n;i++){
            temp[i]=uredi[i];
        }
        temp[n++]=dr;
        delete[]uredi;
        uredi=temp;
        return *this;
    }
    void pecatiCasovi(){
        cout<<"Ime: "<<adresa<<endl;
        for(int i=0;i<n;i++){
            cout<<uredi[i];
        }
    }
    void pecatiUredi(){
        for(int i=0;i<n;i++){
            cout<<uredi[i].vkCasovi()<<endl;
        }
    }
};
float Device::casovi=1;

int main()
{
    int testCase;
    cin >> testCase;
    char ime[100];
    int tipDevice;
    int godina;
    int n;
    Device devices[50];
    if (testCase == 1){
        cout << "===== Testiranje na klasite ======" << endl;
        cin >> ime;
        cin >> tipDevice;
        cin >> godina;
        Device ig(ime,(tip)tipDevice,godina);
        cin>>ime;
        MobileServis t(ime);
        cout<<ig;
    }
    if (testCase == 2){
        cout << "===== Testiranje na operatorot += ======" << endl;
        cin>>ime;
        cin >> n;
        MobileServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            try{t+=tmp;}
            catch(InvalidProductionDate e){
                e.msg();
            }
        }
        t.pecatiCasovi();
    }
    if (testCase == 3){
        cout << "===== Testiranje na isklucoci ======" << endl;
        cin>>ime;
        cin >> n;
        MobileServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            try{t+=tmp;}
            catch(InvalidProductionDate e){
                e.msg();
            }
        }
        t.pecatiCasovi();
    }
    if (testCase == 4){
        cout <<"===== Testiranje na konstruktori ======"<<endl;
        cin>>ime;
        cin >> n;
        MobileServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            try{t+=tmp;}
            catch(InvalidProductionDate e){
                e.msg();
            }
        }
        MobileServis t2 = t;
        t2.pecatiCasovi();
    }
    if (testCase == 5){
        cout << "===== Testiranje na static clenovi ======" << endl;
        cin>>ime;
        cin >> n;
        MobileServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);

            try {t+=tmp;}
            catch(InvalidProductionDate e){
                e.msg();
            }
        }
        t.pecatiCasovi();
        cout << "===== Promena na static clenovi ======" << endl;
        Device::setPocetniCasovi(2);
        t.pecatiCasovi();
    }

    if (testCase == 6){
        cout << "===== Testiranje na kompletna funkcionalnost ======" << endl;
        cin>>ime;
        cin >> n;
        MobileServis t(ime);
        for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            try{t+=tmp;}
            catch(InvalidProductionDate e){
                e.msg();
            }
        }
        Device::setPocetniCasovi(3);
        MobileServis t2 = t;
        t2.pecatiCasovi();
    }

    return 0;

}

