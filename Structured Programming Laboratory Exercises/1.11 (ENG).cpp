/*Да се напише програма која чита радиус на кружница од стандарден влез. На излез да се испечати периметарот и плоштината на кружницата.
Write a program that reads the radius of a circle from standard input. Output the perimeter and area of the circle.*/

#include <iostream>
using namespace std;
int main() {
    double PI = 3.14, radius;
    cin >> radius;
    double perimeter = 2 * PI * radius;
    double area = PI * radius * radius;
    cout << "Perimetar: " << perimeter << endl;
    cout << "Plostina: " << area << endl;
    return 0;
}
