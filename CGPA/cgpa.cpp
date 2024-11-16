#include <iostream>
#include <vector>
using namespace std;

class Subject {
public:
    string subjectname;
    int credits;
    float gradepoints;

    // Constructor
    Subject(string sn, int cr, float gr) {
        subjectname = sn;
        credits = cr;
        gradepoints = gr;
    }
};

class Student {
public:
    string name;
    vector<Subject> subjects;

    // Constructor
    Student(string studentname) {
        name = studentname;
    }

    // Method to add a subject
    void addsubject(string subjectname, int credits, float gradepoint) {
        Subject newsubject(subjectname, credits, gradepoint);
        subjects.push_back(newsubject);
    }

    // Method to calculate CGPA
    float calculatecgpa() {
        int totalcredit = 0;
        float weightgradepoint = 0;
        for (const Subject &subject : subjects) {
            totalcredit += subject.credits;
            weightgradepoint += subject.credits * subject.gradepoints;
        }
        return (totalcredit > 0) ? (weightgradepoint / totalcredit) : 0;
    }

    // Method to display CGPA
    void displaycgpa() {
        cout << "Student name: " << name << endl;
        float cgpa = calculatecgpa();
        cout << "CGPA: " << cgpa << endl;
    }
};

int main() {
    string studentname;
    int numsub;

    cout << "Enter the student name: ";
    getline(cin, studentname);

    cout << "Enter the number of subjects: ";
    cin >> numsub;

    Student student(studentname);

    for (int i = 0; i < numsub; i++) {
        string subjectname;
        int credits;
        float gradepoints;

        cout << "Enter the subject's name: ";
        cin.ignore();
        getline(cin, subjectname);

        cout << "Enter the credits: ";
        cin >> credits;

        cout << "Enter the gradepoints: ";
        cin >> gradepoints;

        student.addsubject(subjectname, credits, gradepoints);
    }

    student.displaycgpa();
    return 0;
}
