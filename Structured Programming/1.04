/*Од стандарден влез се читаат знаци се додека не се прочита извичник. Во вака внесениот текст се скриени цели броеви (помали од 100). Да се напише програма 
што ќе ги прочита сите знаци и на излез ќе го испечати збирот на сите броеви скриени во текстот.
Напомена: cin во C++ ги игнорира празните места (space). За да не ги игнорира потребно е да се додаде noskipws пред читањето на знакот (пр. cin >> noskipws >> znak;)*/


#include <iostream>
using namespace std;
int main(){
    char znak;
    int broj=0,zbir=0;
    while(cin>>noskipws>>znak){
        if(znak=='!'){
            cout<<zbir+broj;
        }
        else{
            if(znak>='0' && znak<='9'){
               broj=broj*10+(znak-'0');
            }
            else{
                zbir=zbir+broj;
                broj=0;
            }
        }
    }
}
