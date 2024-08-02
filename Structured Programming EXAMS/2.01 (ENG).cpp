/*From SI read N strings not longer than 80 chars. At the beginning of the program read two integers:
    N - number of strings you are going to read
    X - shifting size.
Each of the read strings should be transformed in such a way that lowercase and uppercase letters (a-z, A-Z) are replaced with the same letter shifted X places
afterwards in the alphabet (a-z). If you overflow the range of alphabet, continue cyclic from the beginning of the alphabet. Transformed string should be printed on SO.
Transformation of a string should be implemented in a separate recursive function.
Example:
Welcome -> transformed with shift 5 -> Bjqhtrj*/

#include <iostream>
using namespace std;

void transformString(char *str, int shift, int index = 0) {
    char &ch = str[index];
    if (str[index] == '\0') {
        return;
    }
    if (isalpha(ch)) {
        char base;
        if (islower(ch)) {
            base = 'a';
        } else {
            base = 'A';
        }
        int offset = (ch - base + shift) % 26;
        if (offset < 0) {
            offset += 26;
        }
        ch = base + offset;
    }
    transformString(str, shift, index + 1);
}

int main() {
    int n, x;
    cin >> n >> x;
    cin.ignore();
    char line[100];
    for (int i = 0; i < n; i++) {
        cin.getline(line, 100);
        transformString(line, x);
        cout << line << endl;
    }
    return 0;
}
