/*Од стандарден влез се вчитува цел број N. Потоа се внесува низа од N цели броеви. Напиши програма која ќе ги трансформира елементите на низата на следниот начин: 
Секој парен елемент, зголеми го за 3, а секој непарен елемент кој е деллив со 5, одземи го за 2. На крај, испечати ја трансформираната низа.
-------------------------------------------------------------------------------------------------------------------------------------------------------------
An integer N is read from SI. Then an array of N integers is read. Write a program that will transform the elements of the array as follows: 
If the element is an even number, increase it by 3, and if it is an odd number divisible by 5, subtract it by 2. Print the transformed array.*/

#include <iostream>
using namespace std;

int main() {
    int n, niza[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> niza[i];
    }
    for (int i = 0; i < n; i++) {
        if (niza[i] % 2 == 0) { 
            niza[i] += 3;
        } else if (niza[i] % 5 == 0) { 
            niza[i] -= 2;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << niza[i];
        if (i < n - 1) {
            cout << " "; 
        }
    }
    cout << endl;
    return 0;
}
