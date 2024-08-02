/*Read from SI unknown number of triplets of integers (three integers). The reading ends when the program can not read successfully read three integers. 
For each triplet of integers print out the two of them that have the minimum difference between them. First print the smaller one, and then the bigger integer.
If two pairs of integers in the triplet have equal difference, than print out all the integers, ordered from the smallest to the largest.
Example: if 5 1 7 is entered -> 5 - 1 = 4, 7 - 5 = 2, 7 - 1 = 6 -> 2 is the smallest difference -> 5 7 should be printed
Input:
5 1 7
10 2 18
Output:
5 7
2 10 18
*/

#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    while (cin >> a >> b >> c) {
        int min, mid, max;
        if (a <= b && a <= c) {
            min = a;
            if (b <= c) {
                mid = b;
                max = c;
            } else {
                mid = c;
                max = b;
            }
        } else if (b <= a && b <= c) {
            min = b;
            if (a <= c) {
                mid = a;
                max = c;
            } else {
                mid = c;
                max = a;
            }
        } else {
            min = c;
            if (a <= b) {
                mid = a;
                max = b;
            } else {
                mid = b;
                max = a;
            }
        }
        int diff1 = mid - min;
        int diff2 = max - mid;
        if (diff1 < diff2) {
            cout << min << " " << mid << endl;
        } else if (diff2 < diff1) {
            cout << mid << " " << max << endl;
        } else {
            cout << min << " " << mid << " " << max << endl;
        }
    }
    return 0;
}
