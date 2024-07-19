/*Цик-цак е број за кој што важи дека за секој пар соседни цифри, тие се наизменично поголеми односно помали една во однос на друга. 
На пример, ако бројотx е составен од цифрите a, b, c, d и е, тогаш за нив важи:
a>b, b<c, c>d, d<e или a<b, b>c, c<d, d>e
Пр. 343, 4624, 6231209
Од тастатура се читаат непознат број цели броеви поголеми од или еднакви на 10 (броевите помали од 10 се игнорираат). 
Читањето завршува во моментот кога ќе се прочита знак што не е цифра. Да се испечатат сите цик-цак броеви.*/


#include <iostream>
using namespace std;

int main() {
    int a, tmp, counter;
    while (cin >> a) {
        if (a < 10) continue;
        tmp = a;
        counter = 0;
        
        while (tmp) {
            tmp /= 10;
            counter++;
        }
        
        if (a % 10 > (a % 100) / 10) {
            tmp = a;
            while (tmp >= 10) {
                if (tmp % 10 > (tmp % 100) / 10) {
                    counter--;
                } else break;
                tmp /= 100;
            }
            
            tmp = a / 10;
            while (tmp >= 10) {
                if (tmp % 10 < (tmp % 100) / 10) {
                    counter--;
                } else break;
                tmp /= 100;
            }
        } else {
            tmp = a;
            while (tmp >= 10) {
                if (tmp % 10 < (tmp % 100) / 10) {
                    counter--;
                } else break;
                tmp /= 100;
            }
            
            tmp = a / 10;
            while (tmp >= 10) {
                if (tmp % 10 > (tmp % 100) / 10) {
                    counter--;
                } else break;
                tmp /= 100;
            }
        }
        
        if (counter == 1){
            cout << a << endl;
        }
    }
    
    return 0;
}
