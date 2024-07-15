//This exercise is from the second partial exam in 2024
/*Да се дефинира класа Product во која ќе се чуваат информации за производ во една продавница и тоа:
- име (стринг), категорија (стринг) и цена (цел број) и достапна количина (цел број).
За класата да се дефинираат потребните конструктори, оператор за печатење << и метод int totalPrice() - методот ја враќа вкупната вредност на производот пресметана 
како производ на цената и достапната количина.
Да се дефинира класа Store во која ќе се чуваат листа на производи (динамички алоцирана низа од објекти од класата Product и цел број кој ја означува големината на листата).
За класата да се имплементираат:
- Потребните конструктори, Оператор += за додавање на производ (Product) во продавницата, Оператор за печатење <<,  Метод Store fromCategory (string & category) - кој прима 
како аргумент категорија (стринг), а враќа нов објект од класата Store во кој во листата на производи се сместени само производи од категоријата category.
Доколку нема ниту еден таков продукт да се фрли исклучок од класата NoProductFoundException. Справувањето со исклучокот треба да испечати порака 
“No products from category {category} were found in the store”.
Дополнете ја main функцијата со следните барања:
Од датотеката input.txt прочитајте ги информациите за сите производи:
За секој производ во 4 реда се дадени информациите за името, категоријата, цената и количината.
По читањето на информациите за секој производ, секој производ се додава во објектот store.
Во датотеката output1.txt да се испечатат информациите за продавницата.
Во датотеката output2.txt да се испечати резултатот од методот fromCategory за категоријата category вчитана во почетниот код.
----
Define a class Product to store information about a product in a store, including the name (string), category (string), price (integer), and available quantity (integer).
For the class, define the necessary constructors, the print operator <<, and the method int totalPrice() - the method returns the total value of the product calculated 
as the product of the price and available quantity.
Define a class Store to store a list of products (dynamically allocated array of objects from the Product class and an integer indicating the size of the list).
For the class, implement:
- The necessary constructors, The operator += for adding a product (Product) to the store, The print operator <<, The method Store fromCategory(string &category) - which 
takes a category (string) as an argument and returns a new object of the Store class where the list of products contains only products from the specified category.
If there is no such product, throw an exception of the class NoProductFoundException. Handling the exception should print the message 
“No products from category {category} were found in the store”.
Complete the main function with the following requirements:
Read information about all products from the file input.txt
For each product, the information for the name, category, price, and quantity is given in 4 lines.
After reading the information about each product, each product is added to the store object.
Print the store information to the file output1.txt.
Print the result of the fromCategory method for the read category in the initial code to the file output2.txt.*/

//CODE

#include <iostream>
#include <cstring>
#include <fstream>
#include <ostream>
using namespace std;
class NoProductFoundException{
private:
    string kategorija;
public:
    NoProductFoundException(const string &kategorija) : kategorija(kategorija) {}
    void msg(){
        cout<<"No products from category "<<kategorija<<" were found in the store"<<endl;
    }
};
void wtf() {
    ofstream fout("input.txt");
    string line;
    while (getline(std::cin, line)) {
        if (line == "----") {
            break;
        }
        fout << line << endl;
    }
}

void rff(string path) {
    ifstream fin(path);
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}
class Product{
private:
    string ime;
    string kategorija;
    int cena;
    int kolicina;
public:
    Product(const string &ime="",const string &kategorija="", int cena=0, int kolicina=0) : ime(ime), kategorija(kategorija),cena(cena), kolicina(kolicina) {}
    friend ostream &operator<<(ostream &os, Product &product) {
        os << product.ime << " (" << product.kategorija << ") " << product.kolicina << " x " << product.cena << " = " << product.totalPrice();
        return os;
    }
    int totalPrice(){
        int c;
        c=cena*kolicina;
        return c;
    }

    const string &getIme() const {
        return ime;
    }

    const string &getKategorija() const {
        return kategorija;
    }

    int getCena() const {
        return cena;
    }

    int getKolicina() const {
        return kolicina;
    }
};
class Store{
private:
    Product *produkti;
    int n;
public:
    Store(){
        produkti= nullptr;
        n=0;
    }
    ~Store(){delete[]produkti;}
    Store(const Store &dr){
        n = dr.n;
        this->produkti = new Product[dr.n];
        for(int i=0;i<dr.n;i++){
            this->produkti[i]=dr.produkti[i];
        }
    }
    Store &operator=(const Store &dr){
        if(this!=&dr){
            delete[]produkti;
            n = dr.n;
            this->produkti = new Product[dr.n];
            for(int i=0;i<dr.n;i++){
                this->produkti[i]=dr.produkti[i];
            }
        }
        return *this;
    }
    Store &operator+=(Product &dr){
        Product *temp=new Product[n+1];
        for(int i=0;i<n;i++){
            temp[i]=produkti[i];
        }
        temp[n++]=dr;
        delete[]produkti;
        produkti=temp;
        return *this;
    }
    friend ostream &operator<<(ostream &os, const Store &store) {
        for (int i = 0; i < store.n; ++i) {
            os << store.produkti[i] << endl;
        }
        return os;
    }
    Store fromCategory(string &category){
        Store filtered;
        int counter=0;
        for(int i=0;i<n;i++){
            if(produkti[i].getKategorija()==category){
                filtered+=produkti[i];
                counter++;
            }
        }
        if(counter==0){
            throw NoProductFoundException(category);
        }
        return filtered;
    }
};
int main() {

    wtf();


    Store s;

    //TODO your code starts here
    //TODO Read the products from the file and add them in the store `s`
    ifstream ifs("input.txt");
    string ime,kategorija;
    int cena,kolicina;
    while(getline(ifs,ime) && getline(ifs,kategorija) && ifs>>cena && ifs>>kolicina){
        ifs.ignore();
        Product p(ime,kategorija,cena,kolicina);
        s+=p;
    }
    ifs.close();
    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE NEXT COMMENT

    string category;
    cin >> category;

    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE PREVIOUS COMMENT

    //TODO Save the results in the files output1.txt and output2.txt after this line
    ofstream ofs1("output1.txt");
    ofs1<<s;
    ofs1.close();

    ofstream ofs2("output2.txt");
    try{
    Store filtered=s.fromCategory(category);
    ofs2<<filtered<<endl;
    }catch(NoProductFoundException &e){
        e.msg();
    }
    ofs2.close();
    //DO NOT MODIFY THE CODE BELLOW

    cout << "All products:" << endl;
    rff("output1.txt");
    cout << "Products from category " << category << ": " << endl;
    rff("output2.txt");


    return 0;
}

//TEST CASES

//INPUT1
/*Coca-cola zero 1.75L
drinks
80
100
Sandwich with ham and cheese
food
60
150
----
drinks*/
//OUTPUT1
/*All products:
Coca-cola zero 1.75L (drinks) 100 x 80 = 8000
Sandwich with ham and cheese (food) 150 x 60 = 9000
Products from category drinks:
Coca-cola zero 1.75L (drinks) 100 x 80 = 8000*/

//INPUT2
/*Coca-cola zero 1.75L
drinks
80
100
Sandwich with ham and cheese
food
60
150
----
food*/
//OUTPUT2
/*All products:
Coca-cola zero 1.75L (drinks) 100 x 80 = 8000
Sandwich with ham and cheese (food) 150 x 60 = 9000
Products from category food:
Sandwich with ham and cheese (food) 150 x 60 = 9000*/

//INPUT3
/*Coca-cola zero 1.75L
drinks
80
100
Sandwich with ham and cheese
food
60
150
----
beauty*/
//OUTPUT3
/*No products from category beauty were found in the store
All products:
Coca-cola zero 1.75L (drinks) 100 x 80 = 8000
Sandwich with ham and cheese (food) 150 x 60 = 9000
Products from category beauty:*/

//INPUT4
/*Apple
Fruit
100
50
Banana
Fruit
50
100
Milk
Dairy
200
30
Butter
Dairy
250
20
Bread
Bakery
80
40
Eggs
Dairy
150
60
Carrot
Vegetable
60
80
Potato
Vegetable
40
100
----
Fruit*/
//OUTPUT4
/*All products:
Apple (Fruit) 50 x 100 = 5000
Banana (Fruit) 100 x 50 = 5000
Milk (Dairy) 30 x 200 = 6000
Butter (Dairy) 20 x 250 = 5000
Bread (Bakery) 40 x 80 = 3200
Eggs (Dairy) 60 x 150 = 9000
Carrot (Vegetable) 80 x 60 = 4800
Potato (Vegetable) 100 x 40 = 4000
Products from category Fruit:
Apple (Fruit) 50 x 100 = 5000
Banana (Fruit) 100 x 50 = 5000*/

//INPUT5
/*Yogurt
Dairy
180
25
Cheese
Dairy
300
15
Tomato
Vegetable
70
50
Chicken
Meat
500
10
Beef
Meat
800
5
Orange
Fruit
120
40
Lettuce
Vegetable
50
30
Broccoli
Vegetable
90
25
----
Dairy*/
//OUTPUT5
/*All products:
Yogurt (Dairy) 25 x 180 = 4500
Cheese (Dairy) 15 x 300 = 4500
Tomato (Vegetable) 50 x 70 = 3500
Chicken (Meat) 10 x 500 = 5000
Beef (Meat) 5 x 800 = 4000
Orange (Fruit) 40 x 120 = 4800
Lettuce (Vegetable) 30 x 50 = 1500
Broccoli (Vegetable) 25 x 90 = 2250
Products from category Dairy:
Yogurt (Dairy) 25 x 180 = 4500
Cheese (Dairy) 15 x 300 = 4500*/

//INPUT6
/*Fish
Seafood
600
12
Shrimp
Seafood
700
8
Pork
Meat
450
20
Onion
Vegetable
30
50
Garlic
Vegetable
20
100
Cabbage
Vegetable
40
30
Apple
Fruit
100
50
Milk
Dairy
200
30
----
Seafood*/
//OUTPUT6
/*All products:
Fish (Seafood) 12 x 600 = 7200
Shrimp (Seafood) 8 x 700 = 5600
Pork (Meat) 20 x 450 = 9000
Onion (Vegetable) 50 x 30 = 1500
Garlic (Vegetable) 100 x 20 = 2000
Cabbage (Vegetable) 30 x 40 = 1200
Apple (Fruit) 50 x 100 = 5000
Milk (Dairy) 30 x 200 = 6000
Products from category Seafood:
Fish (Seafood) 12 x 600 = 7200
Shrimp (Seafood) 8 x 700 = 5600*/

//INPUT7
/*Pasta
Grains
150
35
Rice
Grains
120
40
Beans
Legumes
90
60
Lentils
Legumes
100
50
Cucumber
Vegetable
60
40
Mushroom
Vegetable
70
25
Peach
Fruit
80
20
Milk
Dairy
200
30
----
Grains*/
//OUTPUT7
/*All products:
Pasta (Grains) 35 x 150 = 5250
Rice (Grains) 40 x 120 = 4800
Beans (Legumes) 60 x 90 = 5400
Lentils (Legumes) 50 x 100 = 5000
Cucumber (Vegetable) 40 x 60 = 2400
Mushroom (Vegetable) 25 x 70 = 1750
Peach (Fruit) 20 x 80 = 1600
Milk (Dairy) 30 x 200 = 6000
Products from category Grains:
Pasta (Grains) 35 x 150 = 5250
Rice (Grains) 40 x 120 = 4800*/

//INPUT8
/*Beef
Meat
800
5
Orange
Fruit
120
40
Lettuce
Vegetable
50
30
Broccoli
Vegetable
90
25
Apple
Fruit
100
50
Banana
Fruit
50
100
Eggs
Dairy
150
60
Potato
Vegetable
40
100
----
Legumes*/
//OUTPUT8
/*No products from category Legumes were found in the store
All products:
Beef (Meat) 5 x 800 = 4000
Orange (Fruit) 40 x 120 = 4800
Lettuce (Vegetable) 30 x 50 = 1500
Broccoli (Vegetable) 25 x 90 = 2250
Apple (Fruit) 50 x 100 = 5000
Banana (Fruit) 100 x 50 = 5000
Eggs (Dairy) 60 x 150 = 9000
Potato (Vegetable) 100 x 40 = 4000
Products from category Legumes:*/
//INPUT9
/*Tomato
Vegetable
70
50
Chicken
Meat
500
10
Beef
Meat
800
5
Orange
Fruit
120
40
Lettuce
Vegetable
50
30
Broccoli
Vegetable
90
25
Apple
Fruit
100
50
Milk
Dairy
200
30
----
Meat*/
//OUTPUT9
/*All products:
Tomato (Vegetable) 50 x 70 = 3500
Chicken (Meat) 10 x 500 = 5000
Beef (Meat) 5 x 800 = 4000
Orange (Fruit) 40 x 120 = 4800
Lettuce (Vegetable) 30 x 50 = 1500
Broccoli (Vegetable) 25 x 90 = 2250
Apple (Fruit) 50 x 100 = 5000
Milk (Dairy) 30 x 200 = 6000
Products from category Meat:
Chicken (Meat) 10 x 500 = 5000
Beef (Meat) 5 x 800 = 4000*/

//INPUT10
/*Tomato
Vegetable
70
50
Chicken
Meat
500
10
Beef
Meat
800
5
Orange
Fruit
120
40
Lettuce
Vegetable
50
30
Broccoli
Vegetable
90
25
Apple
Fruit
100
50
Milk
Dairy
200
30
----
Drink*/
//OUTPUT10
/*No products from category Drink were found in the store
All products:
Tomato (Vegetable) 50 x 70 = 3500
Chicken (Meat) 10 x 500 = 5000
Beef (Meat) 5 x 800 = 4000
Orange (Fruit) 40 x 120 = 4800
Lettuce (Vegetable) 30 x 50 = 1500
Broccoli (Vegetable) 25 x 90 = 2250
Apple (Fruit) 50 x 100 = 5000
Milk (Dairy) 30 x 200 = 6000
Products from category Drink:*/
