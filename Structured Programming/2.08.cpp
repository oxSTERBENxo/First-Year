/*Од стандарден влез се читаат непознат број на редови додека не се прочита 0. Да се најде најдолгиот ред во кој има барем 2 цифри. Потоа, на стандарден 
излез да се испечатат знаците од најдолгиот ред кои се наоѓаат помеѓу првата и последната цифра (заедно со тие 2 цифри) во истиот редослед. Доколку има повеќе
такви редови се печати последниот. Се претпоставува дека ниту еден ред не е подолг од 100 знаци.
Пример.
Влез: 
dat.txt:
    aaa123aa222aa2aaa23aaaaa22
    aaaaaaaaaaaa 23aaaa
    123 aaa aaa aaa aaa 12345 aaa aaa 2a
    0
Излез:
    123 aaa aaa aaa aaa 12345 aaa aaa 2
*/



#include <iostream>
#include <cstring>
using namespace std;
bool daliIma(char a[]){
    int counter=0;
    for (int i = 0; i < strlen(a);i++) {
        if (isdigit(a[i])){
            counter++;
        }
    }
    if (counter >= 2){
        return true;
    } else{
        return false;
    }
}
int prvBroj(char a[]){
    for (int i = 0; i < strlen(a);i++) {
        if (isdigit(a[i])){
            return i;
        }
    }
    return -1;
}
int posledenBroj(char a[]){
    for (int i = strlen(a)-1; i>=0;i--) {
        if (isdigit(a[i])){
            return i;
        }
    }
    return -1;
}
int main() {
    char a[100];
    char max[100];
    int m=0;
    while (cin.getline(a,100) && strcmp(a,"0")!=0){
        if (daliIma(a)){
            int n=strlen(a);
            if (m < n){
                m=n;
                strcpy(max, a);
            }
            if (n == m){
                strcpy(max, a);
            }
        } else{
            continue;
        }
    }
    for (int i = prvBroj(max); i <= posledenBroj(max); ++i) {
        cout << max[i];
    }
    return 0;
}
