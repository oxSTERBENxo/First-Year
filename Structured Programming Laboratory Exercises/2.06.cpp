/*Од стандарден влез да се вчита број N и потоа да се вчитаат N елементи во една низа.
Внесената низа да се трансформира на начин што парните елементи ќе се зголемат за 1, а непарните ќе се намалат за 1.
Трансформираната низа да се испечати на стандарден излез, така што елементите ќе се одвоени со празно место меѓу нив.*/

#include <iostream>
using namespace std;

int main() {
    int N, array[100];;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }
    for (int i = 0; i < N; i++) {
        if (array[i] % 2 == 0) {  
            array[i]++;
        } else {  
            array[i]--;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    return 0;
}
