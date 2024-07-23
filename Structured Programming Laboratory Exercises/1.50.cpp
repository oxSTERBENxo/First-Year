/*Да се напише код којшто ќе и помогне на една продавница во пресметките на попустите на одредени артикли.
Попустите се означуваат со различна буква и тоа 
А == 20%; B == 50%; C == 70%; D == 0% nema popust
Од стандарден влез најпрвин се чита број на артикли кои сака купувачот да ги купи, а потоа како парови се внесуваат цената и видот на попуст за секој од посакуваните артикли.
Да се испечати колку ќе биде сумата што купувачот ќе треба да ја плати вклучувајќи го попустот за секој од артиклите соодветно.  Исто така во нов ред да се испечати 
и колку изнесува попустот на купувачот во денари односно колку денари заштедил.*/

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    double total = 0.0;
    double totalDiscount = 0.0;

    for (int i = 1; i <= n; i++) {
        double price;
        char type;
        cin >> price >> type;

        double discountAmount = 0.0;
        switch (type) {
            case 'A':
                discountAmount = price * 0.2;
                break;
            case 'B':
                discountAmount = price * 0.5;
                break;
            case 'C':
                discountAmount = price * 0.7;
                break;
            case 'D':
                discountAmount = 0.0;
                break;
        }
        total += price - discountAmount;
        totalDiscount += discountAmount;
    }
    cout << total << endl;
    cout << totalDiscount << endl;
    return 0;
}
