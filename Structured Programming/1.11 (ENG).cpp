/*Three natural numbers А, B and C are entered from the SI. Write a program that will check if the three entered numbers can represent the 
values of the angles (in degrees) of a triangle. If the values can represent angles of a triangle print YES in the first line of the standard 
output followed by type of the triangle (RIGHT, ACUTE or OBTUSE) in the next line. If triangle is not possible with the tree given angles print NO in a single line.*/


#include <iostream>
using namespace std;
int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (A > 0 && B > 0 && C > 0 && A + B + C == 180) {
        if (A == 90 || B == 90 || C == 90) {
            cout << "YES" << endl;
            cout << "RIGHT" << endl;
        } else if (A < 90 && B < 90 && C < 90) {
            cout << "YES" << endl;
            cout << "ACUTE" << endl;
        } else {
            cout << "YES" << endl;
            cout << "OBTUSE" << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
