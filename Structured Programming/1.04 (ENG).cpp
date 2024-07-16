/*From SI are read N pairs of integers, where the first number is the students' points, and the second is the max. points. Write a program where for each pair 
(points, max points), will print the students success in percentage and his grade following these rules:
if the student has 90% or more - "10".
if the student has 80% or more - "9".
if the student has 70% or more - "8".
if the student has 60% or more - "7".
if the student has 50% or more - "6".
If the student has less than 50% print "FAIL".
*/

#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int points, maxPoints;
        cin >> points >> maxPoints;
        double percentage = (points * 100.0) / maxPoints;
        int grade=0;
        if (percentage >= 90.0) {
            grade = 10;
            cout << percentage << " " << grade << endl;
        } else if (percentage >= 80.0) {
            grade = 9;
            cout << percentage << " " << grade << endl;
        } else if (percentage >= 70.0) {
            grade = 8;
            cout << percentage << " " << grade << endl;
        } else if (percentage >= 60.0) {
            grade = 7;
            cout << percentage << " " << grade << endl;
        } else if (percentage >= 50.0) {
            grade = 6;
            cout << percentage << " " << grade << endl;
        } else if(percentage<50){
            cout<<percentage<<" "<<"FAIL"<<endl;
        }

    }

    return 0;
}
