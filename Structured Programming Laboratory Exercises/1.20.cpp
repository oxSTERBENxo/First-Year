/*Да се напише програма во која се внесуваат три цели броеви. Да се отпечати 1 доколку сите 3 броеви се исти или доколку сите 3 броеви се различни. 
Во спротивно да се отпечати 0.*/

#include <iostream>
using namespace std;

int main() {
    int broj1, broj2, broj3;
    cin >> broj1 >> broj2 >> broj3;
    if (broj1 == broj2 && broj2 == broj3) {
        cout << "1" << endl; 
    } else if (broj1 != broj2 && broj2 != broj3 && broj1 != broj3) {
        cout << "1" << endl; 
    } else {
        cout << "0" << endl; 
    }
    return 0;
}
