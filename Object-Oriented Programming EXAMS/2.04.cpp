/*Да се креира апстрактна класа Pizza за опишување пици. За секоја пица се чуваат следните информации:
- име (низа од максимум 20 знаци), состојки (низа од максимум 100 знаци), основна цена (реален број)
Од оваа класа да се изведат класите FlatPizza и FoldedPizza за опишување на рамни и преклопени пици соодветно.
- За секоја рамна пица дополнително се чува големина (enum - една од три можности: мала, голема и фамилијарна). 
- За секоја преклопена пица дополнително се чува информацијадали тестото е од бело брашно или не (boolean).
За секоја пица треба да се обезбеди метод за пресметување на нејзината продажна цена:
- цената на рамната пица се пресметува така што основната цена се зголемува за 10%, 20% и 30% за мала, голема и фамилијарна пица соодветно.
- цената на преклопената пица се пресметува така што основната цена се зголемува за 10% ако е тестото е од бело брашно, а во спротивно за 30%.
Да се преоптоварат следните оператори:
- оператор << - за печатење сите податоци за пиците во следниов формат:
За рамна пица:[име]: [состојки], [големина] - [продажната цена на пицата]. 
За преклопена пица: [име]: [состојки], [wf - ако е со бело брашно / nwf - ако не е со бело брашно] - [продажната цена на пицата]
- оператор < - за споредување на пиците од каков било вид според нивната продажна цена. (5 поени)
Да се дефинира глобална функција еxpensivePizza што на влез прима низа од покажувачи кон објекти од класата Pizza и нивниот број, 
а како резултат ги печати информациите за пицата со највисока продажна цена. Ако има повеќе пици со иста највисока цена, се печати првата.
Да се дефинираат потребните конструктори и методи во класите за правилно функционирање на програмата.*/

#include <iostream>
#include <cstring>
using namespace std;
enum Size{
    small,big,family
};
class Pizza{
protected:
    char name[20];
    char sostojki[100];
    double osnovna_cena;
public:
    Pizza(char *name="", char *sostojki="", double osnovnaCena=0){
        strcpy(this->name,name);
        strcpy(this->sostojki,sostojki);
        this->osnovna_cena=osnovnaCena;
    }
    virtual double price() const =0;
    bool operator<(const Pizza &rhs) const {
        return price() < rhs.price();
    }
};
class FlatPizza:public Pizza{
private:
    Size t;
public:
    FlatPizza(char *name="", char *sostojki="", double osnovnaCena=0,Size t=small) : Pizza(name,sostojki,osnovnaCena){
        this->t=t;
    }
    double price() const{
        double cena;
        if(t==small){
            cena=osnovna_cena*1.1;
        }else if(t==big){
            cena=osnovna_cena*1.2;
        }else{
            cena=osnovna_cena*1.3;
        }
        return cena;
    }
    friend ostream &operator<<(ostream &os,const FlatPizza &pizza) {
        os<<pizza.name << ": " <<pizza.sostojki;
        os<<", ";
        if(pizza.t==0){
            cout<<"small";
        }else if(pizza.t==1){
            cout<<"big";
        }else{
            cout<<"family";
        }
        os<<" - ";
        //os << ", " << (Size)pizza.t<<" - ";
        os<< pizza.price()<<endl;
        return os;
    }
};
class FoldedPizza:public Pizza{
private:
    bool isWhite;
public:
    FoldedPizza(char *name="", char *sostojki="", double osnovnaCena=0,bool isWhite=true) : Pizza(name,sostojki,osnovnaCena){
        this->isWhite=isWhite;
    }
    FoldedPizza(const FoldedPizza &dr){
        this->isWhite=dr.isWhite;
    }
    double price() const{
        double cena;
        if(isWhite){
            cena=osnovna_cena*1.1;
        }else{
            cena=osnovna_cena*1.3;
        }
        return cena;
    }
    friend ostream &operator<<(ostream &os, const FoldedPizza &pizza) {
        os<<pizza.name << ": " <<pizza.sostojki;
        if(pizza.isWhite){
            os<<", wf - ";
        }else{
            os<<", nwf - ";
        }
        os<< pizza.price()<<endl;
        return os;
    }

    void setWhiteFlour(bool isWhite) {
        FoldedPizza::isWhite = isWhite;
    }
};
void expensivePizza(Pizza **pPizza, int p) {
    double max= pPizza[0]->price();
    int id;
    for(int i=0;i<p;i++){
        if(max< pPizza[i]->price()){
            max= pPizza[i]->price();
            id=i;
        }
    }
    if(FlatPizza *fp =dynamic_cast<FlatPizza*>(pPizza[id])){ //she flat
        cout<<*fp;
    }else if(FoldedPizza *fp2=dynamic_cast<FoldedPizza*>(pPizza[id])){ //ya still folded
        cout<<*fp2;
    }
}

int main() {
    int test_case;
    char name[20];
    char ingredients[100];
    float inPrice;
    Size size;
    bool whiteFlour;

    cin >> test_case;
    if (test_case == 1) {
        // Test Case FlatPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FlatPizza fp(name, ingredients, inPrice);
        cout << fp;
    } else if (test_case == 2) {
        // Test Case FlatPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        int s;
        cin>>s;
        FlatPizza fp(name, ingredients, inPrice, (Size)s);
        cout << fp;

    } else if (test_case == 3) {
        // Test Case FoldedPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice);
        cout << fp;
    } else if (test_case == 4) {
        // Test Case FoldedPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice);
        fp.setWhiteFlour(false);
        cout << fp;

    } else if (test_case == 5) {
        // Test Cast - operator <, price
        int s;

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        cin>>s;
        FlatPizza *fp1 = new FlatPizza(name, ingredients, inPrice, (Size)s);
        cout << *fp1;

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        cin>>s;
        FlatPizza *fp2 = new FlatPizza(name, ingredients, inPrice, (Size)s);
        cout << *fp2;

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza *fp3 = new FoldedPizza(name, ingredients, inPrice);
        cout << *fp3;

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza *fp4 = new FoldedPizza(name, ingredients, inPrice);
        fp4->setWhiteFlour(false);
        cout << *fp4;

        cout<<"Lower price: "<<endl;
        if(*fp1<*fp2)
            cout<<fp1->price()<<endl;
        else cout<<fp2->price()<<endl;

        if(*fp1<*fp3)
            cout<<fp1->price()<<endl;
        else cout<<fp3->price()<<endl;

        if(*fp4<*fp2)
            cout<<fp4->price()<<endl;
        else cout<<fp2->price()<<endl;

        if(*fp3<*fp4)
            cout<<fp3->price()<<endl;
        else cout<<fp4->price()<<endl;

    } else if (test_case == 6) {
        // Test Cast - expensivePizza
        int num_p;
        int pizza_type;

        cin >> num_p;
        Pizza **pi = new Pizza *[num_p];
        for (int j = 0; j < num_p; ++j) {

            cin >> pizza_type;
            if (pizza_type == 1) {
                cin.get();
                cin.getline(name,20);

                cin.getline(ingredients,100);
                cin >> inPrice;
                int s;
                cin>>s;
                FlatPizza *fp = new FlatPizza(name, ingredients, inPrice, (Size)s);
                cout << (*fp);
                pi[j] = fp;
            }
            if (pizza_type == 2) {

                cin.get();
                cin.getline(name,20);
                cin.getline(ingredients,100);
                cin >> inPrice;
                FoldedPizza *fp =
                        new FoldedPizza (name, ingredients, inPrice);
                if(j%2)
                    (*fp).setWhiteFlour(false);
                cout << (*fp);
                pi[j] = fp;

            }
        }

        cout << endl;
        cout << "The most expensive pizza:\n";
        expensivePizza(pi,num_p);


    }
    return 0;
}
