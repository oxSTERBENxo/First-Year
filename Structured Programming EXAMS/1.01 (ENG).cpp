/*From SI read characters until you read the char !. In these characters are hidden integers (smaller than 100). Write a program that will 
read all characters and print the sum of all integers hidden in the text.*/

#include <iostream>
using namespace std;
int main() {
    char ch;
    int sum = 0,num = 0;
    while (cin.get(ch) && ch != '!') {
        if (ch >= '0' && ch <= '9') {
            num = num * 10 + (ch - '0');
        } else {
            if (num < 100) {
                sum += num;
            }
            num = 0;
        }
    }
    if (num < 100) {
        sum += num;
    }
    cout<< sum << endl;
    return 0;
}


