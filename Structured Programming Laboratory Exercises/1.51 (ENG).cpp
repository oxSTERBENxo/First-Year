/*Да се напише програма во C++ за пресметка на Најголем Заеднички Делител (НЗД) и Најмал Заеднички Содржател (НЗС) на два броја.
НЗД е најголемиот позитивен цел број што ги дели двата броја без остаток. НЗС на два броја M и N претставува најмалиот цел позитивен број кој е делив и со M и со N.
---------------------------------------------------------------------------------------------------------------------------------
Write a program in C++ to find the Greatest Common Divisor (GCD)  and  Least Common Multiple (LCM) of two numbers.
GCD is the largest positive integer that divides both numbers without leaving a remainder. LCM of two numbers M and N is the smallest positive integer that is 
divisible by both M and N.*/

#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    cin >> num1 >> num2;
    
    int a = num1, b = num2;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int nzd = a;

    int nzs = (num1 * num2) / nzd;
    
    cout << "The LCM of " << num1 << " and " << num2 << " is " << nzs << endl;
    cout << "The GCD of " << num1 << " and " << num2 << " is " << nzd << endl;

    return 0;
}
