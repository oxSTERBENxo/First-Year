/*Да се напише програма која ќе го одреди резултатот на студентот по еден предмет. Програмата треба да ги изврши следниве задачи:
Програмата бара внес на следниве податоци од студентот:
Поени на испитот (цел број од 0 до 100).
Присуство на студентот (број на часови посетени во однос на вкупниот број на часови во курсот).
Проверете дали внесените податоци се валидни. Поените од испитот треба да бидат во опсегот од 0 до 100, а присуството на часови треба да биде позитивен  број.
Вашата задача е да го пресметате резултатот на студентот со следниве критериуми:
Ако бројот на поени на испитот е поголем или еднаков на 60 и присуството е 80% или повеќе од часовите, студентот добива  "Odlichna ocenka."
Ако бројот на поени на испитот е поголем или еднаков на 50 и присуството е 70% или повеќе од часовите, студентот добива  "Zadovolitelna ocenka."
Во сите други случаи, студентот добива оценка "Prosechen rezultat."
Прикажете го на екран резултатот на студентот (неговата оценка).*/

#include <iostream>
using namespace std;

int main() {
    int examPoints;
    double attendance;

    cin >> examPoints >> attendance;

    if (examPoints < 0 || examPoints > 100 || attendance < 0 || attendance > 1 ) {
        cout << "Nevalidni vlezni podatoci" << endl;
        return 1; 
    }
    
    if (examPoints >= 60 && attendance >= 0.8) {
        cout << "Odlichna ocenka" << endl;
    } else if (examPoints >= 50 && attendance >= 0.7) { //if you put >0.7 all test cases pass, but the text clearly says >= so ig it's their mistake.
        cout << "Zadovolitelna ocenka" << endl;
    } else {
        cout << "Prosechen rezultat" << endl;
    }
    
    return 0;
}
