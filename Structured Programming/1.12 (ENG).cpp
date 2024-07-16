/*A whole number N greater then 0 is entered from the SI followed by N pairs of natural numbers greater than 10. Write a program that for every pair 
of entered numbers will check if the number obtained by moving the last digit of the first number on its first place is greater that the second number
in the pair or not. Print YES if the condition is satisfied or NO if the condition is not satisfied on the standard output in a single line for each pair of numbers.
(Example for moving the last digit of a number on its first place: 1234 -> 4123, 98700 -> 9870). If the numbers 3456 and 6210 are entered as a pair YES should be 
printed since 6345 > 6210.*/


#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int firstNum, secondNum;
        cin >> firstNum >> secondNum;
        if (firstNum < 10) {
            firstNum = firstNum;
        } else {
            int lastDigit = firstNum % 10;
            int remainingDigits = firstNum / 10;
            int temp = remainingDigits;
            int numDigits = 0;
            while (temp > 0) {
                temp /= 10;
                numDigits++;
            }
            int mult = 1;
            for (int i = 0; i < numDigits; ++i) {
                mult *= 10;
            }
            firstNum = lastDigit * mult + remainingDigits;
        }
        if (firstNum > secondNum) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
