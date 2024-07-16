/*На стандарден влез се дадени повеќе редови со броеви така што секој ред започнува со еден цел број (N>=1) што означува колку броеви следуваат по него во истиот ред.
Да се напише програма која на СИ за секој ред ќе го испечати бројот со најголема најзначајна цифра. Читањето на броеви завршува кога ќе се прочита бројот 0.*/


#include <iostream>
using namespace std;
int main(){
    int n,a[100],brojce;
    while(cin>>n && n!=0){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int najleva=-1;
        for(int i=0;i<n;i++){
            int tempi=a[i];
            while(tempi>9){
                tempi=tempi/10;
            }
            if(tempi>najleva){
                najleva=tempi;
                brojce=a[i];
            }
        }
        cout<<brojce<<endl;
    }
}
