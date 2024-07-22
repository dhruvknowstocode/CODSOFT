#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class student {
public:
    string Name;
    int Grade;
};
bool compareGrades(const student& x, const student& y) {
    return x.Grade < y.Grade;
}
int main() {
    using namespace std;
    vector<student> students;
    int totalnumberofstudents;
    cout << "Enter total number of students in the class: ";
    cin >> totalnumberofstudents;
    for (int i = 0; i < totalnumberofstudents; ++i) {
        student student;
        cout << "\nEnter Name of student " << i+1 << ": ";
        cin >> student.Name;
        cout << "Enter Grade for " << student.Name << ": ";
        cin >> student.Grade;
        students.push_back(student);
    }
    if (students.empty()) {
        cout << "No data entered. Exiting." << endl;
        return 0;
    }
    double sum = 0;
    int HighestGrade = students[0].Grade;
    int LowerGrade = students[0].Grade;
    for (const student& student : students) {
        sum += student.Grade;
        HighestGrade = max(HighestGrade, student.Grade);
        LowerGrade = min(LowerGrade, student.Grade);
    }
    double average = sum / students.size();
    sort(students.begin(), students.end(), compareGrades);
    cout << "\nFinal Grade list of students :\n";
    for (const student& student : students) {
        cout <<"Score of"<< student.Name <<"is"<<":"<< student.Grade << endl;
    }
    cout << "Average Grade is :" << average << endl;
    cout << "Highest Grade is :" << HighestGrade << endl;
    cout << "Lowest Grade is :" << LowerGrade << endl;
    return 0;
}
