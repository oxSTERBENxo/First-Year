/*Од стандарден влез се чита низа на цели броеви се додека не се внесе нешто различно од цел број. Треба да се направи трансформација на низата, 
на тој начин што за секој елемент, сите елементи после него кои што се еднакви со него ќе се зголемат за разликата на позициите помеѓу двата елементи.
Пример: - Низата 5 6 10 5 3 10 10, после трансформација би била 5 6 10 8 3 13 14.*/

#include <iostream>
using namespace std;

int main() {
    int array[100], size = 0, n;
    while (cin >> n) {
        array[size++] = n;
    }
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] == array[j]) {
                array[j] += (j - i);
            }
        }
    }
    for (int i = 0; i < size; i++) {
        cout << array[i]<<" ";
    }
    cout << endl;
    return 0;
}
