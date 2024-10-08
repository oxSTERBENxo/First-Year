/*Од стандарден влез се читаат непознат број на хексадецимални цифри се додека не се внесе точка (.). 
Ваша задача е да го пресметате декадниот збир на внесените хексадецимални цифри. Доколку добиениот декаден збир е делив со 16 се печати Pogodok.
Доколку истиот тој збир покрај што е делив со 16 плус завршува на 16 (последните цифри му се 1 и 6), се печати Poln pogodok инаку се печати самиот збир.
Пример:
влез: A 7 F 2 0 c A 5
излез: 61
(61 = 10 + 7 + 15 + 2 + 0 + 12 + 10 + 5, бројот не е делив со 16, ниту пак последните цифри му се 1,6)*/


#include <iostream>
using namespace std;
int main() {
    char x;
    int zbir = 0, broj = 0;
    while (cin >> x) {
        if (x == '.') {
            break;
        } else {
            if (x >= '0' && x <= '9') {
                zbir = zbir + (x - '0');
            }
            if (x >= 'a' && x <= 'f') {
                zbir = zbir + (x - 'a') + 10;
            }
            if (x >= 'A' && x <= 'F') {
                zbir = zbir + (x - 'A' + 10);
            }
        }
    }

    if (zbir % 16 == 0 && zbir % 100 == 16) {
        cout << "Poln pogodok";
    } else if (zbir % 16 == 0) {
        cout << "Pogodok";
    } else { cout << zbir; }
}
