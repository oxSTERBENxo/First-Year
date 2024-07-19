/*Write a program that will read from SI array of natural numbers (not more than 100). Print all the elements of the array that represent strong numbers 
(each in new line). One number is strong if the sum of factorials of each of his digits is equal to the number itself. Example, number 145 is strong because:
145 = 1! + 4! + 5!
If a number is strong should be checked in a separate function, and for computing factorial a separate recursive function should be implemented and used.*/


#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

bool isStrongNumber(int num) {
    int originalNum = num;
    int sum = 0;

    while (num > 0) {
        int digit = num % 10;
        sum += factorial(digit);
        num /= 10;
    }
    return (sum == originalNum);
}

int main() {
    int n,numbers[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    cout<<"Strong numbers:"<<endl;
    for (int i = 0; i < n; i++) {
        if (isStrongNumber(numbers[i])) {
            cout << numbers[i] << endl;
        }
    }
    return 0;
}
