/*Да се напише програма во која се внесуваат три цели броеви. Доколку внесените броеви се во растечки редослед да се испечати 1, a доколку се во опаѓачки редослед 
да се испечати -1, во спротивно да се испечати 0.*/

#include <iostream>
using namespace std;

int main() {
    int broj1, broj2, broj3;
    cin >> broj1 >> broj2 >> broj3;
    if (broj1 < broj2 && broj2 < broj3) {
        cout << "1" << endl;
    } else if (broj1 > broj2 && broj2 > broj3) {
        cout << "-1" << endl;
    } else {
        cout << "0" << endl;
    }
    return 0;
}
