//This exercise is from the second partial exam in 2024
/*Дефинирајте апстрактна класа Museum со следниве спецификации:
- Име на музејот (низа од максимум 50 знаци/стринг), Град во кој се наоѓа (низа од максимум 50 знаци/стринг), Основна цена на билет (реален број) и 
  Број на работни часови во неделата (цел број).
Дополнително, класата треба да содржи двe чисто виртуелни функции-членови на класaта:
- void printDetails() - функција која ги печати информациите за објектот
- double calculateTicketCost() - функција која враќа цена на билет за посета на музеј
Да се дефинираат две класи, ScientificMuseum и ArtMuseum, кои наследуваат од класата Museum.
За класата ScientificMuseum дополнително се чува информација за интерактивни поставки во рамки на музејот (Boolean променлива), како и информација за број на 
мултимедијални презентации кои може да се посетат во музејот (целобројна променлива).
- Цената на билет (функција double calculateTicketCost()) за ScientificMuseum се пресметува на следниот начин:
  Ако музејот нуди интерактивни поставки, тогаш цената се зголемува за 12%. Дополнително, секоја мултимедијална презентација ја зголемува цената за $6.
- Функцијата void printDetail() ги печати карактеристиките за музејот во следниот формат:
[Ime na muzej] - (Scientific) [Grad] [Broj na mult. prezentacii] [Cena na karta]
За класата ArtMuseum дополнително се чува информација за тоа дали музејот нуди опции за аматерски изложби (Boolean променлива), како и информација за бројот на
оригинални не-реставрирани уметнички дела (цел број).
- Цената на билет (функција double calculateTicketCost()) за  ArtMuseum се пресметува на следниот начин:
  Ако музејот нуди опција за аматерски изложби, тогаш цената се намалува за 18%. Дополнително, секое оригинално не-реставрирано дело ја зголемува цената за $3.
- Функцијата void printDetail() ги печати карактеристиките за музејот во следниот формат:
[Ime na muzej] - (Art) [Grad] [Amaterski izlozbi] [Cena na karta] (10 поени)
Да се дефинира следната глобална функција:
- int findCheapestScientificMuseum(Museum **m, int n) која како аргумент прима низа од покажувачи кон музеи и големина на низата, а како резултат го враќа индексот на 
научниот музеј (ScientificMuseum) кој има најниска цена на карта во низата. Доколку не постои таков објект во низата, функцијата враќа -1. Ако повеќе музеи имаат 
иста цена на картата, се избира тој со повеќе работни часови во неделата (последниот таков).
----------------------------------------------
Define an abstract class Museum with the following specifications:
- Name of the museum (string), City where the museum is located (string), Base ticket price (floating-point number),Number of working hours in the week (integer)
Additionally, the class should contain two pure virtual member functions:
- void printDetails() - function that prints the object's information
- double calculateTicketCost() - function that returns the ticket price for visiting the museum
Define two classes, ScientificMuseum and ArtMuseum, which inherit from the Museum class
For the ScientificMuseum class, additionally store information about:
- Interactive exhibits within the museum (Boolean variable), Number of multimedia presentations available in the museum (integer variable).
The ticket price (function double calculateTicketCost()) for ScientificMuseum is calculated as follows:
If the museum offers interactive exhibits, the price increases by 12%. Additionally, each multimedia presentation increases the price by $6.
The function void printDetail() prints the characteristics of the museum in the following format:
[Museum Name] - (Scientific) [City] [Number of multimedia presentations] [Ticket price] 
For the ArtMuseum class, additionally store information about:
- Whether the museum offers options for amateur exhibitions (Boolean variable), Number of original non-restored artworks (integer variable)
The ticket price (function double calculateTicketCost()) for ArtMuseum is calculated as follows:
If the museum offers options for amateur exhibitions, the price decreases by 18%. Additionally, each original non-restored artwork increases the price by $3.
The function void printDetail() prints the characteristics of the museum in the following format:
[Museum Name] - (Art) [City] [Amateur exhibitions] [Ticket price] 
Define the following global function:
- int findCheapestScientificMuseum(Museum **m, int n) which takes as an argument an array of pointers to museums and the size of the array, and returns the index of the 
scientific museum (ScientificMuseum) with the lowest ticket price in the array. If no such object exists in the array, the function returns -1. If multiple museums have 
the same ticket price, the one with more working hours in the week is chosen (the last one found).*/

//CODE

#include <iostream>
#include <cstring>
using namespace std;

class Museum{
protected:
    string name;
    string city;
    double price;
    int hours;
public:
    Museum(const string &name, const string &city, double price, int hours) : name(name), city(city), price(price),hours(hours) {}
    virtual void printDetail()const=0;
    virtual double calculateTicketCost()const=0;

    int getHours() const {
        return hours;
    }
};
class ScientificMuseum:public Museum{
private:
    bool interaktivniPostapki;
    int prezentacii;
public:
    ScientificMuseum(const string &name, const string &city, double price, int hours, bool interaktivniPostapki,int prezentacii) : Museum(name, city, price, hours), interaktivniPostapki(interaktivniPostapki),prezentacii(prezentacii) {}

    void printDetail() const override {
        cout<<name<<" - (Scientific) "<<city<<" "<<prezentacii<<" "<<calculateTicketCost()<<endl;
    }

    double calculateTicketCost() const override {
        double c=price;
        if(interaktivniPostapki){
            c=c*1.12;
        }
        c=c+prezentacii*6;
        return c;
    }
};
class ArtMuseum:public Museum{
private:
    bool izlozbi;
    int umetnickiDela;
public:
    ArtMuseum(const string &name, const string &city, double price, int hours, bool izlozbi, int umetnickiDela): Museum(name, city, price, hours), izlozbi(izlozbi), umetnickiDela(umetnickiDela) {}

    void printDetail() const override {
        cout<<name<<" - (Art) "<<city<<" "<<izlozbi<<" "<<calculateTicketCost()<<endl;
    }

    double calculateTicketCost() const override {
        double c=price;
        if(izlozbi){
            c=c*0.82;
        }
        c=c+umetnickiDela*3;
        return c;
    }
};
int findCheapestScientificMuseum(Museum **m, int n){
    int index = -1;
    double min = m[0]->calculateTicketCost();
    int maxWeeklyHours = 0;  // Initialize to zero or appropriate starting value

    for (int i = 0; i < n; ++i) {
        ScientificMuseum *tmp = dynamic_cast<ScientificMuseum *>(m[i]);
        if (tmp) {
            double ticketCost = tmp->calculateTicketCost();
            if (ticketCost < min) {
                min = ticketCost;
                maxWeeklyHours = tmp->getHours();
                index = i;  // Update index to current museum
            } else if (ticketCost == min && tmp->getHours() >= maxWeeklyHours) {
                maxWeeklyHours = tmp->getHours();
                index = i;  // Update index to current museum if hours are higher or equal
            }
        }
    }

    return index;
}

int main() {
    int n, testCase, type;
    cin >> testCase >> n;
    cin.ignore();

    Museum** m = new Museum*[n];

    for (int i = 0; i < n; ++i) {
        string name;
        string city;
        float base_price;
        int working_hours;

        cin >> type;
        cin.ignore();
        getline(cin, name);
        getline(cin, city);
        cin >> base_price;
        cin.ignore();
        cin >> working_hours;
        cin.ignore();

        if (type == 1) {
            bool interactive_shows;
            int multimedia_pres;

            cin >> interactive_shows >> multimedia_pres;
            cin.ignore();

            m[i] = new ScientificMuseum(name, city, base_price, working_hours, interactive_shows, multimedia_pres);
        } else {
            bool amateur_shows;
            int original_artwork;

            cin >> amateur_shows >> original_artwork;
            cin.ignore();

            m[i] = new ArtMuseum(name, city, base_price, working_hours, amateur_shows, original_artwork);
        }
    }

    if(testCase == 1){
        cout << "Abstract and child classes OK" << endl;
    }
    else if(testCase == 2){
        for(int i = 0; i < n; i++){
            cout << m[i]->calculateTicketCost() << endl;
        }
        cout << "calculateTicketCost method OK" << endl;
    }
    else if(testCase == 3){
        for(int i = 0; i < n; i++){
            m[i]->printDetail();
        }
        cout << "printDetail method OK" << endl;
    }
    else if(testCase == 4){
        int cheapest_sci_museum_index = findCheapestScientificMuseum(m, n);
        if(cheapest_sci_museum_index>=0){
            m[cheapest_sci_museum_index]->printDetail();
        }else{
            cout << "Scientific Museum not found in the array!"<<endl;
        }
        cout << "findCheapestOnlineOrder method OK" << endl;
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
Science and Tech Museum
New York
15.5
40
1
5
2
Modern Art Museum
Chicago
18.0
35
1
203*/
//OUTPUT1
/*Abstract and child classes OK*/

//INPUT2
/*2
4
1
Science and Tech Museum
New York
15.5
40
1
5
2
Modern Art Museum
Chicago
18.0
35
1
203
1
Natural History Museum
Los Angeles
12.5
40
0
3
2
Classic Art Museum
San Francisco
20.0
20
0
82*/
//OUTPUT2
/*47.36
623.76
30.5
266
calculateTicketCost method OK*/

//INPUT3
/*3
2
1
Science and Tech Museum
New York
15.5
40
1
5
2
Modern Art Museum
Chicago
18.0
35
1
203*/
//OUTPUT3
/*Science and Tech Museum - (Scientific) New York 5 47.36
Modern Art Museum - (Art) Chicago 1 623.76
printDetail method OK*/

//INPUT4
/*4
2
2
Modern Art Museum
Chicago
18.0
35
1
203
2
Classic Art Museum
San Francisco
20.0
20
0
82*/
//OUTPUT4
/*Scientific Museum not found in the array!
findCheapestOnlineOrder method OK*/

//INPUT5
/*4
4
1
Science and Tech Museum
New York
15.5
40
1
5
2
Modern Art Museum
Chicago
18.0
35
1
203
1
Natural History Museum
Los Angeles
12.5
40
0
3
2
Classic Art Museum
San Francisco
20.0
20
0
82*/
//OUTPUT5
/*Natural History Museum - (Scientific) Los Angeles 3 30.5
findCheapestOnlineOrder method OK*/

//INPUT6
/*4
4
1
Science and Tech Museum
New York
15.5
42
1
5
1
Science and Tech Museum 2
New York
15.5
43
1
5
1
Natural History Museum
Los Angeles
15.5
40
1
5
2
Classic Art Museum
San Francisco
20.0
20
0
82*/
//OUTPUT6
/*Science and Tech Museum 2 - (Scientific) New York 5 47.36
findCheapestOnlineOrder method OK*/
