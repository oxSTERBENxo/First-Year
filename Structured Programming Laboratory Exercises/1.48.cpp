/*Напишете програма која чита два природни броја, почеток и крај, од стандардниот влез. Потоа програмата треба да ги пронајде и отпечати палиндромите 
во опсегот [почеток, крај]. Палиндром се дефинира како број што останува ист и кога неговите цифри се во обратен редослед.
Ваша задача е да ги најдете најмалите и најголемите палиндроми во дадениот опсег. */

#include <iostream>
using namespace std;

int main() {
    int start, end;
    cin >> start >> end;
    int minPalindrome = -1, maxPalindrome = -1;
    bool foundMin = false, foundMax = false;

    for (int i = start; i <= end; i++) {
        int originalNum = i;
        int reversedNum = 0;
        while (originalNum > 0) {
            reversedNum = reversedNum * 10 + originalNum % 10;
            originalNum /= 10;
        }

        if (i == reversedNum) {
            if (!foundMin || i < minPalindrome) {
                minPalindrome = i;
                foundMin = true;
            }
            if (!foundMax || i > maxPalindrome) {
                maxPalindrome = i;
                foundMax = true;
            }
        }
    }
    if (foundMin && foundMax) {
        cout << "Smallest Palindromic Number: " << minPalindrome << endl;
        cout << "Largest Palindromic Number: " << maxPalindrome << endl;
    } 
    return 0;
}
