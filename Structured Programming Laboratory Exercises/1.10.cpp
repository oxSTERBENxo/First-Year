/*Да се напише програма со која корисникот внесува два цели броја, а програмата ќе изврши замена на броевите, одностно првиот број ќе ја земе вредноста на вториот,
а вториот ќе ја земе вредноста на првиот. Притоа да се испечати разликата на броевите пред и после направената замена.
Упатство: за да направите замена на броевите користете привремена променлива*/

#include <iostream>
using namespace std;

int main() {
    int broj1, broj2;
    cin>>broj1>>broj2;
    cout << "Vrednosta na broj1 i broj2 pred zamena na broevite e: " << broj1 << "," << broj2;
    cout << " a razlikata: " << broj1 - broj2 << endl;
    int temp = broj1;
    broj1 = broj2;
    broj2 = temp;
    // swap(broj1,broj2);
    cout << "Vrednosta na broj1 i broj2 posle zamena na broevite e: " << broj1 << "," << broj2;
    cout << " a razlikata: " << broj1-broj2 << endl;
    return 0;
}
