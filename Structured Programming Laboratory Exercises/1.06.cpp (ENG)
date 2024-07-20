/*Да се напише програма која од стандарден влез чита цел број(денови). На излез да се отпечати колку години, месеци и денови се тоа.
Претпоставуваме дека сите месеци имаат 30 дена и секоја година има 365 дена.

Write a program that reads an integer (days) from standard input. You will need to calculate how many years, months and days it is.
We assume that all months have 30 days and each year has 365 days.*/

#include <iostream>
using namespace std;

int main() {
    int days;
    cin >> days;
    int years = days / 365;
    int remainingDays = days % 365; 
    int months = remainingDays / 30;
    int remainingDays2 = remainingDays % 30;
    cout << "Years: " << years << ", months: " << months << ", days: " << remainingDays2 << endl;
    return 0;
}
