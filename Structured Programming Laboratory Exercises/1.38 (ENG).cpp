/*Да се напише програма која ќе ги оцени студентите според нивните академски постигнувања. Програмата треба да ги изврши следниве задачи: Проверка на условите:
Програмата проверува дали внесените податоци се валидни и дали студентот има повеќе од 100 кредити и просек поголем од 8. Ако се исполнети условите се прават следниве пресметки:
Предвидени кредити се пресметуваат како (2023−Година на запишување)×60
Поени се пресметуваат како: Поени=Број на кредитиПредвидени кредити×10+(Просек−8.5)×6.5
Доколку студентот има повеќе од 240 кредити, се прикажува "Needs to graduate!" како дополнителна информација. Ако просекот на студентот е поголем од 9, 
се прикажува "Great student!" како дополнителна информација. Во спротивно, ако условите не се исполнети, програмата поставува вредност на поените на 0.
Од стандарден влез се читаат број на кредити (цел број), година на запишување (2010-2023) и просек (децимален број). Да се испечатaт поените на студентот и 
соодветната дополнителна порака(доколку е потребно).
-----------------------------------------
Write a program to evaluate students based on their academic achievements. The program should perform the following tasks:
Check the following conditions:
The program checks if the entered data is valid and if the student has more than 100 credits and an average grade higher than 8. If the conditions are met, 
the following calculations are made:
Predicted credits are calculated as: (2023−year of enrollment)×60
Points are calculated as: Points=number of creditsPredicted Credits×10+(Average Grade−8.5)×6.5
If the student has more than 240 credits, "Needs to graduate!" is displayed as additional information. If the student's average grade is greater than 9, 
"Great student!" is displayed as additional information. Alternatively, if the conditions are not met, the program sets the points to 0.
The program reads the number of credits (integer), year of enrollment (2010-2023), and average grade (decimal number) from standard input. It should print 
the student's points and the relevant additional message (if necessary).*/

#include <iostream>
using namespace std;

int main() {
    int credits, yearOfEnrollment, currentYear=2023;
    double averageGrade, predictedCreds, points;
    cin >> credits >> yearOfEnrollment >> averageGrade;
    if (credits <= 100 || averageGrade <= 8 || yearOfEnrollment < 2010 || yearOfEnrollment > 2023) {
        cout << "Points: 0" << endl;
        return 0;
    }
    predictedCreds = (currentYear - yearOfEnrollment) * 60.0;
    points = (credits / predictedCreds) * 10 + (averageGrade - 8.5) * 6.5;
    if (credits > 240) {
        cout << "Needs to graduate! ";
    }
    if (averageGrade > 9) {
        cout << "Great student! ";
    }
    cout << "Points: " << points << endl;
    return 0;
}
