/*Да се напише програма со која корисникот на влез треба да внесе три позитивни броја, а на излез треба да се отпечати кој од броевите има најмала вредност. 
Доколку сите три броја имаат иста вредност треба да се отпечати порака дека станува збор за три исти броја.  */

#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int smallest = a;
    if (b < a) {
        smallest = b;
    }
    if (c < a) {
        smallest = c;
    }
    if (a == b && b == c) {
        cout<<"Site tri broja imaat ista vrednost"<<endl;
    } else {
        cout<<"Najmala vrednost ima brojot "<<smallest<<endl;
    }
    return 0;
}
