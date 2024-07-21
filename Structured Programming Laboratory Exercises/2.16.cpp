/*Од стандарден влез се чита четирицифрен број. Да се испечати 1 доколку цифрите во бројот се во строго растечки редослед, во спротивно да се испечати 0.*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int digit1 = n / 1000 % 10;
    int digit2 = n / 100 % 10;
    int digit3 = n / 10 % 10;
    int digit4 = n % 10;
    if (digit1 < digit2 && digit2 < digit3 && digit3 < digit4) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }
    return 0;
}
