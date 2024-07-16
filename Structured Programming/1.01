/*Благ број е број што е составен само од парни цифри (0, 2, 4, 6, 8). Во зададен опсег 
(почетокот m и крајот на опегот n се цели броеви чија вредност се внесува од тастатура), 
да се најде и испечати најмалиот „благ број“. Ако не постои таков број, да се испечати NE.*/


#include <iostream>
using namespace std;
int main(){
    int m,n,i,temp;
    bool blag;
    cin>>m>>n;
    for(i=m;i<=n;i++){
        temp=i;
        blag=true;
        while(temp){
            if ((temp % 10) % 2 != 0) {
                blag = false;
                break;
            }
            temp = temp / 10;
        }
        if(blag){
        cout<<i<<endl; 
        return 0;
        }
    }
    cout<<"NE";
}
