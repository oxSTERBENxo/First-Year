/*Да се напише програма која за петцифрен број внесен од стандарден влез ќе ја пресмета сумата на цифрите на парните и непарните позиции соодветно.
Напомена: Последната цифра во бројот се наоѓа на 0-та позиција. 
Појаснување: За бројот 54321 цифрата на 0-та позиција е 1, додека цифрата на 4-та позиција е 5.*/

#include <iostream>
using namespace std;

int main() {
    int n, cifra, parniPoz = 0, neparniPoz = 0;
    cin >> n;
    for (int i = 0; i < 5; i++) {
        cifra = n % 10;
        n /= 10;
        if (i % 2 == 0) {
            neparniPoz += cifra;
        } else {
            parniPoz += cifra;
        }
    }
    cout << "Sumata na cifrite na parnite pozicii e " << neparniPoz << endl;
    cout << "Sumata na cifrite na neparnite pozicii e " << parniPoz << endl;
    return 0;
}
