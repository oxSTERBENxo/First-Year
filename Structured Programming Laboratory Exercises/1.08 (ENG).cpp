/*Да се напише програма која вчитува од стандарден влез должина на катетите (цели броеви) на еден триаголник.
Ваша задача е да ги пресметате и испечатите квадратот на хипотенузата и плоштината на триаголникот.

Write a program that gets from standard input the length of the legs of a triangle.
Your task is to calculate and print the square of the hypotenuse and the area of the triangle.*/

#include <iostream>
#include <cmath> 
using namespace std;

int main() {
    int a,b;
    double c; 
    cin >> a >> b;
    c = sqrt(a*a + b*b);
    double squareOfHypotenuse = c*c;
    double area = a*b/2.0;
    cout<<squareOfHypotenuse<<endl;
    cout<<area<<endl;
    return 0;
}
