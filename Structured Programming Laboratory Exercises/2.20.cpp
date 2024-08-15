/*Oд стандарден влез се читаат броеви се додека не се прочита нешто што не е број. За сите броеви кои што се палиндроми на екран да се испечати сума на цифри од кои што 
е составен бројот, за броевите кои што не се палиндроми потребно е на екран да се испечати од колку цифри е составен бројот. Проверка дали бројот е палиндром, колкава е
сумата на цифри или од колку цифри е составен бројот да се реализираат со посебни функции.
Дополнително функцијата за броење на цифри на број направете ја рекурзивна.*/

#include <iostream>
using namespace std;

bool isPalindrome(int n) {
    int original = n, reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return (original == reversed);
}
int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int countDigits(int n) {
    if (n == 0) {
        return 1;
    }
    if (n < 10) {
        return 1; 
    } else {
        return 1 + countDigits(n / 10); 
    }
}

int charArrayToInt(const char *charArr) {
    int n = 0;
    while (*charArr) {
        n = n * 10 + (*charArr - '0');
        charArr++;
    }
    return n;
}

int main() {
    char arr[100];
    while (true) {
        cin >> arr;
        bool isValidNumber = true;
        for (int i = 0; arr[i] != '\0'; ++i) {
            if (arr[i] < '0' || arr[i] > '9') {
                isValidNumber = false;
                break;
            }
        }
        if (!isValidNumber) {
            break;
        }
        int n = charArrayToInt(arr);
        if (isPalindrome(n)) {
            cout << sumOfDigits(n) << endl;
        } else {
            cout << countDigits(n) << endl;
        }
    }
    return 0;
}
