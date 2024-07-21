/*Да се напише програма во која се внесуваат три броеви. Да се отпечати 1 доколку средниот број е истовремено поголем од двата останати броеви,
или пак е истовремено помал. Во спротивно да се отпечати 0.*/

#include <iostream>
using namespace std;

int main() {
    int broj1, broj2, broj3;
    cin >> broj1 >> broj2 >> broj3;
    if ((broj2 > broj1 && broj2 > broj3) || (broj2 < broj1 && broj2 < broj3)) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }
    return 0;
}
