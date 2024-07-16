/*Read from SI one integer n. From the integers smaller than n, find the one with maximum sum of divisors. Do not count the number itself in the sum of divisors.*/

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n <= 1) {
        cout << "Invalid input. n must be greater than 1." << endl;
        return 0;
    }
    int maxSumDivisors = 0, numberWithMaxSumDivisors = 1;
    for (int i = 1; i < n; i++) {
        int sumDivisors = 0;
        for (int j = 1; j <= i / 2; j++) {
            if (i % j == 0) {
                sumDivisors += j;
            }
        }
        if (sumDivisors > maxSumDivisors) {
            maxSumDivisors = sumDivisors;
            numberWithMaxSumDivisors = i;
        }
    }
    cout << numberWithMaxSumDivisors << endl;
    return 0;
}
