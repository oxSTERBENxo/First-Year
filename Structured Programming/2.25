/*Од стандарден влез се чита природен број N (N <= 100), како и низа од позитивни цели броеви a[ ] со N елементи. 
Да се напише функција int par(a, n) која ќе го врати најмалиот елемент во низата кој се појавува парен број пати во низата. 
Доколку нема таков елемент, функцијата враќа вредност 0. Напишете програма што ќе ја повика функцијата par за внесената низа a[ ] и ќе го испечати
најмалиот број којшто се појавува парен број пати во низата a[ ].
Пример 1.
Влез
12 // бројот N на елементи
1 3 4 5 3 1 4 5 5 3 2 3 // елементи на низата
Излез
Najmaliot element koj se pojavuva paren broj pati e 1 // овде функцијата par враќа вредност 1, а се печати оваа порака
Пример 2.
Влез
12 // бројот N на елементи
7 3 4 5 3 8 4 5 5 3 2 6 // елементи на низата
Излез
Nitu eden element ne se pojavuva paren broj pati! // овде функцијата par враќа вредност 0, се печати оваа порака */


#include <iostream>
#include <algorithm>
using namespace std;
int par(int a[],int n){
    sort(a,a+n);
    int count = 1;
    int minpar = 0;
    for (int i = 0; i < n-1; i++) {
        if (a[i] == a[i + 1]) {
            count++;
        } else {
            if (count % 2 == 0 && (minpar == 0||a[i] < minpar)) {
                minpar = a[i];
            }
            count = 1;
        }
    }

    return minpar;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(par(a,n)){
        cout<<"Najmaliot element koj se pojavuva paren broj pati e "<<par(a,n);
    }else{
        cout<<"Nitu eden element ne se pojavuva paren broj pati!";
    }
}

