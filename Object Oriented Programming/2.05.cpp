/*Да се креира класа Customer за опишување на купувачи на една книжара. За секој купувач се чуваат податоци за:
- името (низа од 50 знаци), електронска адреса (низа од 50 знаци), вид на купувач (стандардни, лојални или вип), основен попуст (цел број изразен во проценти),
дополнителен попуст (цел број изразен во проценти) и број на купени производи.
Сите лојални купувачи со покажување на клуб картичка имаат право на основниот попуст при купување од книжарата. Основниот попуст е ист за сите лојални купувачи и 
изнесува 10%. Оваа вредност може да се смени со одлука на раководството на книжарата. Дополнителниот попуст е фиксен и може да го користат само вип купувачите
и изнесува 20%. Стандардните купувачи немаат право на попуст.
- За оваа класа да се имплементира оператор << за печатење на купувач во формат:
[ime_na_kupuvac]
[email_na_kupuvac]
[broj_na_proizvodi]
[vid_na_kupuvac] [popust_sto_moze_da_go_koristi]
каде попустот е 0% ако купувачот е стандарден, вредноста на основниот попуст, ако е лојален или збир од основниот и дополнителниот попуст, ако купувачот е вип.
Да се креира класа за онлајн книжара FINKI-bookstore во која се чува:
- низа од регистрирани купувачи (динамички алоцирана низа) и број на купувачи.
За класата да се обезбедат:
- operator+= (10 поени) за додавање купувач во листата од купувачи, но само ако веќе не е дел од неа (ако во листата нема купувач со иста електронска адреса). Ако во
листата постои корисник со иста електронска адреса, треба да се генерира исклучок UserExistsException. Потребно е да се обезбеди справување со исклучокот во 
функцијата main на означеното место. Во ваква ситуација се печати порака "The user already exists in the list".
- Функција update со која сите стандардни купувачи со купени повеќе од 5 производи стануваат лојални, а сите лојални купувачи со над 10 купени производи, стануваат вип.
- Оператор << за печатење на информациите за сите регистрирани купувачи.
Да се обезбедат сите дополнителни методи потребни за правилно функционирање на програмата.*/

#include <iostream>
#include <cstring>
using namespace std;
const int MAX=50;
class UserExistsException{
public:
    UserExistsException(){}
    void msg(){
        cout<<"The user already exists in the list!"<<endl;
    }
};
enum typeC{
    standarden, lojalen, vip
};
class Customer{
    char ime[51];
    char email[51];
    typeC type;
    int popust;
    int dopolnitelenPopust;
    int kupeniProizvodi;
public:
    Customer(){
        popust=10;
        dopolnitelenPopust=20;
    }
    Customer(char *ime, char* email, typeC type, int kupeniProizvodi){
        strcpy(this->ime,ime);
        strcpy(this->email,email);
        this->type=type;
        this->kupeniProizvodi=kupeniProizvodi;
        popust=10;
        dopolnitelenPopust=20;
    }

    void setDiscount1(int popust) {
        Customer::popust = popust;
    }
    typeC getType(){
        return type;
    }

    void setType(typeC type) {
        Customer::type = type;
    }

    int getProizvodi(){
        return kupeniProizvodi;
    }
    friend ostream& operator<<(ostream &os, Customer &dr){
        os<<dr.ime<<endl;
        os<<dr.email<<endl;
        os<<dr.kupeniProizvodi<<endl;
        if (dr.type==0){
            os<<"standard 0"<<endl;
        }else if(dr.type==1){
            os<<"loyal "<<dr.popust<<endl;
        }else if(dr.type==2){
            os<<"vip "<<dr.dopolnitelenPopust+dr.popust<<endl;
        }
        return os;
    }
    char *getEmail(){
        return email;
    }
};

class FINKI_bookstore{
    Customer* kupuvaci;
    int n;
public:
    FINKI_bookstore(){
        n=0;
        kupuvaci=0;
    }
    void setCustomers(Customer *dr, int num){
        kupuvaci=new Customer[num];
        for(int i=0;i<num;i++){
            kupuvaci[i]=dr[i];
        }
        n=num;
    }
    FINKI_bookstore &operator+=(Customer dr){
        for(int i=0;i<n;i++){
            if(strcmp(dr.getEmail(),kupuvaci[i].getEmail())==0){
                throw UserExistsException();
            }
        }
        Customer *temp=new Customer[n+1];
        for(int i=0;i<n;i++){
            temp[i]=kupuvaci[i];
        }
        temp[n++]=dr;
        delete [] kupuvaci;
        kupuvaci=temp;
        return *this;
    }
    void update(){
        for(int i=0;i<n;i++){
            if(kupuvaci[i].getType()==lojalen && kupuvaci[i].getProizvodi()>10){
                kupuvaci[i].setType(vip);
            }
            if(kupuvaci[i].getType()==standarden && kupuvaci[i].getProizvodi()>5){
                kupuvaci[i].setType(lojalen);
            }
        }
    }
    friend ostream &operator<<(ostream &os, FINKI_bookstore &dr){
        for(int i=0;i<dr.n;i++){
            os<<dr.kupuvaci[i];
        }
        return os;
    }
};

int main(){
    int testCase;
    cin >> testCase;

    char name[MAX];
    char email[MAX];
    int tC;
    int discount;
    int numProducts;


    if (testCase == 1){
        cout << "===== Test Case - Customer Class ======" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (typeC) tC, numProducts);
        cout << c;

    }

    if (testCase == 2){
        cout << "===== Test Case - Static Members ======" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (typeC) tC, numProducts);
        cout << c;

        c.setDiscount1(5);

        cout << c;
    }

    if (testCase == 3){
        cout << "===== Test Case - FINKI-bookstore ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << fc <<endl;
    }

    if (testCase == 4){
        cout << "===== Test Case - operator+= ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        Customer c(name, email, (typeC) tC, numProducts);
        fc+=c;

        cout << fc;
    }

    if (testCase == 5){
        cout << "===== Test Case - operator+= (exception) ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name,MAX);
        cin.getline(email,MAX);
        cin >> tC;
        cin >> numProducts;
        Customer c(name, email, (typeC) tC, numProducts);
        try{
            fc+=c;
        }
        catch(UserExistsException e){
            e.msg();
        }


        cout << fc;
    }

    if (testCase == 6){
        cout << "===== Test Case - update method  ======" << endl << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for(int i = 0; i < n; ++i) {
            cin.get();
            cin.getline(name,MAX);
            cin.getline(email,MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (typeC) tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << "Update:" << endl;
        fc.update();
        cout << fc;
    }
    return 0;

}
