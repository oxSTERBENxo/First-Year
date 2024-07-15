/*Да се креира класа за опишување на концерти. За еден концерт се чуваат информации за:
- назив (низа од најмногу 20 знаци), локација (низа од најмногу 20 знаци), сезонски попуст (реален број), цена на билет во денари (децимален број).
Сите податоци во класата треба да се приватни. Сезонскиот попуст е ист за сите концерти и може да се менува од страна на менаџерите во зависност од сезоната. 
За таа цел да се обезбеди функција за менување на сезонскиот попуст. Сезонскиот попуст е изразен во проценти и почетната вредност е 20 проценти.
Основната цена на еден билет за концерт се пресметува со методот:
- cena() – која ја враќа цената со сезонскиот попуст
За потребите на еден летен фестивал, треба да се обезбедат посебен вид на забавни концерти, електронски концерти. За секој eлектронски концерт дополнително се чуваат 
инфромации за името на DJ-от(динамички алоцирана низа од знаци), времетраење на настапот во часови (реален број) и логичка променлива за дали се работи за дневна 
или ноќна забава (дневна-true/ноќна-false).
За секој електронски концерт треба да биде на располагање метод за пресметување на цената за билет:
- cena() - основната цена се зголемува во зависност од времетраењето на електронскиот концерт. Ако времетраењето на концертот е подолго од 5 часа, основната цена 
се зголемува за 150 денари. Ако времетраењето е подолго од 7 часа, цената се зголемува за 360 денари. Доколку се работи за дневна забава, цената се намалува за 50, 
а доколку се работи за ноќна забава цената се зголемува за 100 денари.
Да се имплементираат следните функции:
- void najskapKoncert(Koncert ** koncerti, int n) – во која ќе се испечати називот и цената на најскапиот концерт во низата. Дополнително, да се испечати и колку 
од концертите се електронски, а колку не во формат:
[Електронски концерти: X од вкупно Y.] (10 поени)
- bool prebarajKoncert(Koncert ** koncerti, int n, char * naziv, bool elektronski) – во која ќе се прабарува концерт кој имаат ист назив како променливата naziv. 
Доколку променливата elektronski е true, треба да се пребарува само низ електронските концерти, во спротивно се пребаруваат сите концерти. Доколку е пронајден концертот, 
се печати неговиот назив и цена и функцијата враќа true. Доколку не е пронајден концертот, функцијата враќа false. Можно е да има повеќе концерти со ист назив.*/

#include<iostream>
#include<cstring>
using namespace std;

class Koncert {
    char naziv[20];
    char lokacija[20];
    static double popust;
    double bilet;
public:
    Koncert(char* naziv="", char* lokacija="", double bilet=0.0) {
        strcpy(this->naziv, naziv);
        strcpy(this->lokacija, lokacija);
        this->bilet = bilet;
    }
    virtual ~Koncert(){}
    virtual double cena() {
        double c=bilet;
        c=c-c*popust;
        return c;
    }
    static double getSezonskiPopust() {
        return popust;
    }
    static void setSezonskiPopust(double p) {
        popust = p;
    }
    char* getNaziv() {
        return naziv;
    }
};
double Koncert::popust = 0.2;
class ElektronskiKoncert : public Koncert {
    char *dj;
    double vreme;
    bool tip;
public:
    ElektronskiKoncert() : Koncert() {
        dj = nullptr;
    }
    ElektronskiKoncert(char* naziv, char* lokacija, double bilet, char* dj, double vreme, bool tip): Koncert(naziv, lokacija, bilet) {
        this->dj = new char[strlen(dj) + 1];
        strcpy(this->dj, dj);
        this->vreme = vreme;
        this->tip = tip;
    }
    ~ElektronskiKoncert() {delete[] dj;}
    double cena() override {
        double c = Koncert::cena();
        if (vreme > 7) {
            c=c+360;
        } else if (vreme > 5) {
            c=c+150;
        }
        if (tip) {
            c=c-50;
        } else {
            c=c+100;
        }
        return c;
    }
};

void najskapKoncert(Koncert** koncerti, int n) {
    Koncert* max = koncerti[0];
    int elektronski = 0;
    for (int i = 0; i < n; i++) {
        if (max->cena() < koncerti[i]->cena()) {
            max = koncerti[i];
        }
        ElektronskiKoncert* e = dynamic_cast<ElektronskiKoncert*>(koncerti[i]);
        if (e != nullptr) {
            elektronski++;
        }
    }
    cout << "Najskap koncert: " << max->getNaziv() << " " << max->cena() << endl;
    cout << "Elektronski koncerti: " << elektronski << " od vkupno " << n << endl;
}

bool prebarajKoncert(Koncert** koncerti, int n, char* naziv, bool elektronski) {
    bool koncert = false;
    for (int i = 0; i < n; i++) {
        if (elektronski) {
            ElektronskiKoncert* e = dynamic_cast<ElektronskiKoncert*>(koncerti[i]);
            if (e != nullptr) {
                if (strcmp(koncerti[i]->getNaziv(), naziv) == 0) {
                    koncert = true;
                    cout << koncerti[i]->getNaziv() << " " << koncerti[i]->cena() << endl;
                }
            }
        } else {
            if (strcmp(koncerti[i]->getNaziv(), naziv) == 0) {
                koncert = true;
                cout << koncerti[i]->getNaziv() << " " << koncerti[i]->cena() << endl;
            }
        }
    }
    return koncert;
}

int main() {
    int tip;
    cin >> tip;

    if (tip == 1) { // Koncert
        char naziv[100], lokacija[100];
        float cenaBilet;
        cin >> naziv >> lokacija >> cenaBilet;
        Koncert k1(naziv, lokacija, cenaBilet);
        cout << "Kreiran e koncert so naziv: " << k1.getNaziv() << endl;
    } else if (tip == 2) { // cena - Koncert
        char naziv[100], lokacija[100];
        float cenaBilet;
        cin >> naziv >> lokacija >> cenaBilet;
        Koncert k1(naziv, lokacija, cenaBilet);
        cout << "Osnovna cena na koncertot so naziv " << k1.getNaziv() << " e: " << k1.cena() << endl;
    } else if (tip == 3) { // ElektronskiKoncert
        char naziv[100], lokacija[100], imeDJ[40];
        float cenaBilet, casovi;
        bool dnevna;
        cin >> naziv >> lokacija >> cenaBilet >> imeDJ >> casovi >> dnevna;
        ElektronskiKoncert s(naziv, lokacija, cenaBilet, imeDJ, casovi, dnevna);
        cout << "Kreiran e elektronski koncert so naziv " << s.getNaziv() << " i sezonskiPopust " << s.getSezonskiPopust() << endl;
    } else if (tip == 4) { // cena - ElektronskiKoncert
        char naziv[100], lokacija[100], imeDJ[40];
        float cenaBilet, casovi;
        bool dnevna;
        cin >> naziv >> lokacija >> cenaBilet >> imeDJ >> casovi >> dnevna;
        ElektronskiKoncert s(naziv, lokacija, cenaBilet, imeDJ, casovi, dnevna);
        cout << "Cenata na elektronskiot koncert so naziv " << s.getNaziv() << " e: " << s.cena() << endl;
    } else if (tip == 5) { // najskapKoncert
        // Implement your input here for testing if needed
    } else if (tip == 6) { // prebarajKoncert
        Koncert* koncerti[5];
        koncerti[0] = new Koncert("Area", "BorisTrajkovski", 350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand", "Belgium", 8000, "Afrojack", 7.5, false);
        koncerti[2] = new ElektronskiKoncert("SeaDance", "Budva", 9100, "Tiesto", 5, true);
        koncerti[3] = new Koncert("Superhiks", "PlatoUkim", 100);
        koncerti[4] = new ElektronskiKoncert("CavoParadiso", "Mykonos", 8800, "Guetta", 3, true);

        najskapKoncert(koncerti, 5);
    } else if (tip == 7) { // prebaraj
        Koncert* koncerti[5];
        koncerti[0] = new Koncert("Area", "BorisTrajkovski", 350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand", "Belgium", 8000, "Afrojack", 7.5, false);
        koncerti[2] = new ElektronskiKoncert("SeaDance", "Budva", 9100, "Tiesto", 5, true);
        koncerti[3] = new Koncert("Superhiks", "PlatoUkim", 100);
        koncerti[4] = new ElektronskiKoncert("CavoParadiso", "Mykonos", 8800, "Guetta", 3, true);

        char naziv[100];
        bool elektronski;
        cin >> elektronski;
        if (prebarajKoncert(koncerti, 5, "Area", elektronski))
            cout << "Pronajden" << endl;
        else
            cout << "Ne e pronajden" << endl;

        if (prebarajKoncert(koncerti, 5, "Area", !elektronski))
            cout << "Pronajden" << endl;
        else
            cout << "Ne e pronajden" << endl;
    } else if (tip == 8) { // smeni cena
        Koncert* koncerti[4];
        koncerti[0] = new Koncert("Area", "BorisTrajkovski", 350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand", "Belgium", 8000, "Afrojack", 7.5, false);
        koncerti[2] = new ElektronskiKoncert("SeaDance", "Budva", 9100, "Tiesto", 5, true);
        koncerti[3] = new Koncert("Superhiks", "PlatoUkim", 100);

        Koncert::setSezonskiPopust(0.9);
        najskapKoncert(koncerti, 4);
    }

    return 0;
}
