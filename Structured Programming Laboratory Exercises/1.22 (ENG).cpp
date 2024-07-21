/*Да се напише програма во која се внесуваат четири броеви. Доколку збирот на првите два броја е парен број и збирот на последните два броја е непарен број,
да се испечати 1, во спротивно да се испечати 0.

Write a program in which four numbers are entered. If the sum of the first two numbers is an even number and the sum of the last two numbers is an odd number,
print 1, otherwise print 0.*/

#include <iostream>
using namespace std;

int main() {
    int num1, num2, num3, num4;
    cin >> num1 >> num2 >> num3 >> num4;
    int sum1 = num1 + num2;
    int sum2 = num3 + num4;
    if (sum1 % 2 == 0 && sum2 % 2 != 0) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }
    return 0;
}

