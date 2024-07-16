/*Да се креира класа која претставува слика (Image) во рамките на еден компјутер. За секоја датотека се чуваат:
- име на сликата (дин. алоцирана низа од знаци). Предефинирано поставено на untitled
- име на корисникот кој е сопственик на датотеката (низа од макс. 50 знаци). Предефинирано поставено на unknown.
- димензии на сликата (2 цели броеви кои претставуваат ширина и висина во пиксели). Предефинирано поставени на 800.
Од класата Imageда се изведе класата TransparentImage, која претставува слика која содржи поддржува транспарентност. За транспарентна слика дополнително се чува :
- дали поддржува нивоа на транспарентност (bool променлива, предефинирано не поддржува транспарентност).
За класите Image и TransparentImage да биде достапна метода (fileSize)за пресметка на големината на сликата (во бајти). Големината се пресметува на сл. начин:
- за објектите од класата Image: големината на датотеката е еднаква на:висината * ширината * 3.
- за TransparentImage: доколку поддржува нивоа на транспарентност, големината на датотеката е еднаква на ширина * висина * 4. Доколку не поддржува транспарентност,
големината на сликата се пресметува како ширина * висина + бр._на_пиксели_присутни_во_сликата / 8.
За класите Image и TransparentImage да се преоптоварат следниве оператори:
- оператор << кој ги печати податоците од датотеката во сл. формат: ime_fajl avtor golemina_na_fajlot_vo_bajti
- оператор > кој ги споредува сликите според нивната големина.
Да се дефинира класа Folder, што репрезентира директориум во кој може да се поставуваат слики. За секој фолдер се чува:
- име на фолдерот (низа од макс 255 знаци), име на корисникот кој е сопственик на фолдерот (низа од макс. 50 знаци) предефинирано поставено на unknown и
  низа од покажувачи кон Image објекти (макс. 100 во рамките на еден фолдер).
Да се имплементираат следниве методи:
- метода за пресметка на големината на фолдерот (folderSize). Големината на фолдерот е сума од големините од сите слики во рамките на фолдерот.
- метода за пронаоѓање на наголемата слика во рамките на фолдерот (getMaxFile). Методата враќа покажувач кон најголемата слика во фолдерот (сметано во бајти).
За класата Folder да се имплементира и оператор += кој додава објекти од типот Image/TransparentImage во рамките на фолдерот.
Да се креираат следниве функционалности за класите:
- operator << - со кој се печатат податоците за фолдерот во формат:
ime_folder sopstvenik --
imeslika avtor goleminanafajlotvo_bajti
imeslika avtor goleminanafajlotvobajti -- goleminanafoldervo_bajti
- operator [] - кој враќа покажувач кон соодветната слика во фолдерот. Доколку не постои слика на тој индекс, треба да се врати NULL (5 поени).
- Да се креира и глобална функција max_folder_size која го прима низа од објекти од типот Folder и го враќа фолдерот кој има зафаќа најмногу простор (во бајти).
Да се овозможи правилно функционирање на класите (потребни set или get методи/оператори/конструктори/деструктори) според изворниот код кој е веќе зададен.
Сите податочни членови на класите се protected.*/

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Image{
protected:
    char *slika;
    char sopstvenik[50];
    int shirina;
    int visina;
public:
    Image(char* slika="untitled", char* sopstvenik="unknown", int shirina=800, int visina=800){
        this->slika=new char[strlen(slika)+1];
        strcpy(this->slika,slika);
        strcpy(this->sopstvenik,sopstvenik);
        this->shirina=shirina;
        this->visina=visina;
    }
    virtual ~Image(){delete [] slika;}
    Image(const Image &dr){
        this->slika=new char[strlen(dr.slika)+1];
        strcpy(this->slika,dr.slika);
        strcpy(this->sopstvenik,dr.sopstvenik);
        this->shirina=dr.shirina;
        this->visina=dr.visina;
    }
    Image &operator=(Image &dr){
        if(this!=&dr){
            delete [] slika;
            this->slika=new char[strlen(dr.slika)+1];
            strcpy(this->slika,dr.slika);
            strcpy(this->sopstvenik,dr.sopstvenik);
            this->shirina=dr.shirina;
            this->visina=dr.visina;
        } return *this;
    }
    virtual unsigned int fileSize(){
        return visina*shirina*3;
    }
    friend ostream &operator<<(ostream &os, Image &dr){
        os<<dr.slika<<" "<<dr.sopstvenik<<" "<<dr.fileSize()<<endl;
        return os;
    }
    bool operator>(Image &dr){
        return fileSize()>dr.fileSize();
    }
};

class TransparentImage : public Image{
    bool transparentnost;
public:
    TransparentImage(char* slika="untitled", char* sopstvenik="unknown", int shirina=800, int visina=800, bool transparentnost=true)
            :Image(slika,sopstvenik,shirina,visina){
        this->transparentnost=transparentnost;
    }
    unsigned int fileSize(){
        if(transparentnost){
            return shirina*visina*4;
        } else {
            return shirina*visina+(shirina*visina)/8;
        }
    }
    friend ostream &operator<<(ostream &os, TransparentImage &dr){
        os<<dr.slika<<" "<<dr.sopstvenik<<" "<<dr.fileSize()<<endl;
        return os;
    }
};

class Folder{
    char ime[256];
    char korisnik[51];
    Image *images[100];
    int n;
public:
    Folder(){
        for(int i=0;i<100;i++){
            images[i]=0;
        }
        n=0;
    }
    Folder(char* ime, char* korisnik){
        strcpy(this->ime,ime);
        strcpy(this->korisnik,korisnik);
        for(int i=0;i<100;i++){
            images[i]=0;
        }
        n=0;
    }
    int folderSize(){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=images[i]->fileSize();
        }
        return sum;
    }
    Image *getMaxFile(){
        Image *tmp = images[0];
        for(int i=0;i<n;i++){
            if(*images[i]>*tmp){
                tmp=images[i];
            }
        }
        return tmp;
    }
    Folder &operator+=(Image &dr){
        TransparentImage *ti = dynamic_cast<TransparentImage *>(&dr);
        if(ti){
            images[n++]=new TransparentImage(*ti);
        } else images[n++]=new Image(dr);
        return *this;
    }
    friend ostream &operator<<(ostream &os, Folder &dr){
        os<<dr.ime<<" "<<dr.korisnik<<endl;
        os<<"--"<<endl;
        for(int i=0;i<dr.n;i++){
            os<<*dr.images[i];
        }
        os<<"--"<<endl;
        os<<"Folder size: "<<dr.folderSize()<<endl;
        return os;
    }
    Image *operator[](int j){
        if(j>=0 && j<n){
            return images[j];
        } else {
        return nullptr;
        }
    }
};

Folder &max_folder_size(Folder *folders, int n){
    Folder tmp = folders[0];
    int indeks=0;
    for(int i=0;i<n;i++){
        if(tmp.folderSize()<folders[i].folderSize()){
            tmp=folders[i];
            indeks=i;
        }
    }
    return folders[indeks];
}

int main() {

    int tc; // Test Case

    char name[255];
    char user_name[51];
    int w, h;
    bool tl;

    cin >> tc;

    if (tc==1){
        // Testing constructor(s) & operator << for class File

        cin >> name;
        cin >> user_name;
        cin >> w;
        cin >> h;


        Image f1;

        cout<< f1;

        Image f2(name);
        cout<< f2;

        Image f3(name, user_name);
        cout<< f3;

        Image f4(name, user_name, w, h);
        cout<< f4;
    }
    else if (tc==2){
        // Testing constructor(s) & operator << for class TextFile
        cin >> name;
        cin >> user_name;
        cin >> w >> h;
        cin >> tl;

        TransparentImage tf1;
        cout<< tf1;

        TransparentImage tf4(name, user_name, w, h, tl);
        cout<< tf4;
    }
    else if (tc==3){
        // Testing constructor(s) & operator << for class Folder
        cin >> name;
        cin >> user_name;

        Folder f3(name, user_name);
        cout<< f3;
    }
    else if (tc==4){
        // Adding files to folder
        cin >> name;
        cin >> user_name;

        Folder dir(name, user_name);

        Image * f;
        TransparentImage *tf;

        int sub, fileType;

        while (1){
            cin >> sub; // Should we add subfiles to this folder
            if (!sub) break;

            cin >>fileType;
            if (fileType == 1){ // Reading File
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                f = new Image(name,user_name, w, h);
                dir += *f;
            }
            else if (fileType == 2){
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                cin >> tl;
                tf = new TransparentImage(name,user_name, w, h, tl);
                dir += *tf;
            }
        }
        cout<<dir;
    }
    else if(tc==5){
        // Testing getMaxFile for folder

        cin >> name;
        cin >> user_name;

        Folder dir(name, user_name);

        Image* f;
        TransparentImage* tf;

        int sub, fileType;

        while (1){
            cin >> sub; // Should we add subfiles to this folder
            if (!sub) break;

            cin >>fileType;
            if (fileType == 1){ // Reading File
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                f = new Image(name,user_name, w, h);
                dir += *f;
            }
            else if (fileType == 2){
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                cin >> tl;
                tf = new TransparentImage(name,user_name, w, h, tl);
                dir += *tf;
            }
        }
        cout<< *(dir.getMaxFile());
    }
    else if(tc==6){
        // Testing operator [] for folder

        cin >> name;
        cin >> user_name;

        Folder dir(name, user_name);

        Image* f;
        TransparentImage* tf;

        int sub, fileType;

        while (1){
            cin >> sub; // Should we add subfiles to this folder
            if (!sub) break;

            cin >>fileType;
            if (fileType == 1){ // Reading File
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                f = new Image(name,user_name, w, h);
                dir += *f;
            }
            else if (fileType == 2){
                cin >> name;
                cin >> user_name;
                cin >> w >> h;
                cin >> tl;
                tf = new TransparentImage(name,user_name, w, h, tl);
                dir += *tf;
            }
        }

        cin >> sub; // Reading index of specific file
        cout<< *dir[sub];
    }
    else if(tc==7){
        // Testing function max_folder_size
        int folders_num;

        Folder dir_list[10];

        Folder dir;
        cin >> folders_num;

        for (int i=0; i<folders_num; ++i){
            cin >> name;
            cin >> user_name;
            dir = Folder(name, user_name);


            Image* f;
            TransparentImage *tf;

            int sub, fileType;

            while (1){
                cin >> sub; // Should we add subfiles to this folder
                if (!sub) break;

                cin >>fileType;
                if (fileType == 1){ // Reading File
                    cin >> name;
                    cin >> user_name;
                    cin >> w >> h;
                    f = new Image(name,user_name, w, h);
                    dir += *f;
                }
                else if (fileType == 2){
                    cin >> name;
                    cin >> user_name;
                    cin >> w >> h;
                    cin >> tl;
                    tf = new TransparentImage(name,user_name, w, h, tl);
                    dir += *tf;
                }
            }
            dir_list[i] = dir;
        }

        cout<<max_folder_size(dir_list, folders_num);
    }
    return 0;
};
