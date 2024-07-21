/*Да се напише програма во која што се внесува еден четирицифрен и еден трицифрен број. Да се отпечати 1 доколку сумата на цифрите на првиот број е поголема 
од сумата на цифрите на вториот број, во спротивно 0. */

#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    int sum1 = (n1 / 1000) + ((n1 / 100) % 10) + ((n1 / 10) % 10) + (n1 % 10);
    int sum2 = (n2 / 100) + ((n2 / 10) % 10) + (n2 % 10);
    if (sum1 > sum2) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }
    return 0;
}

/*#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n1, n2;
    cin >> n1;
    cin >> n2;
    int sum1 = sumOfDigits(n1);
    int sum2 = sumOfDigits(n2);
    if (sum1 > sum2) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }
    return 0;
}
*/
