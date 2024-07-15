/*Потребно е да се имплементира класа за компјутерска игра (Game), што содржи информации за:
- име на играта (низа од макс. 100 знаци), цена на играта (децимален број), дали е играта купена на распродажба (bool променлива).
Од класата Game да се изведе класа SubscriptionGame, што дополнително ќе чува:
- месечен надоместок за играње (децимален број), датум кога играта е купена (месец и година како позитивни цели броеви)
За класите Game и SubscriptionGame да се преоптоварат операторите за печатење (<<) и читање (>>). Да се дефинира и операторот == кој ќе споредува игри според нивното име.
Да се дефинира класа за корисник (User) во која се чуваат:
- кориснично име на корисникот (низа од макс. 100 знаци), колекција од игри кои се купени од корисникот (динамички алоцирана низа).
- Да се преоптовари операторот += кој ќе овозможи додавање на нова игра во колекцијата на игри. Притоа ако корисникот ја има веќе купено играта, потребно е да се
креира исклучок од типот ExistingGame. Класата за имплементација на исклучоци потребно е има соодветен конструктор и метода message за печатење на порака на екран.
- Да се креира и метода total_spent() во класата User која ќе пресметува колку пари корисникот потрошил за својата колекција од игри. Доколку играта е купена на распродажба,
цената на играта е 30% од стандарната цена. Доколку играта е од типот SubscriptionGame, потребно е да се вкалкулира и сумата потрошена за месечниот
надоместок (број_на_изминати_месеци x цена_на_месечен_надоместок) без да се земе во предвид моменталниот месец (мај 2018).
- Да се преоптовари и оператоторот за печатење на корисникот, која печати информации во сл. формат (види тест примери 7 до 12):
User: username
- Game: PUBG, regular price: $70, bought on sale
- Game: Half Life 2, regular price: $70 - Game: Warcraft 4, regular price: $40, monthly fee: $10, purchased: 1-2017
Листа на дел од методите со нивни прототипови кои се користат во main:
ЕxistingGame::message()
Game::operator==(Game&)
User::operator+=(Game&)
User::get_game(int)
User::total_spent(int)
User::get_name()
User::get_games_number()
*/

#include <iostream>
#include <cstring>
using namespace std;

class ExistingGame{
private:
    char msg[256];

public:
    ExistingGame(char msg_txt[]){
        strncpy(this->msg, msg_txt, 255);
        this->msg[255] = '\0';
    }
    void message(){
        cout<<this->msg<<endl;
    }
};

class Game {
protected:
    char name[100];
    float price;
    bool onSale;
public:
    Game(){
        name[0] = '\0';
    }
    Game(char *n, float price, bool onSale=false){
        strncpy(name, n, 99);
        this->name[99] = '\0';
        this->price = price;
        this->onSale = onSale;
    }

    virtual float get_price(){
        if (onSale){
            return price * 0.3;
        }
        return price;
    }

    bool operator==(Game& g){
        return !strcmp(this->name, g.name);
    }
    friend ostream &operator<<(ostream &os, const Game &dr) {
        os<<"Game: "<< dr.name <<", regular price: $" << dr.price;
        if (dr.onSale){
            os<<", bought on sale";
        }
        return os;
    }
    friend istream &operator>>(istream &is, Game &dr){
        is.get();
        is.getline(dr.name,100);
        is>>dr.price>>dr.onSale;
        return is;
    }

};

class SubscriptionGame : public Game {
protected:
    float monthly_fee;
    int month, year;

public:
    SubscriptionGame(){
        name[0] = '\0';
    }

    SubscriptionGame(char *n, float p, bool s, float mf, int m, int y):
            Game(n, p, s),
            monthly_fee(mf),
            month(m),
            year(y) { }

    float get_price(){
        float price = Game::get_price();

        int months=0;
        if (year<2018){
            months = (12 - this->month) + (2017 - year)*12 + 5;
        }
        else {
            months = 5 - this->month;
        }

        price += months * monthly_fee;

        return price;
    }
    friend ostream &operator<<(ostream &os, SubscriptionGame &dr) {
        Game * tmp = dynamic_cast<Game*>(&dr);
        os << *tmp;
        os <<", monthly fee: $"<< dr.monthly_fee;
        os <<", purchased: "<< dr.month << "-" << dr.year<<endl;
        return os;
    }
    friend istream &operator>>(istream &is, SubscriptionGame &dr){
        is.get();
        is.getline(dr.name,100);
        is>>dr.price>>dr.onSale;
        is>>dr.monthly_fee >> dr.month >> dr.year;
        return is;
    }
};

class User {
private:
    void obj_copy(const User *orig, User *cpy){
        strcpy(cpy->username, orig->username);
        cpy->numGames = orig->numGames;
        cpy->games = new Game*[cpy->numGames];
        for (int i=0; i< cpy->numGames; ++i){
            cpy->games[i] = new Game(*(orig->games[i]));
        }
    }
protected:
    char username[100];
    Game ** games;
    int numGames;
public:
    User (char const * const un="") {
        strncpy(this->username, un, 99);
        this->username[99] = '\0';
        games = 0;
        numGames = 0;
    }
    User (const User &dr){
        obj_copy(&dr,this);
    }
    ~User(){
        for (int i=0; i < this->numGames; ++i){
            delete this->games[i];
        }
        delete [] games;
    }

    User &operator=(User &dr){
        if (this!=&dr){
            delete [] dr.games;
            for (int i=0; i < this->numGames; ++i){
                delete dr.games[i];
            }
            obj_copy(&dr, this);
        }
        return *this;
    }

    User &operator+=(Game &dr){

        Game ** new_games = new Game*[this->numGames + 1];

        for (int i=0; i < (this->numGames);i++) {
            if ( (*(this->games[i])) == dr){
                throw ExistingGame("The game is already in the collection");
            }

            new_games[i] = games[i];
        }
        SubscriptionGame * sg = dynamic_cast< SubscriptionGame* >(&dr);
        if(sg){
            new_games[numGames] = new SubscriptionGame(*sg);
        }
        else {
            new_games[numGames] = new Game(dr);
        }
        delete [] this->games;
        this->games = new_games;
        this->numGames++;
        return *this;
    }

    Game& get_game(int i){
        return (*(this->games[i]));
    }

    float total_spent(){
        float sum = 0.0;
        for (int i=0; i<this->numGames;i++){
            sum += games[i]->get_price();
        }
        return sum;
    }

    char const * const get_username(){
        return this->username;
    }

    int get_games_number(){
        return this->numGames;
    }

};

ostream & operator<<(ostream &os, User &dr) {

    os<<"\nUser: "<<dr.get_username()<<"\n";

    for (int i=0; i < dr.get_games_number(); ++i){
        SubscriptionGame *sg = dynamic_cast<SubscriptionGame *> (&dr.get_game(i));
        if (sg){
            os<<"- "<<(*sg);
        }
        else {
            os<<"- "<<(dr.get_game(i));
        }
        cout<<"\n";
    }
    return os;
}

int main() {
    int test_case_num;

    cin>>test_case_num;

    // for Game
    char game_name[100];
    float game_price;
    bool game_on_sale;

    // for SubscritionGame
    float sub_game_monthly_fee;
    int sub_game_month, sub_game_year;

    // for User
    char username[100];
    int num_user_games;

    if (test_case_num == 1){
        cout<<"Testing class Game and operator<< for Game"<<std::endl;
        cin.get();
        cin.getline(game_name,100);
        //cin.get();
        cin>>game_price>>game_on_sale;

        Game g(game_name, game_price, game_on_sale);

        cout<<g;
    }
    else if (test_case_num == 2){
        cout<<"Testing class SubscriptionGame and operator<< for SubscritionGame"<<std::endl;
        cin.get();
        cin.getline(game_name, 100);

        cin>>game_price>>game_on_sale;

        cin>>sub_game_monthly_fee;
        cin>>sub_game_month>>sub_game_year;

        SubscriptionGame sg(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
        cout<<sg;
    }
    else if (test_case_num == 3){
        cout<<"Testing operator>> for Game"<<std::endl;
        Game g;

        cin>>g;

        cout<<g;
    }
    else if (test_case_num == 4){
        cout<<"Testing operator>> for SubscriptionGame"<<std::endl;
        SubscriptionGame sg;

        cin>>sg;

        cout<<sg;
    }
    else if (test_case_num == 5){
        cout<<"Testing class User and operator+= for User"<<std::endl;
        cin.get();
        cin.getline(username,100);
        User u(username);

        int num_user_games;
        int game_type;
        cin >>num_user_games;

        try {

            for (int i=0; i<num_user_games; ++i){

                cin >> game_type;

                Game *g;
                // 1 - Game, 2 - SubscriptionGame
                if (game_type == 1){
                    cin.get();
                    cin.getline(game_name, 100);

                    cin>>game_price>>game_on_sale;
                    g = new Game(game_name, game_price, game_on_sale);
                }
                else if (game_type == 2){
                    cin.get();
                    cin.getline(game_name, 100);

                    cin>>game_price>>game_on_sale;

                    cin>>sub_game_monthly_fee;
                    cin>>sub_game_month>>sub_game_year;
                    g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
                }

                //cout<<(*g);


                u+=(*g);
            }
        }catch(ExistingGame &ex){
            ex.message();
        }

        cout<<u;

//    cout<<"\nUser: "<<u.get_username()<<"\n";

//    for (int i=0; i < u.get_games_number(); ++i){
//        Game * g;
//        SubscriptionGame * sg;
//        g = &(u.get_game(i));

//        sg = dynamic_cast<SubscriptionGame *> (g);

//        if (sg){
//          cout<<"- "<<(*sg);
//        }
//        else {
//          cout<<"- "<<(*g);
//        }
//        cout<<"\n";
//    }

    }
    else if (test_case_num == 6){
        cout<<"Testing exception ExistingGame for User"<<std::endl;
        cin.get();
        cin.getline(username,100);
        User u(username);

        int num_user_games;
        int game_type;
        cin >>num_user_games;

        for (int i=0; i<num_user_games; ++i){

            cin >> game_type;

            Game *g;
            // 1 - Game, 2 - SubscriptionGame
            if (game_type == 1){
                cin.get();
                cin.getline(game_name, 100);

                cin>>game_price>>game_on_sale;
                g = new Game(game_name, game_price, game_on_sale);
            }
            else if (game_type == 2){
                cin.get();
                cin.getline(game_name, 100);

                cin>>game_price>>game_on_sale;

                cin>>sub_game_monthly_fee;
                cin>>sub_game_month>>sub_game_year;
                g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
            }

            //cout<<(*g);

            try {
                u+=(*g);
            }
            catch(ExistingGame &ex){
                ex.message();
            }
        }

        cout<<u;

//      for (int i=0; i < u.get_games_number(); ++i){
//          Game * g;
//          SubscriptionGame * sg;
//          g = &(u.get_game(i));

//          sg = dynamic_cast<SubscriptionGame *> (g);

//          if (sg){
//            cout<<"- "<<(*sg);
//          }
//          else {
//            cout<<"- "<<(*g);
//          }
//          cout<<"\n";
//      }
    }
    else if (test_case_num == 7){
        cout<<"Testing total_spent method() for User"<<std::endl;
        cin.get();
        cin.getline(username,100);
        User u(username);

        int num_user_games;
        int game_type;
        cin >>num_user_games;

        for (int i=0; i<num_user_games; ++i){

            cin >> game_type;

            Game *g;
            // 1 - Game, 2 - SubscriptionGame
            if (game_type == 1){
                cin.get();
                cin.getline(game_name, 100);

                cin>>game_price>>game_on_sale;
                g = new Game(game_name, game_price, game_on_sale);
            }
            else if (game_type == 2){
                cin.get();
                cin.getline(game_name, 100);

                cin>>game_price>>game_on_sale;

                cin>>sub_game_monthly_fee;
                cin>>sub_game_month>>sub_game_year;
                g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
            }

            //cout<<(*g);


            u+=(*g);
        }

        cout<<u;

        cout<<"Total money spent: $"<<u.total_spent()<<endl;
    }
}

