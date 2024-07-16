/*Write a program in which from the standard input you read one positive integer z, and afterwards you read one after another pairs of integers (a, b). Thereby, 
the loop should end if you read the pair (0, 0). The program should calculate how many times the integer z is equal to the sum of the pairs a and b, as well as the
percentage of the pairs (a,b) that give sum equal to z (NOTE: the pair (0,0) is not taken into account when doing calculations!).*/

#include <iostream>
using namespace std;
int main() {
    int z;
    cin >> z;
    int a, b, countZ = 0, totalCount = 0;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) {
            break;
        }
        totalCount++;
        if (a + b == z) {
            countZ++;
        }
    }
    double percentage = 0.0;
    if (totalCount > 0) {
        percentage = (double(countZ) / totalCount) * 100.0;
    }
    cout << "You entered " << countZ << " pairs of numbers that have a sum equal to " << z << endl;
    cout << "The percentage of pairs with sum " << z << " is " << percentage << "%" << endl;
    return 0;
}
