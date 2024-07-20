/*Да се напише програма во која корисникот внесува два цели броја. Програмата треба да ja најде нивната средна вредност. Потоа, програмата треба да го
зголеми првиот број за вредноста на таа средна вредност, а вториот број да го намали за истата вредност. На крајот, да се испечати новата разлика меѓу броевите.*/

#include <iostream>
using namespace std;

int main() {
    int broj1, broj2;
    double srednaVrednost;
    cin>>broj1>>broj2;
    srednaVrednost = (broj1 + broj2) / 2.0;
    broj1 += srednaVrednost;
    broj2 -= srednaVrednost;
    cout << "Razlikata e: " << broj1 - broj2 << endl;
    return 0;
}
