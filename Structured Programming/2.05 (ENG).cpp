/*From SI read one number that represents the today's date in format DDMMYYYY (DD-day, MM-month, YYYY-year). Then read one integer N, after you read
N dates of birth in the given format. For each of the N read dates your program should print "YES" if on today's date (read in the beginning) the person
with that date have more or equal to 18 years, otherwise should print "NO".*/


#include <iostream>
using namespace std;
int main() {
    int today;
    cin >> today;
    int todayDay= today / 1000000;
    int todayMonth = (today / 10000) % 100;
    int todayYear = today % 10000;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        int dob_day = n / 1000000;
        int dob_month = (n / 10000) % 100;
        int dob_year = n % 10000;
        int age = todayYear - dob_year;
        if (todayMonth < dob_month || (todayMonth == dob_month && todayDay < dob_day)) {
            age--;
        }
        if (age >= 18) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
