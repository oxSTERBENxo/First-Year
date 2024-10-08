//This exercise is from the second partial exam in 2024.
/*Дефинирајте апстрактна класа Library со следниве спецификации:
- Име на библиотеката (низа од максимум 50 знаци/стринг), Град во кој се наоѓа (низа од максимум 50 знаци/стринг), Основна цена на месечна членарина (реален број) и
  Информација дали работи за викенд (Boolean променлива)
Дополнително, класата треба да содржи двe чисто виртуелни функции-членови на класта:
- void printDetail() - функција која ги печати информациите за објектот
- double calculateMembershipCardCost() - функција која враќа цена на чинење на членарина во библиотеката
Да се дефинираат две класи, AcademicLibrary и NationalLibrary, кои наследуваат од класата Library.
За класата AcademicLibrary дополнително се чува информација за отворени можности за истражување (Boolean променлива), како и информација за број на специјализирани 
колекции од списанија во рамки на библиотеката (целобројна променлива).
- Цената на членарина (функција double calculateMembershipCardCost()) за AcademicLibrary се пресметува на следниот начин:
Ако библиотеката нуди отворени можности за истражување, тогаш цената се зголемува за 24%. Дополнително, секоја специјализирани колекции од списанија ја зголемува цената за $6.
- Функцијата void printDetail() ги печати карактеристиките за библиотеката во следниот формат:
[Ime na biblioteka] - (Academic) [Grad] [Broj na spec. kolekcii] [Cena na clenarina]
За класата NationalLibrary дополнително се чува информација за тоа дали библиотеката нуди едукативни програми за културното наследство (Boolean променлива), како и 
информација за бројот на сочувани оригинални ракописи од национално значење (цел број).
- Цената на членарина (функција double calculateMembershipCardCost()) за NationalLibrary се пресметува на следниот начин:
Ако библиотеката нуди едукативни програми, тогаш цената се намалува за 7%. Дополнително, секој сочуван оригинален ракопис ја зголемува цената за $15.
- Функцијата void printDetail() ги печати карактеристиките за библиотеката во следниот формат:
[Ime na biblioteka] - (National) [Grad] [Broj na rakopisi] [Cena na clenarina]
Да се дефинира следната глобална функција:
- int findMostExpensiveNationalLibrary(Library **l, int n) која како аргумент прима низа од покажувачи кон библиотеки и големина на низата, а како резултат го враќа 
индексот во низата на националната библиотека (NationalLibrary) која има најскапата членарина. Доколку не постои таков објект во низата, функцијата враќа -1. Ако повеќе 
национални библиотеки имаат иста цена на членарина, се избира таа која работи за викенд (последниот најден).
--------------------------------------------
Define an abstract class Library with the following specifications:
- Name of the library (string), City where the library is located (string), Base monthly membership fee (floating-point number) and
Information on whether it operates on weekends (Boolean variable)
Additionally, the class should contain two pure virtual member functions:
- void printDetails() - function that prints the object's information
- double calculateMembershipCardCost() - function that returns the membership fee for the library
Define two classes, AcademicLibrary and NationalLibrary, which inherit from the Library class.
For the AcademicLibrary class, additionally store information about:
- Open research opportunities (Boolean variable), Number of specialized journal collections within the library (integer variable)
The membership fee (function double calculateMembershipCardCost()) for AcademicLibrary is calculated as follows:
If the library offers open research opportunities, the fee increases by 24%. Additionally, each specialized journal collection increases the fee by $6.
The function void printDetail() prints the characteristics of the library in the following format:
[Library Name] - (Academic) [City] [Number of specialized collections] [Membership fee]
For the NationalLibrary class, additionally store information about:
- Whether the library offers educational programs on cultural heritage (Boolean variable) and
Number of preserved original manuscripts of national significance (integer variable).
The membership fee (function double calculateMembershipCardCost()) for NationalLibrary is calculated as follows:
If the library offers educational programs, the fee decreases by 7%. Additionally, each preserved original manuscript increases the fee by $15.
The function void printDetail() prints the characteristics of the library in the following format:
[Library Name] - (National) [City] [Number of manuscripts] [Membership fee]
Define the following global function:
- int findMostExpensiveNationalLibrary(Library **l, int n) which takes as an argument an array of pointers to libraries and the size of the array, and returns the index 
in the array of the national library (NationalLibrary) with the highest membership fee. If no such object exists in the array, the function returns -1. If multiple 
national libraries have the same membership fee, the one that operates on weekends is chosen (the last one found).*/

//CODE 

#include <iostream>
using namespace std;

class Library{
protected:
    string biblioteka;
    string grad;
    double cena;
    bool DaliVikend;
public:
    Library(const string &biblioteka, const string &grad, double cena, bool daliVikend) : biblioteka(biblioteka),grad(grad), cena(cena),DaliVikend(daliVikend) {}
    virtual void printDetail()const=0;
    virtual double calculateMembershipCardCost()const=0;

    const string &getBiblioteka() const {
        return biblioteka;
    }

    const string &getGrad() const {
        return grad;
    }

    double getCena() const {
        return cena;
    }

    bool isDaliVikend() const {
        return DaliVikend;
    }
};
class AcademicLibrary:public Library{
private:
    bool istrazuvanje;
    int kolekcii;;
public:
    AcademicLibrary(const string &biblioteka, const string &grad, double cena, bool daliVikend, bool istrazuvanje,int kolekcii) : Library(biblioteka, grad, cena, daliVikend), istrazuvanje(istrazuvanje),kolekcii(kolekcii) {}

    void printDetail() const override {
        cout<<biblioteka<<" - "<<"(Academic) "<<grad<<" "<<kolekcii<<" "<<calculateMembershipCardCost()<<endl;
    }

    double calculateMembershipCardCost() const override {
        double c=cena;
        if(istrazuvanje){
            c=c*1.24;
        }
        c=c+kolekcii*6;
        return c;
    }
};
class NationalLibrary: public Library{
private:
    bool edukativniProgrami;
    int originalniRakopisi;
public:
    NationalLibrary(const string &biblioteka, const string &grad, double cena, bool daliVikend, bool edukativniProgrami,int originalniRakopisi) : Library(biblioteka, grad, cena, daliVikend),edukativniProgrami(edukativniProgrami),originalniRakopisi(originalniRakopisi) {}

    void printDetail() const override {
        cout<<biblioteka<<" - "<<"(National) "<<grad<<" "<<originalniRakopisi<<" "<<calculateMembershipCardCost()<<endl;
    }

    double calculateMembershipCardCost() const override {
        double c=cena;
        if(edukativniProgrami){
            c=c*0.93;
        }
        c=c+originalniRakopisi*15;
        return c;
    }
};

int findMostExpensiveNationalLibrary(Library **pLibrary, int n) {
    double highest = -1.0;
    int id = -1;
    for (int i = 0; i < n; ++i) {
        NationalLibrary *nl = dynamic_cast<NationalLibrary*>(pLibrary[i]);
        if (nl) {
            double currentCost = nl->calculateMembershipCardCost();
            bool operatesOnWeekends = nl->isDaliVikend();
            if (currentCost > highest || (currentCost == highest && operatesOnWeekends)) {
                highest = currentCost;
                id = i;
            }
        }
    }
    return id;
}




int main() {
    int n, testCase, type;
    cin >> testCase >> n;
    cin.ignore();

    Library** m = new Library*[n];

    for (int i = 0; i < n; ++i) {
        string name;
        string city;
        float base_price;
        bool weekend_working;

        cin >> type;
        cin.ignore();
        getline(cin, name);
        getline(cin, city);
        cin >> base_price;
        cin.ignore();
        cin >> weekend_working;
        cin.ignore();

        if (type == 1) {
            bool open_cooperation;
            int specialized_articles;

            cin >> open_cooperation >> specialized_articles;
            cin.ignore();

            m[i] = new AcademicLibrary(name, city, base_price, weekend_working, open_cooperation, specialized_articles);
        } else {
            bool cultural_program;
            int national_articles;

            cin >> cultural_program >> national_articles;
            cin.ignore();

            m[i] = new NationalLibrary(name, city, base_price, weekend_working, cultural_program, national_articles);
        }
    }

    if(testCase == 1){
        cout << "Abstract and child classes OK" << endl;
    }
    else if(testCase == 2){
        for(int i = 0; i < n; i++){
            cout << m[i]->calculateMembershipCardCost() << endl;
        }
        cout << "calculateMembershipCardCost method OK" << endl;
    }
    else if(testCase == 3){
        for(int i = 0; i < n; i++){
            m[i]->printDetail();
        }
        cout << "printDetail method OK" << endl;
    }
    else if(testCase == 4){
        int most_expensive_nat_lib_index = findMostExpensiveNationalLibrary(m, n);
        if(most_expensive_nat_lib_index>=0){
            m[most_expensive_nat_lib_index]->printDetail();
        }else{
            cout << "National Library not found in the array!"<<endl;
        }
        cout << "findMostExpensiveNationalLibrary method OK" << endl;
    }


    for (int i = 0; i < n; ++i) {
        delete m[i];
    }

    delete[] m;

    return 0;
}


//TEST CASES

//INPUT1
/*1
2
1
Harvard Library
Cambridge
25.0
1
1
38
2
Library of Congress
Washington D.C.
30.0
1
1
12*/
//OUTPUT1
/*Abstract and child classes OK*/

//INPUT2
/*2
4
1
Harvard Library
Cambridge
25.0
1
1
38
2
Library of Congress
Washington D.C.
30.0
1
1
12
1
Stanford Library
Stanford
20.0
1
0
120
2
British Library
London
28.0
0
0
17*/
//OUTPUT2
/*259
207.9
740
283
calculateMembershipCardCost method OK*/

//INPUT3
/*3
2
1
Harvard Library
Cambridge
25.0
1
1
38
2
Library of Congress
Washington D.C.
30.0
1
1
12*/
//OUTPUT3
/*Harvard Library - (Academic) Cambridge 38 259
Library of Congress - (National) Washington D.C. 12 207.9
printDetail method OK*/

//INPUT4
/*4
2
1
Harvard Library
Cambridge
25.0
1
1
38
1
Stanford Library
Stanford
20.0
1
0
120*/
//OUTPUT4
/*National Library not found in the array!
findMostExpensiveNationalLibrary method OK*/

//INPUT5
/*4
4
1
Harvard Library
Cambridge
25.0
1
1
38
2
Library of Congress
Washington D.C.
30.0
1
1
12
1
Stanford Library
Stanford
20.0
1
0
120
2
British Library
London
28.0
0
0
20*/
//OUTPUT5
/*British Library - (National) London 20 328
findMostExpensiveNationalLibrary method OK*/

//INPUT6
/*4
4
2
Library of Congress
Washington D.C.
30.0
0
1
12
2
Library of Congress 2
Washington D.C.
30.0
1
1
12
2
British Library
London
28.0
0
0
10
1
Stanford Library
Stanford
20.0
1
0
120*/
//OUTPUT6
/*Library of Congress 2 - (National) Washington D.C. 12 207.9
findMostExpensiveNationalLibrary method OK*/
