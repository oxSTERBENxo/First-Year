/*Од тастатура се читаат два цели броеви a, b. Да се испечатат сите парни броеви кои што се деливи со 7 и сите непарни броеви кои што не се деливи со 3 во опсег (а, b]. 
Ако вакви броеви не постојат да се испечати 0, а во спротивно да се испечати колкав процент од броевите ги исполнуваат условите(односно ќе бидат испечатени).
---------------------------------------------------------------------------------------------------------------------------------------------
Read from SI two integers a and b. Write a program that will print all even numbers that are divisible by 7, and all odd numbers that are not divisible by 3 in
the range(a, b]. If such numbers don't exist, print 0, otherwise print the numbers and print the percentage of the numbers that meet the conditions.
*/

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a >= b) {
        cout << 0 << endl;
        return 0;
    }
    int countEvenDivBy7 = 0, countOddNotDivBy3 = 0;
    for (int n = a + 1; n <= b; n++) {
        if (n % 2 == 0 && n % 7 == 0) {
            cout << n << endl;
            countEvenDivBy7++;
        } else if (n % 2 != 0 && n % 3 != 0) {
            cout << n << endl;
            countOddNotDivBy3++;
        }
    }
    int totalNumbers = countEvenDivBy7 + countOddNotDivBy3;
    double percentage = 0.0;
    if (totalNumbers > 0) {
        percentage = 100.0 * totalNumbers / (b - a);
        cout << percentage << "%" << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
