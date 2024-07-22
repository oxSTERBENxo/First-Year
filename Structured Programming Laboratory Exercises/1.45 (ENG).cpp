/*Од стандарден влез се внесува даден број X,  а потоа се внесуваат броеви додека не се внесе нешто различно од број. За секој од броевите да се провери дали 
неговиот број на цифри е еднаков со бројот на цифри на Х, и доколку условот е исполнет, да се испечати.

From standard input, a number X is entered, and then the numbers are entered until something other than a number is entered. For each of the entered numbers,
check if the number of digits is equal to the number of digits in X. For each of the entered number, if the condition is met, print the number.*/

#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X;
    int number;
    while (cin >> number) {
        int digitsX = 0;
        if (X == 0) {
            digitsX = 1; 
        } else {
            int tempX = X;
            while (tempX != 0) {
                tempX /= 10;
                digitsX++;
            }
        }
        int digitsNumber = 0;
        if (number == 0) {
            digitsNumber = 1; 
        } else {
            int tempNumber = number;
            while (tempNumber != 0) {
                tempNumber /= 10;
                digitsNumber++;
            }
        }
        if (digitsNumber == digitsX) {
            cout << number << endl; 
        }
    }
    return 0;
}
