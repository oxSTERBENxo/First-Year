/*Марта и нејзините 3 другарки сакаат да одат на кино и купуваат билети.
Иницијалната цена на еден билет за сите филмови е 200 денари, но 
доколку филмот е комедија се доплаќа 20 денари,
доколку филмот е акција се доплаќа 40 денари
доколку филмот е романса се доплаќа 30 денари
Освен картите кои сакаат да ги купат тие сакаат да купат и нешто за пиење и грицкање. Менито е следното:
Пијалоци:                                                        Пуканки:
Вода: 80ден                                                      големина S: 100ден
Fanta, CocaCola, Sprite: 100ден                                  големина M: 150ден
IceTea: 120ден.                                                  големина L: 200ден.
Да се пресмета која ќе биде вкупната цена што Марта и нејзините другарки ќе треба да ја платат. Дополнително доколку тие одлучат да одат во Среда и платат со нивната
VISA картичка за вредноста од 2 билети ќе добијат 4 (односно добиваат 50% попуст на купените билети без разлика за кој филм станува збор)
Објаснување за input 
вид на филм:  action
големина на пуканки:  L
број на пакувања пуканки:  2
вид на пијалок:  Fanta
број на пијалоци:  3
Кој ден ќе гледа филм:  Wednesday
VISA картичка:  1 (ДА) или 0 (НЕ)*/

#include <iostream>
using namespace std;

int main() {
    string filmType, popSize, drinkType, dayOfWeek;
    int numPop, numDrinks, useVisa;
    cin >> filmType >> popSize >> numPop >> drinkType >> numDrinks >> dayOfWeek >> useVisa;

    int ticketPrice = 200;
    if (filmType == "comedy") {
        ticketPrice += 20;
    } else if (filmType == "action") {
        ticketPrice += 40;
    } else if (filmType == "romance") {
        ticketPrice += 30;
    }

    int popPrice;
    if (popSize == "S") {
        popPrice = 100;
    } else if (popSize == "M") {
        popPrice = 150;
    } else if (popSize == "L") {
        popPrice = 200;
    }

    int drinkPrice;
    if (drinkType == "Water") {
        drinkPrice = 80;
    } else if (drinkType == "Fanta" || drinkType == "CocaCola" || drinkType == "Sprite") {
        drinkPrice = 100;
    } else if (drinkType == "IceTea") {
        drinkPrice = 120;
    }

    int totalPop = numPop * popPrice;
    int totalDrinks = numDrinks * drinkPrice;

    int totalTicket = ticketPrice * 4;
    if (useVisa == 1 && dayOfWeek == "Wednesday") {
        totalTicket /= 2;
    }

    int total = totalTicket + totalPop + totalDrinks;
    cout << total << endl;
    return 0;
}
