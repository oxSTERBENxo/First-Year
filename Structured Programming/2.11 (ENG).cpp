/*Write a program that will read a string (not longer than 100 characters) containing letters and digits. The program should print on the standard output
the letters that are between the first and the second digit, left-to-right, including the bordering digits themselves. If there is only one digit in the string,
the program should print all the letters till the end of the string. If there is no digits in the string the program should print out the message "No digits".
Example:
Axvdf7dbb3bdbd88B -> 7dbb3
Isdv88mvndkv9d -> 88
vnjis9kjsnvnv -> 9kjsnvnv
dsfsrtt -> No digits*/


#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char arr[100];
    cin.getline(arr, 100);
    int firstDigitIndex = -1, secondDigitIndex = -1;
    bool foundFirstDigit = true;
    for (int i = 0; i < strlen(arr); i++) {
        if (isdigit(arr[i])) {
            if (foundFirstDigit) {
                firstDigitIndex = i;
                foundFirstDigit = false;
            } else {
                secondDigitIndex = i;
                break;
            }
        }
    }
    if (firstDigitIndex == -1) {
        cout << "No digits" << endl;
    } else if (secondDigitIndex == -1) {
        cout << &arr[firstDigitIndex] << endl;
    } else {
        arr[secondDigitIndex + 1] = '\0';
        cout << &arr[firstDigitIndex] << endl;
    }

    return 0;
}
