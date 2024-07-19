/*Read an integer k from SI, followed by lines of characters. Print on SO the read lines transformed in such a way that all the vowels in the line 
will be repeated k times. */

#include <iostream>
#include <cstring>
using namespace std;

bool isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return true;
    } else {
        return false;
    }
}

void transformAndPrintLine(const char* line, int n) {
    char result[1000];
    int idx = 0,len = strlen(line);
    for (int i = 0; i < len; i++) {
        char c = line[i];
        if (isVowel(c)) {
            for (int j = 0; j < n; j++) {
                result[idx++] = c;
            }
        } else {
            result[idx++] = c;
        }
    }
    result[idx] = '\0';
    cout << result << endl;
}

int main() {
    int n;
    char line[1000];
    cin >> n;
    cin.ignore();
    while (cin.getline(line, 1000)) {
        transformAndPrintLine(line, n);
    }
    return 0;
}
