/*Во рамките на еден телекомуникациски оператор, СМС пораките се делат на регуларни и специјални. За секојa СМС порака се знае:
- основна цена за една порака до 160 знаци (реален број), претплатнички број на кој е испратена (низа од знаци со должина 12)
Класата за опишување на СМС пораки е апстрактнa.
За секоја Регуларна СМС дополнително се чуваат податоци за текстот на пораката и тоа дали е користена роаминг услуга (bool променлива). 
За секоја Специјална СМС дополнително се чуваат податоци за тоа дали е наменета за хуманитарни цели (bool променлива).
За секој објект од двете изведени класи треба да бидат на располагање следниве методи:
- Метод SMS_cena(), за пресметување на цената на испратена СМС порака на следниот начин:
  За регуларна СМС - цената се зголемува за 300% од основната цена ако е испратена од странство, а 18% од дома и цената се формира врз база на тоа во колку СМС пораки
  ќе го собере текстот што сакаме да го испратиме. Една регуларна порака може да собере најмногу 160 знаци. Притоа, доколку се надмине 160-от знак, се започнува нова
  порака и цената се пресметува како за две или повеќе пораки (пр. за 162 знаци, цената на СМС е иста како и за 320 знаци).
  За специјална СМС - цената се зголемува за 150% од основната цена ако пораката HE е наменета за хуманитарни цели. Доколку е наменета за тоа, данокот од 18% не се
  пресметува на цената.
  Пресметувањето 18% данок на цената на сите СМС пораки е фиксен и не се менува, додека пак процентот од 300% за регуларни и 150% за специјални СМС е променлив и во 
  зависност од операторот може да се менува. Да се обезбеди механизам за можност за нивно менување.
- Преоптоварен оператор << за печатење на податоците за СМС пораките во формат:
  Тел.број: цена
- Да се имплементира функција vkupno_SMS со потпис: void vkupno_SMS(SMS** poraka, int n) во која се печати вкупниот број на регуларни СМС пораки и нивната вкупна цена, 
како и бројот на специјални СМС пораки и нивната вкупна цена во проследената низа посебно.
Да се обезбедат сите потребни функции за правилно функционирање на програмата.*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class SMS{
protected:
    double osnovnaCena;
    char broj[14];
    static const double danok;
public:
    SMS(){}
    SMS(char *broj, double osnovnaCena){
        strcpy(this->broj,broj);
        this->osnovnaCena=osnovnaCena;
    }
    virtual ~SMS(){}
    virtual double SMS_cena() = 0;
    friend ostream &operator<<(ostream &os, SMS &dr){
        os<<"Tel: "<<dr.broj<<" - cena: "<<dr.SMS_cena()<<"den."<<endl;
        return os;
    }
};

class RegularSMS : public SMS{
    char *msg;
    bool roaming;
    static double regularProcent;
public:
    RegularSMS():SMS(){
        msg=0;
    }
    RegularSMS(char* broj, double osnovnaCena, char* message, bool roaming)
            :SMS(broj,osnovnaCena){
        this->msg=new char[strlen(message)+1];
        strcpy(this->msg,message);
        this->roaming=roaming;
    }
    RegularSMS(const RegularSMS& dr):SMS(dr){
        this->msg=new char[strlen(dr.msg)+1];
        strcpy(this->msg,dr.msg);
        this->roaming=dr.roaming;
    }
    RegularSMS &operator=(RegularSMS &dr){
        if(this!=&dr){
            delete [] msg;
            strcpy(this->broj,dr.broj);
            this->osnovnaCena=dr.osnovnaCena;
            this->msg=new char[strlen(dr.msg)+1];
            strcpy(this->msg,dr.msg);
            this->roaming=dr.roaming;
        }
        return *this;
    }
    double SMS_cena(){
        double cena=osnovnaCena;
        if(roaming){
            cena = osnovnaCena + cena * regularProcent;
        } else {
            cena = cena * danok;
        }
        int tmp=strlen(msg)%160;
        if(tmp){
            cena= cena * (strlen(msg) / 160 + 1);
        }
        else{
            cena = cena * strlen(msg) / 160;
        }
        return cena;
    }
    static double set_rProcent(double s){
        regularProcent= s / 100.0;
    }
};

class SpecialSMS : public SMS{
private:
    bool humanitarna;
    static double specialProcent;
public:
    SpecialSMS():SMS(){}
    SpecialSMS(char* broj, double osnovnaCena, bool humanitarna):SMS(broj, osnovnaCena){
        this->humanitarna=humanitarna;
    }
    virtual double SMS_cena() {
        double c=osnovnaCena;
        if(humanitarna==0){
            c=c+ c * specialProcent;
        }
        return c;
    }

    static void set_sProcent(double specialProcent) {
        SpecialSMS::specialProcent = specialProcent / 100.0;
    }

};

void vkupno_SMS(SMS **poraka, int n) {
    double sumReg=0.0,sumSpec=0.0;
    int reg=0,spec=0;
    for(int i=0;i<n;i++){
        if(dynamic_cast<RegularSMS*>(poraka[i])){
            reg++;
            sumReg=sumReg+poraka[i]->SMS_cena();
        }else if(dynamic_cast<SpecialSMS*>(poraka[i])){
            spec++;
            sumSpec=sumSpec+ poraka[i]->SMS_cena();
        }
    }
    cout<<"Vkupno ima "<<reg<<" regularni SMS poraki i nivnata cena e: "<<sumReg<<endl;
    cout<<"Vkupno ima "<<spec<<" specijalni SMS poraki i nivnata cena e: "<<sumSpec<<endl;
}

const double SMS::danok=1.18;
double RegularSMS::regularProcent=3;
double SpecialSMS::specialProcent=1.5;

int main(){

    char tel[20], msg[1000];
    float cena;
    float price;
    int p;
    bool roam, hum;
    SMS  **sms;
    int n;
    int tip;

    int testCase;
    cin >> testCase;

    if (testCase == 1){
        cout << "====== Testing RegularSMS class ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++){
            cin >> tel;
            cin >> cena;
            cin.get();
            cin.getline(msg, 1000);
            cin >> roam;
            cout << "CONSTRUCTOR" << endl;
            sms[i] = new RegularSMS(tel, cena, msg, roam);
            cout << "OPERATOR <<" << endl;
            cout << *sms[i];
        }
        for (int i = 0; i<n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 2){
        cout << "====== Testing SpecialSMS class ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++){
            cin >> tel;
            cin >> cena;
            cin >> hum;
            cout << "CONSTRUCTOR" << endl;
            sms[i] = new SpecialSMS(tel, cena, hum);
            cout << "OPERATOR <<" << endl;
            cout << *sms[i];
        }
        for (int i = 0; i<n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 3){
        cout << "====== Testing method vkupno_SMS() ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i<n; i++){

            cin >> tip;
            cin >> tel;
            cin >> cena;
            if (tip == 1) {

                cin.get();
                cin.getline(msg, 1000);
                cin >> roam;

                sms[i] = new RegularSMS(tel, cena, msg, roam);

            }
            else {
                cin >> hum;

                sms[i] = new SpecialSMS(tel, cena, hum);
            }
        }

        vkupno_SMS(sms, n);
        for (int i = 0; i<n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 4){
        cout << "====== Testing RegularSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
        cin >> tel;
        cin >> cena;
        cin.get();
        cin.getline(msg, 1000);
        cin >> roam;
        sms1 = new RegularSMS(tel, cena, msg, roam);
        cout << *sms1;

        cin >> tel;
        cin >> cena;
        cin.get();
        cin.getline(msg, 1000);
        cin >> roam;
        cin >> p;
        RegularSMS::set_rProcent(p);
        sms2 = new RegularSMS(tel, cena, msg, roam);
        cout << *sms2;

        delete sms1, sms2;
    }
    if (testCase == 5){
        cout << "====== Testing SpecialSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
        cin >> tel;
        cin >> cena;
        cin >> hum;
        sms1 = new SpecialSMS(tel, cena, hum);
        cout << *sms1;

        cin >> tel;
        cin >> cena;
        cin >> hum;
        cin >> p;
        SpecialSMS::set_sProcent(p);
        sms2 = new SpecialSMS(tel, cena, hum);
        cout << *sms2;

        delete sms1, sms2;
    }

    return 0;
}
