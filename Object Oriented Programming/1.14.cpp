/*Потребно е да се имплементираат класи File (датотека) и Folder (директориум) за работа со едноставен податочен систем.
Во класата File треба да се чуваат следниве податоци:
Име на датотеката (динамички алоцирана низа од знаци), Екстензија на датотеката (енумерација со можни вредности: txt, pdf, exe),
Име на сопственикот на датотеката (динамички алоцирана низа од знаци), Големина на датотеката (цел број на мегабајти).
Дополнително, во класата потребно е да се напишат и:
- Конструктор без параметри, Конструктор со параметри, Конструктор за копирање, Деструктор.
- Преоптоварување на операторот =
- Метод за печатење на информациите за една датотека (видете го излезот од тест примерите за структурата на печатење) - print()
- Метод за проверка на еднаквост помеѓу две датотеки со потпис bool equals(const File & that) кој ќе враќа true ако датотеките имаат исто име, екстензија и сопственик
- Метод за споредба на типот помеѓу две датотеки со потпис bool equalsType(const File & that) кој ќе враќа true ако датотеките се од ист тип, т.е. имаат исто име и екстензија
Во класата Folder треба да се чуваат следниве податоци:
Име на директориумот (динамички алоцирана низа од знаци), Број на датотеки во него (на почеток директориумот е празен),
Динамички алоцирана низа од датотеки (објекти од класата File)
Дополнително, во класата потребно е да се напишат и:
- Конструктор со потпис Folder(const char* name), Деструктор.
- Метод за печатење на информациите за еден директориум (видете го излезот од тест примерите за структурата на печатење) - print()
- Метод за бришење на датотека од директориумот со потпис void remove(const File & file) кој ќе ја избрише првата датотека од директориумот која е еднаква според equals методот
- Метод за додавање на датотека во директориумот со потпис void add(const File & file) кој ќе додава датотеката во директориумот
Не го менувајте почетниот код.*/

#include<iostream>
#include<cstring>
using namespace std;

enum Extension{
    pdf,txt,exe
};
class File{
    char *ime;
    Extension e;
    char *sopstvenik;
    int golemina;
public:
    File(){
        ime=0;
        sopstvenik=0;
    }
    File(char *ime, char *sopstvenik, int golemina=0, Extension e=pdf){
        this->e=e;
        this->golemina=golemina;
        this->ime = new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        this->sopstvenik = new char[strlen(sopstvenik)+1];
        strcpy(this->sopstvenik,sopstvenik);
    }
    ~File(){
        delete [] ime;
        delete [] sopstvenik;
    }
    File(const File &dr){
        this->e=dr.e;
        this->golemina=dr.golemina;
        this->ime = new char[strlen(dr.ime)+1];
        strcpy(this->ime,dr.ime);
        this->sopstvenik = new char[strlen(dr.sopstvenik)+1];
        strcpy(this->sopstvenik,dr.sopstvenik);
    }
    File &operator=(const File &dr){
        if(this!=&dr){
            delete [] ime;
            delete [] sopstvenik;
            this->e=dr.e;
            this->golemina=dr.golemina;
            this->ime = new char[strlen(dr.ime)+1];
            strcpy(this->ime,dr.ime);
            this->sopstvenik = new char[strlen(dr.sopstvenik)+1];
            strcpy(this->sopstvenik,dr.sopstvenik);
        }
        return *this;
    }
    void print(){
        cout<<"File name: "<<ime<<".";
        if(e==0){
            cout<<"pdf"<<endl;
        }else if(e==1){
            cout<<"txt"<<endl;
        }else if(e==2){
            cout<<"exe"<<endl;
        }
        cout<<"File owner: "<<sopstvenik<<endl;
        cout<<"File size: "<<golemina<<endl;
    }
    bool equals(const File &dr) const{
        return((strcmp(ime,dr.ime)==0)&&(e==dr.e));
    }
};
class Folder{
    char *ime;
    int n;
    File *files;
public:
    Folder(char *ime){
        this->ime = new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        n=0;
        files=0;
    }
    ~Folder(){
        delete [] ime;
        delete [] files;
    }
    Folder(const Folder &dr){
        this->ime = new char[strlen(dr.ime)+1];
        strcpy(this->ime,dr.ime);
        n=dr.n;
        files = new File[dr.n];
        for(int i=0;i<n;i++){
            this->files[i]=dr.files[i];
        }
    }
    Folder &operator=(const Folder &dr){
        if(this!=&dr){
            delete [] ime;
            delete [] files;
            this->ime = new char[strlen(dr.ime)+1];
            strcpy(this->ime,dr.ime);
            n=dr.n;
            files=new File[dr.n];
            for(int i=0;i<n;i++){
                this->files[i]=dr.files[i];
            }
        }
        return *this;
    }
    void print(){
        cout<<"Folder name: "<<ime<<endl;
        for(int i=0;i<n;i++){
            files[i].print();
        }
    }
    void remove(const File &dr){
        File *temp = new File[n];
        int j=0;
        for(int i=0;i<n;i++){
            if(!dr.equals(files[i])){
                temp[j]=files[i];
                j++;
            }
        }
        n=j;
        delete [] files;
        files=temp;
    }
    void add(const File &dr){
        File *temp = new File[n+1];
        for(int i=0;i<n;i++){
            temp[i]=files[i];
        }
        temp[n++]=dr;
        delete [] files;
        files=temp;
    }
};

int main() {
    char fileName[20];
    char fileOwner[20];
    int ext;
    int fileSize;

    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File created = File(fileName, fileOwner, fileSize, (Extension) ext);
        File copied = File(created);
        File assigned = created;

        cout << "======= CREATED =======" << endl;
        created.print();
        cout << endl;
        cout << "======= COPIED =======" << endl;
        copied.print();
        cout << endl;
        cout << "======= ASSIGNED =======" << endl;
        assigned.print();
    }
    else if (testCase == 2) {
        cout << "======= FILE EQUALS & EQUALS TYPE =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File first(fileName, fileOwner, fileSize, (Extension) ext);
        first.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File second(fileName, fileOwner, fileSize, (Extension) ext);
        second.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File third(fileName, fileOwner, fileSize, (Extension) ext);
        third.print();

        bool equals = first.equals(second);
        cout << "FIRST EQUALS SECOND: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equals = first.equals(third);
        cout << "FIRST EQUALS THIRD: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        bool equalsType = first.equals(second);
        cout << "FIRST EQUALS TYPE SECOND: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equalsType = second.equals(third);
        cout << "SECOND EQUALS TYPE THIRD: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

    }
    else if (testCase == 3) {
        cout << "======= FOLDER CONSTRUCTOR =======" << endl;
        cin >> fileName;
        Folder folder(fileName);
        folder.print();

    }
    else if (testCase == 4) {
        cout << "======= ADD FILE IN FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        folder.print();
    }
    else {
        cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File file(fileName, fileOwner, fileSize, (Extension) ext);
        folder.remove(file);
        folder.print();
    }
    return 0;
}
