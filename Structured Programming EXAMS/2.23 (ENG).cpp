/*N positive integers are entered from the standard input and stored in an array a (N <100)**. Also, a single-digit 
integer **k** is entered. Write a function that will find the maximum of the abbreviated numbers of the elements in 
the array **a** and provide a call to that function in the main () function. A given element of the array is 
abbreviated as follows: all digits smaller than or equal to **k are deleted from the number.
For example: If k = 3 and a[0] = 12345, then abbreviated a[0] becomes 45, if a[1] = 458763, a[1] becomes 45876, 
and a[2] = 112 is shortened to a[2] = 0. The maximum abbreviated number is 45876.*/

#include <iostream>
using namespace std;
int maxAbbreviatedNum(int arr[], int n, int k) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        int abbreviatedNum = 0, mult = 1, num = arr[i];
        while (num > 0) {
            int digit = num % 10;
            num /= 10;
            if (digit > k) {
                abbreviatedNum += digit * mult;
                mult *= 10;
            }
        }
        if (abbreviatedNum > max) {
            max = abbreviatedNum;
        }
    }
    return max;
}

int main() {
    int n, k ,arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;
    int result = maxAbbreviatedNum(arr, n, k);
    cout << result << endl;
    return 0;
}
