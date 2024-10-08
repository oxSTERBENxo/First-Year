//This exercise is from the second partial exam in 2024
/*Да се дефинира класа Student во која ќе се чуваат информации за студент кој полагал испит по некој предмет и тоа:
индекс (стринг), име (стринг), презиме (стринг) и поени освоени на испитот (цел број).
За класата да се дефинираат потребните конструктори , оператор за печатење <<  и метод int grade() (методот ја враќа оценката по предметот 
по скалата 0-49 (5), 50-59 (6), 60-69 (7), 70-79 (8), 80-89 (9), 90-100 (10)).
Да се дефинира класа Results во која ќе се чуваат листа на студенти кои го положиле испитот по предметот (динамички алоцирана низа од објекти од класата Student) 
и цел број кој ја означува големината на листата.
За класата да се имплементираат:
- Потребните конструктори, 
- Оператор += за додавање на студент (Student) во резултатите
  Доколку студентот кој се додава има помалку од 50 поени, односно не го положил испитот, да се фрли исклучок од класата StudentFailedException. Справувањето со исклучокот 
  треба да испечати порака “Student with id {ID} failed the course”.
- Оператор за печатење <<
- Метод Results withGrade(int grade) - кој прима како аргумент оценка (цел број), а враќа нов објект од класата Results во кој во листата на студенти кои го полагале 
  предметот се содржат само студентите со оценка grade.
Дополнете ја main функцијата со следните барања:
Од датотеката input.txt прочитајте ги информациите за сите студенти кои го полагале испитот и тоа во следниот формат:
Информациите за секој студент се дадени во еден ред и тоа во редослед индекс, име, презиме и поени, одделени со празно место.
По читањето на информациите за секој студент, секој студент се додава во објектот results.
Во датотеката output1.txt да се испечатат резултатите за сите студенти.
Во датотеката output2.txt да се испечатат резултатите за сите студенти со оценка grade вчитана во почетниот код.
----
Define a class Student to store information about a student who has taken an exam for a subject, including the:
index (string), first name (string), last name (string), and points earned on the exam (integer).
For the class, define the necessary constructors, the print operator <<, and the method int grade() (the method returns the grade for the subject 
based on the scale 0-49 (5), 50-59 (6), 60-69 (7), 70-79 (8), 80-89 (9), 90-100 (10)).
Define a class Results to store a list of students who have passed the exam for the subject (dynamically allocated array of objects from the Student class) and an 
integer indicating the size of the list.
For the class, implement:
- The necessary constructors
- The operator += for adding a student (Student) to the results.
  If the student being added has less than 50 points, meaning they did not pass the exam, throw an exception from the class StudentFailedException. Handling the exception
  should print the message “Student with id {ID} failed the course”.
- The print operator <<
- The method Results withGrade(int grade) - which takes a grade (integer) as an argument and returns a new object of the Results class where the list of students who 
  have taken the subject contains only students with the grade grade.
Complete the main function with the following requirements:
Read information about all students who have taken the exam from the file input.txt in the following format:
The information for each student is given in one line in the order of index, first name, last name, and points, separated by a space.
After reading the information for each student, each student is added to the results object.
Print the results for all students to the file output1.txt.
Print the results for all students with the grade read in the initial code to the file output2.txt.*/

//CODE

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class StudentFailedException {
private:
    string id;
public:
    StudentFailedException(const string &id) : id(id) {}

    void msg() const {
        cout << "Student with id " << id << " failed the course" << endl;
    }
};

class Student {
private:
    string index;
    string first_name;
    string last_name;
    int points;
    int grade; // Store grade directly

public:
    Student(const string &index = "", const string &first_name = "", const string &last_name = "", int points = 0)
            : index(index), first_name(first_name), last_name(last_name), points(points) {
        calculateGrade();
    }

    void calculateGrade() {
        if (points >= 90) {
            grade = 10;
        } else if (points >= 80) {
            grade = 9;
        } else if (points >= 70) {
            grade = 8;
        } else if (points >= 60) {
            grade = 7;
        } else if (points >= 50) {
            grade = 6;
        } else {
            grade = 5;
        }
    }

    int getGrade() const {
        return grade;
    }

    const string &getIndex() const {
        return index;
    }

    friend ostream &operator<<(ostream &os, const Student &student) {
        os << student.index << " " << student.first_name << " " << student.last_name << " "
           << student.points << " Grade: " << student.grade;
        return os;
    }
};

class Results {
private:
    Student *students;
    int numStudents;

public:
    Results() : students(nullptr), numStudents(0) {}

    ~Results() {
        delete[] students;
    }

    Results(const Results &other) : students(nullptr), numStudents(0) {
        *this = other; // Reuse assignment operator
    }

    Results &operator=(const Results &other) {
        if (this != &other) {
            delete[] students;
            numStudents = other.numStudents;
            students = new Student[numStudents];
            for (int i = 0; i < numStudents; ++i) {
                students[i] = other.students[i];
            }
        }
        return *this;
    }

    Results &operator+=(const Student &student) {
        if (student.getGrade() <= 5) {
            throw StudentFailedException(student.getIndex());
        }
        
        Student *temp = new Student[numStudents + 1];
        for (int i = 0; i < numStudents; ++i) {
            temp[i] = students[i];
        }
        temp[numStudents++] = student;
        delete[] students;
        students = temp;
        return *this;
    }

    Results withGrade(int grade) const {
        Results filtered;
        for (int i = 0; i < numStudents; ++i) {
            if (students[i].getGrade() == grade) {
                filtered += students[i];
            }
        }
        return filtered;
    }

    friend ostream &operator<<(ostream &os, const Results &results) {
        if (results.numStudents == 0) {
            os << "None" << endl;
        } else {
            for (int i = 0; i < results.numStudents; ++i) {
                os << results.students[i] << endl;
            }
        }
        return os;
    }
};

void wtf() {
    ofstream fout("input.txt");
    string line;
    while (getline(cin, line)) {
        if (line == "----") {
            break;
        }
        fout << line << endl;
    }
    fout.close();
}

void rff(const string &path) {
    ifstream fin(path);
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}

int main() {
    wtf();

    Results results;

    ifstream ifs("input.txt");
    string index, first_name, last_name;
    int points;

    while (ifs >> index >> first_name >> last_name >> points) {
        Student s(index, first_name, last_name, points);
        try {
            results += s; // Add student to results
        } catch (StudentFailedException &e) {
            e.msg(); // Handle failed student
        }
    }
    ifs.close();

    int grade;
    cin >> grade;

    ofstream ofs1("output1.txt");
    ofs1 << results;
    ofs1.close();

    ofstream ofs2("output2.txt");
    try {
        Results filtered = results.withGrade(grade);
        ofs2 << filtered;
    } catch (StudentFailedException &e) {
        e.msg(); // Handle exception for grade filtering
    }
    ofs2.close();

    cout << "All students:" << endl;
    rff("output1.txt");
    cout << "Grade report for grade " << grade << ":" << endl;
    rff("output2.txt");

    return 0;
}

//TEST CASES

//INPUT1
/*151020 Stefan Andonov 89
151021 Vlatko Spasev 55
----
9*/
//OUTPUT1
/*All students:
151020 Stefan Andonov 89 Grade: 9
151021 Vlatko Spasev 55 Grade: 6
Grade report for grade 9:
151020 Stefan Andonov 89 Grade: 9*/

//INPUT2
/*151020 Stefan Andonov 89
151021 Vlatko Spasev 55
----
6*/
//OUTPUT2
/*All students:
151020 Stefan Andonov 89 Grade: 9
151021 Vlatko Spasev 55 Grade: 6
Grade report for grade 6:
151021 Vlatko Spasev 55 Grade: 6*/

//INPUT3
/*151020 Stefan Andonov 89
151021 Vlatko Spasev 55
----
7*/
//OUTPUT3
/*All students:
151020 Stefan Andonov 89 Grade: 9
151021 Vlatko Spasev 55 Grade: 6
Grade report for grade 7:
None8?

//INPUT4
/*151020 Stefan Andonov 39
151021 Vlatko Spasev 55
----
6*/
//OUTPUT4
/*Student with id 151020 failed the course
All students:
151021 Vlatko Spasev 55 Grade: 6
Grade report for grade 6:
151021 Vlatko Spasev 55 Grade: 6*/

//INPUT5
/*123 John Doe 95
124 Jane Smith 85
125 Jim Brown 75
126 Jake White 65
127 Judy Green 45
128 Jack Black 55
129 Jill Blue 82
----
9*/
//OUTPUT5
/*Student with id 127 failed the course
All students:
123 John Doe 95 Grade: 10
124 Jane Smith 85 Grade: 9
125 Jim Brown 75 Grade: 8
126 Jake White 65 Grade: 7
128 Jack Black 55 Grade: 6
129 Jill Blue 82 Grade: 9
Grade report for grade 9:
124 Jane Smith 85 Grade: 9
129 Jill Blue 82 Grade: 9*/

//INPUT6
/*201 Alice Johnson 92
202 Bob Miller 87
203 Charlie Davis 60
204 David Wilson 78
205 Emma Harris 50
206 Frank Clark 49
207 Grace Lewis 85
----
10*/
//OUTPUT6
/*Student with id 206 failed the course
All students:
201 Alice Johnson 92 Grade: 10
202 Bob Miller 87 Grade: 9
203 Charlie Davis 60 Grade: 7
204 David Wilson 78 Grade: 8
205 Emma Harris 50 Grade: 6
207 Grace Lewis 85 Grade: 9
Grade report for grade 10:
201 Alice Johnson 92 Grade: 10*/

//INPUT7
/*301 Henry King 50
302 Irene Wright 67
303 Jack Turner 72
304 Karen Phillips 81
305 Larry Scott 53
306 Molly Adams 90
307 Nancy Baker 88
----
8*/
//OUTPUT7
/*All students:
301 Henry King 50 Grade: 6
302 Irene Wright 67 Grade: 7
303 Jack Turner 72 Grade: 8
304 Karen Phillips 81 Grade: 9
305 Larry Scott 53 Grade: 6
306 Molly Adams 90 Grade: 10
307 Nancy Baker 88 Grade: 9
Grade report for grade 8:
303 Jack Turner 72 Grade: 8*/

//INPUT8
/*401 Olivia Hall 79
402 Paul Allen 95
403 Quincy Young 84
404 Rachel Hernandez 56
405 Samuel Martinez 50
406 Teresa Roberts 73
407 Ursula Moore 62
----
7*/
//OUTPUT8
/*All students:
401 Olivia Hall 79 Grade: 8
402 Paul Allen 95 Grade: 10
403 Quincy Young 84 Grade: 9
404 Rachel Hernandez 56 Grade: 6
405 Samuel Martinez 50 Grade: 6
406 Teresa Roberts 73 Grade: 8
407 Ursula Moore 62 Grade: 7
Grade report for grade 7:
407 Ursula Moore 62 Grade: 7*/

//INPUT9
/*701 Jack Kelly 55
702 Laura Bennett 75
703 Michael Russell 87
704 Nora Watson 70
705 Owen Patterson 89
706 Piper Richardson 83
707 Quinn Cox 88
----
9*/
//OUTPUT9
/*All students:
701 Jack Kelly 55 Grade: 6
702 Laura Bennett 75 Grade: 8
703 Michael Russell 87 Grade: 9
704 Nora Watson 70 Grade: 8
705 Owen Patterson 89 Grade: 9
706 Piper Richardson 83 Grade: 9
707 Quinn Cox 88 Grade: 9
Grade report for grade 9:
703 Michael Russell 87 Grade: 9
705 Owen Patterson 89 Grade: 9
706 Piper Richardson 83 Grade: 9
707 Quinn Cox 88 Grade: 9*/

//INPUT10
/*1001 Alice Johnson 92
1002 Bob Miller 87
1003 Charlie Davis 60
1004 David Wilson 78
1005 Emma Harris 50
1006 Frank Clark 49
1007 Grace Lewis 85
1008 Henry King 45
1009 Irene Wright 67
1010 Jack Turner 72
1011 Karen Phillips 81
1012 Larry Scott 53
1013 Molly Adams 90
1014 Nancy Baker 88
1015 Olivia Hall 79
1016 Paul Allen 95
1017 Quincy Young 84
1018 Rachel Hernandez 56
1019 Samuel Martinez 49
1020 Teresa Roberts 73
----
8*/
//OUTPUT10
/*Student with id 1006 failed the course
Student with id 1008 failed the course
Student with id 1019 failed the course
All students:
1001 Alice Johnson 92 Grade: 10
1002 Bob Miller 87 Grade: 9
1003 Charlie Davis 60 Grade: 7
1004 David Wilson 78 Grade: 8
1005 Emma Harris 50 Grade: 6
1007 Grace Lewis 85 Grade: 9
1009 Irene Wright 67 Grade: 7
1010 Jack Turner 72 Grade: 8
1011 Karen Phillips 81 Grade: 9
1012 Larry Scott 53 Grade: 6
1013 Molly Adams 90 Grade: 10
1014 Nancy Baker 88 Grade: 9
1015 Olivia Hall 79 Grade: 8
1016 Paul Allen 95 Grade: 10
1017 Quincy Young 84 Grade: 9
1018 Rachel Hernandez 56 Grade: 6
1020 Teresa Roberts 73 Grade: 8
Grade report for grade 8:
1004 David Wilson 78 Grade: 8
1010 Jack Turner 72 Grade: 8
1015 Olivia Hall 79 Grade: 8
1020 Teresa Roberts 73 Grade: 8*/
