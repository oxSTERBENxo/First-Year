/*Од стандарден влез се чита ливче во спортска обложувалница.
Во првиот ред е запишана сумата на уплата (цел број).
Потоа во секој нареден ред кој се чита од стандарден влез (се додека не се прочита знакот #) е запишан по еден тип во следниот формат:
ab12 1 1.25
Првиот број е шифрата на типот (низа од знаци која не е подолга од 9 знаци), вториот број е типот (може да биде 1, 0 или 2) додека третиот број е коефициентот (реален број).
Ваша задача е да го испечатите типот со најголем коефициент како и можната добивка на ливчето. Доколку има повеќе типови со ист максимален коефициент, да се испечати првиот.
Можната добивка се пресметува како производ на сите коефициенти со сумата на уплата.*/



#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char max_shifra[10];
    int max_tip;
    float max_koef = -1;
    float proizvod = 1.0;
    int uplata;
    
    cin >> uplata;
    cin.ignore();  

    char shifra[10];
    while (cin>>shifra) {
        if (shifra[0] == '#') {
            break;
        }
        if(shifra[0]=='\0'){
            continue;
        }

        int tip;
        float koef;

        cin >> tip;
        cin >> koef;
        cin.ignore(); 
        
        proizvod=proizvod*koef;
        
        if (koef > max_koef) {
            strcpy(max_shifra, shifra);
            max_koef = koef;
            max_tip = tip;
        }
    }

    cout << max_shifra << " " << max_tip << " " << max_koef << endl;
    cout << proizvod * uplata;
    return 0;
}
