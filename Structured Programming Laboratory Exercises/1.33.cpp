/*Од стандарден влез се читаат два телефонски броја и времетраење на разговорот во минути.
Да се пресмета цената на повикот доколку знаеме дека првите 30 минути чинат 3 ден/мин, а после тие 30 мин цената на 1 минута е 2ден.
Дополнително доколку двата телефонски броја се на ист оператор да се пресмета 30% попуст.

оператор1 ги користи (071, 072, 073)
оператор2 ги користи (074, 075, 076)*/

#include <iostream>
using namespace std;

int main() {
    int number1, number2, duration;
    cin >> number1 >> number2 >> duration;
    bool sameOperator = false;
    if ((number1 >= 71000000 && number1 <= 73999999) && (number2 >= 71000000 && number2 <= 73999999)) {
        sameOperator = true;
    }
    if ((number1 >= 74000000 && number1 <= 76999999) && (number2 >= 74000000 && number2 <= 76999999)) {
        sameOperator = true;
    }
    double callCost, discount = 0.0;
    if (duration <= 30) {
        callCost = duration * 3.0;
    } else {
        callCost = 30 * 3.0 + (duration - 30) * 2.0;
    }
    if (sameOperator) {
        discount = callCost * 0.3;
    }
    double totalCost = callCost - discount;
    cout << totalCost << endl;
    return 0;
}
