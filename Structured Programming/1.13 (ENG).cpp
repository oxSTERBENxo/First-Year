/*Sweet number is number that contains only even digits (0, 2, 4, 6, 8). In given range (m and n read from SI) find the smallest "sweet number". 
If there is no such number, print NSN.*/

#include <iostream>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    bool foundSweetNumber = false;
    int sweetNumber = -1;
    for (int num = m; num <= n; ++num) {
        int temp = num;
        bool isSweet = true;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit % 2 != 0) {
                isSweet = false;
                break;
            }
            temp /= 10;
        }
        if (isSweet) {
            foundSweetNumber = true;
            sweetNumber = num;
            break; 
        }
    }
    if (foundSweetNumber) {
        cout << sweetNumber << endl;
    } else {
        cout << "NSN" << endl;
    }
    return 0;
}
