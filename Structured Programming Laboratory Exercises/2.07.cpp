/*Се чита низа од n цели броеви. Провери дали низата е специјална. Ако од сите броеви на парни позиции 50% или повеќе се парни броеви, и од сите броеви на непарна
позиција 30% или помалку се непарни броеви, тогаш низата е специјална. Испечати 1 ако е низата специјална, испечати 0 ако не е.*/

#include <iostream>
using namespace std;

int main() {
    int n,array[100],evenCount=0,oddCount=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {  
            if (array[i] % 2 == 0) {
                evenCount++;
            }
        } else { 
            if (array[i] % 2 != 0) {
                oddCount++;
            }
        }
    }
    double procEvenPos = (double)evenCount / (n / 2) * 100;
    double procOddPos = (double)oddCount / ((n + 1) / 2) * 100;
    if (procEvenPos >= 50 && procOddPos <= 30) {
        cout << "1" << endl;  // Special array
    } else {
        cout << "0" << endl;  // Not special array
    }
    return 0;
}

