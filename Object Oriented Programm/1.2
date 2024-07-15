/*Да се имплементира класа List во којашто ќе се чуваат информации за:
броеви што се дел од листата (динамички алоцирана низа од цели броеви), бројот на броеви што се дел од листата.
За класата да се дефинираат следните методи:
- конструктор (со аргументи), copy-конструктор, деструктор, оператор =,
- void pecati()метод што ќе ги печати информациите за листата во форматот: [број на елементи во листата]: x1 x2 .. xn sum: [сума] average: [просек]
- int sum() метод што ја враќа сумата на елементите во листата,
- double average() метод што ќе го враќа просекот на броевите во листата.

Дополнително, креирајте класата ListContainer, во која што ќе се чуваат информации за:
низа од листи (динамички алоцирана низа од објекти од класата List), број на елементи во низата од листи (цел број),
број на обиди за додавање на листа во контејнерот (цел број првично поставен на нула)
За класата потребно е да ги дефинирате следните методи:
- конструктор (default), copy-конструктор, деструктор, оператор =
- void pecati() метод што ќе ги печати информациите за контејнерот во форматот: 
List number: [реден број на листата] List info: [испечатени информации за листата со методот List::pecati()] \n sum: [сума] average: [просек]
Доколку контејнерот е празен се печати само порака The list is empty.
- void addNewList(List l) метод со којшто се додава листа во контејнерот
Напомена: една листа се додава во контејнерот ако и само ако има различна сума од сите листи што се веќе додадени во контејнерот
- int sum() метод што ја враќа сумата на сите елементи во сите листи
- double average() метод што го враќа просекот на сите елементи во сите листи во контејнерот*/

#include <iostream>
#include <cstring>
using namespace std;
class List{
private:
    int *broevi;
    int n;
public:
    List(int *broevi=nullptr, int n=0){
        this->broevi= new int[n];
        for(int i=0;i<n;i++){
            this->broevi[i]=broevi[i];
        }
        this->n=n;
    }
    List(const List &dr){
        this->broevi= new int[dr.n];
        for(int i=0;i<dr.n;i++){
            this->broevi[i]=dr.broevi[i];
        }
        this->n=dr.n;
    }
    ~List(){delete [] broevi;};
    List &operator=(const List &dr){
        if(this!=&dr){
            delete [] broevi;
            this->broevi= new int[dr.n];
            for(int i=0;i<dr.n;i++){
                this->broevi[i]=dr.broevi[i];
            }
            this->n=dr.n;
        }
        return *this;
    }
    void pecati(){
        cout<<n<<": ";
        for(int i=0;i<n;i++){
            cout<<broevi[i]<<" ";
        }
        cout << "sum: " << sum() << " average: " << average() << endl;
    }
    int sum(){
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+broevi[i];
        }
        return sum;
    }
    double average(){
        return (double)sum()/n;
    }

    int *getBroevi(){
        return broevi;
    }
    int getN(){
        return n;
    }

};
class ListContainer{
private:
    List *listi;
    int n;
    int capacity;//obidi
public:
    ListContainer(List *listi=nullptr,int n=0,int capacity=0){
        this->n=n;
        this->capacity=capacity;
        this->listi=new List[n];
        for(int i=0;i<n;i++){
            this->listi[i]=listi[i];
        }
    }
    ~ListContainer(){
        delete [] listi;
    }
    ListContainer(const ListContainer &dr){
        this->n=dr.n;
        this->capacity=dr.capacity;
        delete [] listi;
        this->listi=new List[dr.n];
        for(int i=0;i<dr.n;i++){
            this->listi[i]=dr.listi[i];
        }
    }
    ListContainer &operator=(const ListContainer &dr){
        if(this!=&dr){
            this->n=dr.n;
            this->capacity=dr.capacity;
            delete [] listi;
            this->listi=new List[dr.n];
            for(int i=0;i<dr.n;i++){
                this->listi[i]=dr.listi[i];
            }
            return *this;
        }
    }
    int sum(){
        int suma=0;
        for(int i=0;i<n;i++){
            suma=suma+listi[i].sum();
        }
        return suma;
    }
    double average(){
        int vkupnoEl=0;
        for(int i=0;i<n;i++){
            vkupnoEl=vkupnoEl+listi[i].getN();
        }
        return double(sum())/vkupnoEl;
    }

    void print(){
        if(n==0){
            cout<<"The list is empty"<<endl;
            return;
        }else{
            for(int i=0;i<n;i++){
                cout<<"List number: "<<i+1<<" List info: ";
                listi[i].pecati();
            }
            cout<<"Sum: "<<sum()<<" Average: "<<average()<<endl;
            cout<<"Successful attempts: "<<n<<" Failed attempts: "<<capacity-n<<endl;
        }
    }

    void addNewList(List l){
        int flag=0;
        for(int i=0;i<n;i++){
            if(l.sum()==listi[i].sum()){
                flag=1;
            }
        }
        if(flag==0){
            List *temp= new List[n+1];
            for(int i=0;i<n;i++){
                temp[i]=listi[i];
            }
            temp[n]=l;
            delete[]listi;
            listi=temp;
            n++;
        }
        capacity++;
    }

};
int main() {

    ListContainer lc;
    int N;
    cin>>N;

    for (int i=0;i<N;i++) {
        int n;
        int niza[100];

        cin>>n;

        for (int j=0;j<n;j++){
            cin>>niza[j];

        }

        List l=List(niza,n);

        lc.addNewList(l);
    }


    int testCase;
    cin>>testCase;

    if (testCase==1) {
        cout<<"Test case for operator ="<<endl;
        ListContainer lc1;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1=lc;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1.sum();
        lc1.average();

    }
    else {
        lc.print();
    }
}
