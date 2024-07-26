/*Да се напише програма која за низа од N броеви ќе проверува дали парот кој се наоѓа еден до друг е прост број.
НАПОМЕНА: низата е составена од цифри од 0 до 9*/

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false; 
    if (num == 2) return true; 
    if (num % 2 == 0) return false; 
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i += 2) {
        int num;
        if (i + 1 < n) {
            num = arr[i] * 10 + arr[i + 1];
        } else {
            num = arr[i];
        }
        if (isPrime(num)) {
            cout << "brojot " << num << " e prost" << endl;
        } else {
            cout << "brojot " << num << " NE e prost" << endl;
        }
    }
    return 0;
}

