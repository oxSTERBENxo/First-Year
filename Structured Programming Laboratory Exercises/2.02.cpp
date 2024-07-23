/*Да се напише програма со која ќе се печатат најмалите k елементи од низата. Низата и бројот на најмалите елементи се внесуваат преку тастатура.*/
//test case as an example
/*  input:                       output:
    7 4                          4-te najmali elementi se: 5 12 16 20
    16 12 5 49 48 47 20
*/

#include <iostream>
using namespace std;

int main() {
    int n, k, arr[100];
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < k; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
    cout<<k<<"-te najmali elementi se: ";
    for (int i = 0; i < k; ++i) {
        cout << arr[i]<<" ";
    }
    cout << endl;
    return 0;
}
