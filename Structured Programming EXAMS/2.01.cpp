/*Се внесуваат низи од значи од стандарден влез. Да се избројат и испечатат сите последнователни појавувања на соседни самогласки во речениците. 
Појавата на големи и мали букви да се игнорира. Пронајдените парови самогласки да се испечатат на екран, секој во нов ред со мали букви. Потоа во нов ред 
се печати бројот на појавувања на паровите самогласки. Читањето завршува кога ќе се прочита знакот #.
Пример:
IO is short for Input Output
medioio medIo song
#
Излез:
io
ou
io
oi
io
io
6
*/


#include <iostream>
#include <cstring>
using namespace std;
bool samoglaska(char a){
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'){
        return true;
    }else{
        return false;
    }
}
int main(){
    int count=0;
    while(true){
        char a[100];
        cin.getline(a,100);
        if(a[0]=='\0'){
            continue;
        }
        if(a[0]=='#'){
            break;
        }
        for(int i=0;i< strlen(a);i++){
            a[i]= tolower(a[i]);
        }
        for(int i=0;i< strlen(a);i++){
            if(samoglaska(a[i]) && samoglaska(a[i+1])){
                count++;
                cout<<a[i]<<a[i+1]<<endl;
            }
        }
        
    }
    cout<<count;
}
