/*Напишете C++ програма со која ќе пресметате просек на оцените на даден студент.
На влез се вчитуваат пет цели броеви претставувајќи ги оцените на студентот во еден семестар.
Напомена: просекот да се претстави како float*/

#include <iostream>
using namespace std;

int main() {
    int grade1, grade2, grade3, grade4, grade5;
    cin >> grade1 >> grade2 >> grade3 >> grade4 >> grade5;
    float sum = grade1 + grade2 + grade3 + grade4 + grade5;
    float average = sum / 5;
    cout << "Average grade: "<<average << endl;
    return 0;
}
