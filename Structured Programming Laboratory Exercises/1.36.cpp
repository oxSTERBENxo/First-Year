/*Да се напише програма која што за вчитан датум како влезна променлива ( DD MM GGGG) ќе испечати на  излез порака 1 или 0 во зависност од тоа дали внесениот датум
е правилен или не. Напомена: За проверка на валидноста на датумот разгледајте ги следниве потточки:
- за датумот 29.02. да се внимава дали станува збор за престапна година (престапна година е секоја година која што е делива со 400 или пак е делива со 4, но не и со 100)
- дали месецот е број помеѓу 1 и 12
- дали денот одговара со бројот на денови во тој месец*/

#include <iostream>
using namespace std;

int main() {
    int day, month, year;
    cin >> day >> month >> year;
    bool isValid = true;
    if (month < 1 || month > 12) {
        isValid = false;
    }
    else {
        int daysInMonth;
        if (month == 1 || month == 3 || month == 5 || month == 7 ||
            month == 8 || month == 10 || month == 12) {
            daysInMonth = 31;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            daysInMonth = 30;
        }
        else { 
            if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
                daysInMonth = 29;
            }
            else {
                daysInMonth = 28;
            }
        }
        if (day < 1 || day > daysInMonth) {
            isValid = false;
        }
    }
    if (isValid) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}
