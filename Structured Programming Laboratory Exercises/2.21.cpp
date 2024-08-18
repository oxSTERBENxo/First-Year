/*Од стандарден влез се внесуваат број на елементи на низа и самата низа. Ваша задача е да најдете најголем и најмал елемент на низата, 
како и да ја трансформирате низата така што секој елемент ќе се зголеми за разликата помеѓу најголемиот и најмалиот елемент и на крајот да ги испечатите најголемиот,
најмалиот елемент и трансформираната низата.*/

#include <iostream>
using namespace std;

int main() {
    int n, niza[100];
    cin >> n;
    cin >> niza[0];
    int max = niza[0], min = niza[0], diff;
    for (int i = 1; i < n; i++) {
        cin >> niza[i];
        if (niza[i] > max) {
            max = niza[i];
        }
        if (niza[i] < min) {
            min = niza[i];
        }
    }
    diff = max - min;
    for (int i = 0; i < n; i++) {
        niza[i] += diff;
    }
    cout << "MAX -> " << max << endl;
    cout << "MIN -> " << min << endl;
    for (int i = 0; i < n; i++) {
        cout << niza[i]<<" ";
    }
    cout << endl;
    return 0;
}
