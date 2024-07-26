/*Сакаме да ги истражиме цените на одредени производи во продавница и да видиме кои од нив се над просечната цена, а кои се под просечната цена. 
За да го постигнеме ова, влезот е N, бројот на производите, и потоа N производи, претставувајќи ја нивната цена. Вашата задача е да го пресметате просекот на сите производи,
а потоа да ги замените оние кои се под просекот со вредност 0 и оние над просекот (или еднакви) со вредност 1.
На излез испечатете ја просечната цена, како и трансформираната низата (види тест примери)
------------------------------------------------------------------------------------------
You are tasked with analyzing product prices in a store to identify those above and below the average price. 
The input consists of an integer N, representing the number of products, followed by N prices (of those products). 
Your goal is to compute the average price of all products and then replace prices below the average with 0 and prices above the average (or equal) with 1.
Print the average price as well as the transformed array (check test cases)*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    double prices[n],sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
        sum += prices[i]; 
    }
    double average = sum / n;
    cout<<"Average price: "<<average<<endl;
    for (int i = 0; i < n; i++) {
        if (prices[i] < average) {
            cout<<0<<" ";
        } else {
            cout<<1<<" ";
        }
    }
    cout << endl;
    return 0;
}
