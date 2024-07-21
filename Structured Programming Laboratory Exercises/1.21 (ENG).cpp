/*Игор сака да направи овошна салата. За таа цел оди во маркет каде цените се следните:
Цената на 100 грама јаболка е 30 денари, 
цената на 100 грама малини е 50 денари и  
цената на 100 грама банани е 40 денари. 
Доколку купи 200 грама од еден вид на овошје (јаболка/малини/банани) добива 30% попуст, а доколку купи 500 грама или повеќе исто така од еден вид на овошје добива 50% попуст.
(пример. ќе добие попуст ако купи 500 грама само малини не вкупно 500грама од сите овошја)
Дополнително: Исто така при наплата проверуваме дали Игор сака да искористи 140 денари од својот дневен студентски оброк. 
Доколку ДА 140 денари се одземаат од целокупната сума, во спротивно сумата останува непроменета. Колку денари ќе треба да доплати Игор?
Појаснување за влезните параметри: имаме колку грама сака да купи од секое овошје соодветно според редоследот јаболка, малини, банани и 1 или 0 во зависност дали сака да
плати 140ден со својата студентска картичка или не.

Igor wants to make a fruit salad. To do that, he goes to the market where the prices are as follows:
The price of 100 grams of apples is 30 denars,
the price of 100 grams of raspberries is 50 denars, and
the price of 100 grams of bananas is 40 denars.
If he buys 200 grams of one type of fruit (apples/raspberries/bananas), he gets a 30% discount, and if he buys 500 grams or more of one type of fruit, he gets a 50% discount.
(Example: He will get a discount if he buys 500 grams of just raspberries, not a total of 500 grams from all fruits)
Additionally: When paying, we check if Igor wants to use 140 denars from his daily student meal card.
If YES, 140 denars are subtracted from the total amount; otherwise, the amount remains unchanged. How much money does Igor need to pay extra?
Explanation of input parameters: We have how many grams he wants to buy of each fruit, respectively in the order apples, raspberries, bananas, and 1 or 0 depending on 
whether he wants to pay 140 denars with his student card or not.*/

#include <iostream>
using namespace std;

int main() {
    int applesPrice = 30, raspPrice = 50, bananaPrice = 40;
    int applesGrams, raspGrams, bananaGrams;
    bool studentCard;

    cin >> applesGrams >> raspGrams >> bananaGrams;
    cin >> studentCard;

    int applesTotalCost = (applesGrams * applesPrice) / 100;
    int raspTotalCost = (raspGrams * raspPrice) / 100;
    int bananasTotalCost = (bananaGrams * bananaPrice) / 100;

    if (applesGrams >= 500) {
        applesTotalCost *= 0.5;
    } else if (applesGrams == 200) {
        applesTotalCost *= 0.7;
    }
    if (raspGrams >= 500) {
        raspTotalCost *= 0.5;
    } else if (raspGrams == 200) {
        raspTotalCost *= 0.7;
    }
    if (bananaGrams >= 500) {
        bananasTotalCost *= 0.5;
    } else if (bananaGrams == 200) {
        bananasTotalCost *= 0.7;
    }

    int total = applesTotalCost + raspTotalCost + bananasTotalCost;
    
    if (studentCard == 1) {
        total -= 140;
    }
    cout << total << endl;
    return 0;
}
