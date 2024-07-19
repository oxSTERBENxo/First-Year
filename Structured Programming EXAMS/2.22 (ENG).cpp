/*Write a fully recursive function triangle (n) which given the input argument n, prints a triangle from the numbers from 1 to n. Additional functions
can be used, but no loops should be used.

Example for n=4.

    1
    12
    123
    1234*/

#include <iostream>
using namespace std;
void printNumbers(int start, int end) {
    if (start > end) {
        return;
    }
    cout << start;
    printNumbers(start + 1, end);
}
void triangle(int n) {
    if (n <= 0) {
        return;
    }
    triangle(n - 1);
    printNumbers(1, n);
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    triangle(n);
    return 0;
}
