/*Дадени се еден четирицифрен и еден трицифрен број. Да се пресмета аритметичка средина на броевите кои се наоѓаат на парните позииции на трицифрениот број и на 
непарните позиции на четирицифрениот број. Напомена: Под парни позиции се смета и нултата позиција. 
пр. за бројот 2468 на нулта позиција е бројот 2, на прва позиција е бр 4, на втора бр 6 и на трета бр 8.

One four-digit number and one three-digit number are given. Calculate the arithmetic mean of the numbers that are in the even positions of the three-digit number and
in the odd positions of the four-digit number. Note: Under even positions, the zero position is also considered.
e.g. for the number 2468, the zero position is the number 2, the first position is the number 4, the second is the number 6 and the third is the number 8.*/

#include <iostream>
using namespace std;

int main() {
    int fourDigNum, threeDigNum;
    cin >> threeDigNum >> fourDigNum;

    int d1 = (fourDigNum / 100) % 10;
    int d3 = fourDigNum % 10;

    int d0 = (threeDigNum / 100) % 10;
    int d2 = threeDigNum % 10;

    int evenDigits = d0 + d2;
    int oddDigits = d1 + d3;

    double AS = (evenDigits + oddDigits) / 4.0;

    cout << AS << endl;

    return 0;
}
