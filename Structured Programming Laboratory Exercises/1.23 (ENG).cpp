/*Да се напише програма каде од стандарден влез се внесува еден 5 цифрен број. Програмата печати 1 доколку бројот е специјален, а 0 во спротивно.
Еден број е специјален доколку за него важи дека е делив со збирот на својата втора и трета цифра и првата,третата и петтата цифра се во строго растечки редослед.
Да се внимава на делење со 0, т.е. да се испечати -1 во таков случај.

Write a program where a 5-digit number is entered from standard input. The program prints 1 if the number is special, and 0 otherwise.
A number is considered special if it is divisible by the sum of its second and third digits, and the first, third, and fifth digits are in a strictly ascending order.
Be careful about division by 0, print -1 in such a case.*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int digit1 = n / 10000;
    int digit2 = (n / 1000) % 10;
    int digit3 = (n / 100) % 10;
    int digit5 = n % 10;
    if (digit2 + digit3 == 0) {
        cout << "-1" << endl;
        return 0;
    }
    bool special = (n % (digit2 + digit3) == 0) && (digit1 < digit3 && digit3 < digit5);
    if (special) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }
    return 0;
}
