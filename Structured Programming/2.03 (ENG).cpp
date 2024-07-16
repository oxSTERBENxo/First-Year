/*Let A = {a1, a2, .. a_n} is an array of integers. The size of the array n and the elements of the array are read from SI. Write a program that
will transform the array so each element of the original array is replaced with the number of appearance of the least significant digit (the right most) in
the number itself. Print the result array on the standard output. Compute the count of given digit in a number with separate recursive function.
Example:
Input: 
5
1 11 1121 111222112 22222
Output:
1 2 3 4 5
*/


#include <iostream>
using namespace std;
int countDigit(int num, int d) {
    if (num == 0) {
        return 0;
    } else {
        int lastDigit = num % 10;
        if (lastDigit == d) {
            return 1 + countDigit(num / 10, d);
        } else {
            return countDigit(num / 10, d);
        }
    }
}

int main() {
    int n, A[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        int leastSignificantDigit = A[i] % 10;
        A[i] = countDigit(A[i], leastSignificantDigit);
    }
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}



