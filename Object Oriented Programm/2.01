/*Издавачката куќа FINKI-Education издава онлајн и печатени книги. За секоја книга се чуваат податоци за:
ISBN бројот (низа од најмногу 20 знаци), насловот (низа од најмногу 50 знаци), авторот (низа од најмногу 30 знаци) и основната цена изразена во $ (реален број). 
Класата за опишување на книгите е апстрактна.
За секоја онлајн книга дополнително се чуваат податоци за url од каде може да се симне (динамички резервирана низа од знаци) и големината изразена во MB (цел број). 
За секоја печатена книга дополнително се чуваат податоци за масата изразена во килограми (реален број) и дали ја има на залиха (логичка променлива).
За секој објект од двете изведени класи треба да бидат на располагање следниве методи:
- Метод bookPrice, за пресметување на продажната цена на книгата на следниот начин: за онлајн книга - цената се зголемува за 20% од основната цена ако книгата е 
поголема од 20MB, за печатена книга - цената се зголемува за 15% од основната цена ако масата на книгата е поголема од 0.7kg
- Преоптоварен оператор > за споредба на две книги од каков било вид според нивната цена.
- Преоптоварен оператор << за печатење на податоците за книгите во формат: //пример: 978-0672326974: C++ Primer Plus, Stephen Prata 24 (isbn,naslov,avtor,cena)
Да се имплементира функција mostExpensiveBook со потпис void mostExpensiveBook (Book** books, int n) во која се печати вкупниот број на онлајн, односно,
печатени книги во проследената низа посебно. Потоа се наоѓа и печати најскапата книга.
Да се обезбедат сите потребни функции за правилно функционирање на програмата.*/

#include<iostream>
#include<cstring>
using namespace std;

class Book{
protected:
    char ISBN[20];
    char naslov[50];
    char avtor[30];
    double cena;
public:
    Book(char *ISBN, char *naslov, char *avtor, double cena){
        strcpy(this->ISBN,ISBN);
        strcpy(this->naslov,naslov);
        strcpy(this->avtor,avtor);
        this->cena=cena;
    }
//    Book& operator=(Book& dr){
//        if(this!=&dr){
//            strcpy(this->ISBN,dr.ISBN);
//            strcpy(this->naslov,dr.naslov);
//            strcpy(this->avtor,dr.avtor);
//            this->cena=dr.cena;
//        } return *this;
//    }
    virtual double bookPrice()const =0;

    bool operator>(const Book &dr) const {
        return dr.bookPrice() < bookPrice();
    }

    friend ostream &operator<<(ostream &os, const Book &book) {
        os <<book.ISBN<<": " <<book.naslov << ", " << book.avtor<<" "<<book.bookPrice()<<endl;
        return os;
    }

    void setISBN(char *ISBN) {
        strcpy(this->ISBN,ISBN);
    }
};
class OnlineBook:public Book{
private:
    char *url;
    int golemina;
public:
    OnlineBook(char *ISBN="", char *naslov="", char *avtor="", double cena=0.0, char *url= nullptr, int golemina=0) : Book(ISBN, naslov, avtor, cena){
        this->golemina=golemina;
        this->url=new char[strlen(url)+1];
        strcpy(this->url,url);
    }
    OnlineBook(const OnlineBook &dr):Book(dr){
        this->golemina=dr.golemina;
        this->url=new char[strlen(dr.url)+1];
        strcpy(this->url,dr.url);
    }
    OnlineBook &operator=(const OnlineBook &dr){
        if(this!=&dr){
            delete[]url;
            strcpy(this->ISBN,dr.ISBN);
            strcpy(this->naslov,dr.naslov);
            strcpy(this->avtor,dr.avtor);
            this->cena=dr.cena;
            this->golemina=dr.golemina;
            this->url=new char[strlen(dr.url)+1];
            strcpy(this->url,dr.url);
        }
        return *this;
    }
    ~OnlineBook(){delete[]url;}
    double bookPrice() const override {
        double onlinePrice=cena;
        if(golemina>20){
            onlinePrice= onlinePrice*1.2;
        }
        return onlinePrice;
    }
};
class PrintBook:public Book{
private:
    double masa;
    bool NaZaliha;
public:
    PrintBook(char *ISBN="", char *naslov="", char *avtor="", double cena=0, double masa=0, bool naZaliha=0) : Book(ISBN, naslov,avtor, cena){
        this->masa=masa;
        this->NaZaliha=NaZaliha;
    }

    double bookPrice() const override {
        double printPrice=cena;
        if(masa>0.7){
            printPrice= printPrice*1.15;
        }
        return printPrice;
    }
};

void mostExpensiveBook(Book **books, int n) {
    int print=0,online=0;
    Book *max=books[0];
    for(int i=0;i<n;i++) {
        if (dynamic_cast<OnlineBook*>(books[i])){
            online++;
        }else{
            print++;
        }
        if(max->bookPrice()<books[i]->bookPrice()){
            max=books[i];
        }
    }
    cout<<"FINKI-Education"<<endl;
    cout<<"Total number of online books: "<<online<<endl;
    cout<<"Total number of print books: "<<print<<endl;
    cout<<"The most expensive book is:"<<endl;
    cout<<*max<<endl;
}


int main(){

    char isbn[20], title[50], author[30], url[100];
    int size, tip;
    float price, weight;
    bool inStock;
    Book  **books;
    int n;

    int testCase;
    cin >> testCase;

    if (testCase == 1){
        cout << "====== Testing OnlineBook class ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++){
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> url;
            cin >> size;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new OnlineBook(isbn, title, author, price, url, size);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 2){
        cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
        cin >> isbn;
        cin.get();
        cin.getline(title, 50);
        cin.getline(author, 30);
        cin >> price;
        cin >> url;
        cin >> size;
        cout << "CONSTRUCTOR" << endl;
        OnlineBook ob1(isbn, title, author, price, url, size);
        cout << ob1 << endl;
        cout << "COPY CONSTRUCTOR" << endl;
        OnlineBook ob2(ob1);
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
        cout << "OPERATOR =" << endl;
        ob1 = ob2;
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
    }
    if (testCase == 3){
        cout << "====== Testing PrintBook class ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++){
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> weight;
            cin >> inStock;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 4){
        cout << "====== Testing method mostExpensiveBook() ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i<n; i++){

            cin >> tip >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            if (tip == 1) {

                cin >> url;
                cin >> size;

                books[i] = new OnlineBook(isbn, title, author, price, url, size);

            }
            else {
                cin >> weight;
                cin >> inStock;

                books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            }
        }

        mostExpensiveBook(books, n);
    }

    for (int i = 0; i<n; i++) delete books[i];
    delete[] books;
    return 0;
}
