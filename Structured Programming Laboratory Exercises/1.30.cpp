/*За еден студент се читаат освоени поени од 5 активности за еден предмет. Услов за еден предмет да биде положен е да се имаат над 50 освоени поени. 
Ако студентот има 0-50 поени не го положил предметот, ако има 51-60 го положил со 6, 61-70 го положил со 7, 71-80 го положил со 8, 81-90 го положил со 9 и над 90 
го положил со 10. Да се испечати оценката која ја имал студентот,неговите поени и да се испечати 1 доколку има услов да добие повисока оценка, а во спротивно 0. 
Услов за повисока оценка има само ако недостига 1 поен за добивање на повисока оценка.*/

#include <iostream>
using namespace std;

int main() {
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    int poeni = a+b+c+d+e;
    int ocena = 0;
    if (poeni >= 91) {
        ocena = 10;
    } else if (poeni >= 81) {
        ocena = 9;
    } else if (poeni >= 71) {
        ocena = 8;
    } else if (poeni >= 61) {
        ocena = 7;
    } else if (poeni >= 51) {
        ocena = 6;
    }else{
        cout<<"Predmetot ne e polozen";
        return 0;
    }
    
    cout << "Ocenka: " << ocena << ", poeni: " << poeni << endl;
    if(poeni==60 || poeni==70 || poeni==80 || poeni==90){
        cout<<"Ima uslov za povisoka ocenka"<<endl;
    }else if(poeni>90){
        return 0;
    }else{
        cout<<"Nema uslov za povisoka ocenka"<<endl;
    }
    return 0;
}
