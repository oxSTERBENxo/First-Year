/*Да се напише програма што ќе ја испечати сумата на квадратите на сите парни броеви во интервалот [A,B). А и B се внесуваат од тастатура.*/

#include <iostream>
using namespace std;

int main() {
    int A, B, sum=0;
    cin >> A >> B;
    for (int i = A; i < B; i++) {
        if (i % 2 == 0) {
            sum += i * i;
        }
    }
    cout << "The sum is: " << sum << endl;
    return 0;
}
