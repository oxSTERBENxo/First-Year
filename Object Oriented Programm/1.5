/*За потребите на една продавница за гитари, потребно е да се направи програма за менаџирање на магацинот.
За таа цел, треба да се креира класа Gitara. Класата треба да содржи:
Сериски број (низа од 25 знаци), Набавна цена (реален број), Година на производство (цел број), Тип (низа од 40 знаци).
Да се дефинира метод daliIsti кој како аргумент ќе добие објект од тип Gitara и ќе ги спореди двете гитари според нивниот сериски број.
Дополнително, за оваа класа да се направи функција pecati() за печатење на објектот во следниот формат: [СерискиБрој] [Тип] [Цена]
Да се креира класа Magacin која содржи:
Име на магацинот (низа од 30 знаци), Локација на магацинот (низа од 60 знаци), 
Низа од гитари кои ги поседува магацинот (динамички алоцирана низа од објекти од класата Gitara)
Број на објекти во низата (цел број), Година на отвoрање (цел број).
За класата Magacin да се дефинира метод double vrednost() што ќе ја пресметува моменталната вредност на гитарите кои се наоѓаат во магацинот. 
Таа се пресметува како збир од вредноста на сите гитари од кои е составен магацинот.
Дополнително, за класата да се дефинираат функциите:
-void dodadi(Gitara d) за сместување на нова гитара во магацин (додавање на нов објект од класата Gitara во динамички алоцираната низа со гитари) (10 поени)
-void prodadi(Gitara p) за бришење на дадена гитара од магацинот (бришење на сите објекти кои се исти како аргументот проследен во фунцијата)(10 поени)
-void pecati(bool daliNovi) за печатење на информации за магацинот така што во првиот ред ќе биде прикажано имете и локацијата на магацинот,
а потоа во секој нареден ред ќе бидат прикажани гитарите кои се наоѓаат во магацинот. Доколку пратената променлива има вредност true ќе се печатат само гитарите
кои имаат година на производство понова од годината на отварање на магацинот. Во спротивно се печатат сите гитари.
За класите да се дефинираат потребните конструктори, деструктор и сите останати методи за правилно функционирање на програмата. 
Сите податочни членови во класите се приватни.*/

#include <iostream>
#include <cstring>
using namespace std;
class Gitara{
private:
    char seriski[25];
    double nabavna;
    int godina;
    char tip[40];
public:
    char *getSeriski(){
        return seriski;
    }

    double getNabavna(){
        return nabavna;
    }

    int getGodina(){
        return godina;
    }

    char *getTip(){
        return tip;
    }

    Gitara( char *tip="",char *seriski="", int godina=2000,double nabavna=0){
        strcpy(this->tip, tip);
        strcpy(this->seriski,seriski);
        this->nabavna=nabavna;
        this->godina=godina;
    }
    Gitara(const Gitara &dr){
        strcpy(this->tip, dr.tip);
        strcpy(this->seriski,dr.seriski);
        this->nabavna=dr.nabavna;
        this->godina=dr.godina;
    }
    Gitara  &operator=(const Gitara &dr){
        if(this!=&dr){
            strcpy(this->tip, dr.tip);
            strcpy(this->seriski,dr.seriski);
            this->nabavna=dr.nabavna;
            this->godina=dr.godina;
        }
        return *this;
    }
    bool daliIsti(Gitara &dr){
        return strcmp(seriski,dr.seriski)==0;
    }
    void pecati(){
        cout<<seriski<<" "<<tip<<" "<<nabavna<<endl;
    }
};
class Magacin{
private:
    char name[50];
    char lokacija[60];
    Gitara *gitari;
    int n;
    int godina;
public:
    Magacin(char *name="", char *lokacija="",int godina=0){
        strcpy(this->name,name);
        strcpy(this->lokacija,lokacija);
        gitari= nullptr;
        n=0;
        this->godina=godina;
    }
    Magacin(const Magacin &dr){
        strcpy(this->name,dr.name);
        strcpy(this->lokacija,dr.lokacija);
        this->n=dr.n;
        this->godina=dr.godina;
        this->gitari=new Gitara[n];
        for(int i=0;i<n;i++){
            this->gitari[i]=dr.gitari[i];
        }
    }
    Magacin &operator=(const Magacin &dr){
        if(this!=&dr){
            delete [] gitari;
            strcpy(this->name,dr.name);
            strcpy(this->lokacija,dr.lokacija);
            this->n=dr.n;
            this->godina=dr.godina;
            this->gitari=new Gitara[n];
            for(int i=0;i<n;i++){
                this->gitari[i]=dr.gitari[i];
            }
        }
        return *this;
    }
    ~Magacin(){delete [] gitari;}
    double vrednost(){
        double sum=0;
        for(int i=0;i<n;i++){
            sum+=gitari[i].getNabavna();
        }
        return sum;
    }
    void dodadi(Gitara dr){
        Gitara *temp =new Gitara[n+1];
        for(int i=0;i<n;i++){
            temp[i]=gitari[i];
        }
        temp[n++]=dr;
        delete [] gitari;
        gitari=temp;
    }
    void prodadi(Gitara dr){
        Gitara *temp = new Gitara[n];
        int j=0;
        for(int i=0;i<n;i++){
            if(!gitari[i].daliIsti(dr)){
                temp[j]=gitari[i];
                j++;
            }
        }
        n=j;
        delete [] gitari;
        gitari=temp;
    }
    void pecati(bool daliNovi){
        cout<<name<<" "<<lokacija<<endl;
        if(daliNovi){
            for(int i=0;i<n;i++){
                if(gitari[i].getGodina()>godina){
                    gitari[i].pecati();
                }
            }
        }else{
            for(int i=0;i<n;i++){
                gitari[i].pecati();
            }
        }
    }
};
int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, godina;
    float cena;
    char seriski[50],tip[50];

    if(testCase == 1) {
        cout << "===== Testiranje na klasata Gitara ======" << endl;
        cin>>tip;
        cin>>seriski;
        cin >> godina;
        cin >> cena;
        Gitara g(tip,seriski, godina,cena);
        cout<<g.getTip()<<endl;
        cout<<g.getSeriski()<<endl;
        cout<<g.getGodina()<<endl;
        cout<<g.getNabavna()<<endl;
    } else if(testCase == 2){
        cout << "===== Testiranje na klasata Magacin so metodot print() ======" << endl;
        Magacin kb("Magacin1","Lokacija1");
        kb.pecati(false);
    }
    else if(testCase == 3) {
        cout << "===== Testiranje na klasata Magacin so metodot dodadi() ======" << endl;
        Magacin kb("Magacin1","Lokacija1",2005);
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>tip;
            cin>>seriski;
            cin >> godina;
            cin >> cena;
            Gitara g(tip,seriski, godina,cena);
            cout<<"gitara dodadi"<<endl;
            kb.dodadi(g);
        }
        kb.pecati(true);
    }

    else if(testCase == 4) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() ======" << endl;
        Magacin kb("Magacin1","Lokacija1",2012);
        cin>>n;
        Gitara brisi;
        for (int i=0;i<n;i++){
            cin>>tip;
            cin>>seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip,seriski, godina,cena);
            if(i==2)
                brisi=g;
            cout<<"gitara dodadi"<<endl;
            kb.dodadi(g);
        }
        kb.pecati(false);
        kb.prodadi(brisi);
        kb.pecati(false);
    }
    else if(testCase == 5) {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() i pecati(true) ======" << endl;
        Magacin kb("Magacin1","Lokacija1",2011);
        cin>>n;
        Gitara brisi;
        for (int i=0;i<n;i++){
            cin>>tip;
            cin>>seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip,seriski, godina,cena);
            if(i==2)
                brisi=g;
            cout<<"gitara dodadi"<<endl;
            kb.dodadi(g);
        }
        kb.pecati(true);
        kb.prodadi(brisi);
        cout<<"Po brisenje:"<<endl;
        Magacin kb3;
        kb3=kb;
        kb3.pecati(true);
    }
    else if(testCase ==6)
    {
        cout << "===== Testiranje na klasata Magacin so metodot vrednost()======" << endl;
        Magacin kb("Magacin1","Lokacija1",2011);
        cin>>n;
        Gitara brisi;
        for (int i=0;i<n;i++){
            cin>>tip;
            cin>>seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip,seriski, godina,cena);
            if(i==2)
                brisi=g;
            kb.dodadi(g);
        }
        cout<<kb.vrednost()<<endl;
        kb.prodadi(brisi);
        cout<<"Po brisenje:"<<endl;
        cout<<kb.vrednost();
        Magacin kb3;
        kb3=kb;
    }
    return 0;
}
