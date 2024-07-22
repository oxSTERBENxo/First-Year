/*Од стандарден влез се вчитува даден број n, а потоа се вчитуваат n трицифрени броеви. Ваша задача е да го најдете најголемиот број чиј збир на неговите цифри
треба да е парен број.*/
#include <iostream>
using namespace std;

int main() {
    int n, largestNumber = -1; ;
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num >= 100 && num <= 999) {
            int digitSum = 0, tempNum = num;
            while (tempNum > 0) {
                digitSum += tempNum % 10;
                tempNum /= 10;
            }
            if (digitSum % 2 == 0) {
                
                if (num > largestNumber) {
                    largestNumber = num;
                }
            }
        }
    }
    if (largestNumber != -1) {
        cout << largestNumber << endl;
    } else {
        cout << "Nema" << endl;
    }
    return 0;
}
