/*Using the characters + and - form a square image with "width" n (n > 2) that represent square of the chars -, enclosed by a square of chars + (view examples). 
For given n, print the appropriate image. Attention: do not print additional characters as empty spaces, or unnecessary new line... The image ends with new line char. 
Do not use any matrix or arrays because n is not limited.*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << '+';
    }
    cout << endl;
    for (int i = 0; i < n - 2; i++) {
        cout << '+';
        for (int j = 0; j < n - 2; j++) {
            cout << '-';
        }
        cout << '+' << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << '+';
    }
    cout << endl;
    return 0;
}
