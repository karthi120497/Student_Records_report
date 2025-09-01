#include <iostream>
using namespace std;

class Student {
    string name;
    int rollNo;
    float marks[3];
    float total, average;
    char grade;

public:
    void input() {
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        total = 0;
        cout << "Enter marks for 3 subjects:\n";
        for (int i = 0; i < 3; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
            total += marks[i];
        }

        average = total / 3;
        if (average >= 90)
            grade = 'A';
        else if (average >= 75)
            grade = 'B';
        else if (average >= 60)
            grade = 'C';
        else if (average >= 40)
            grade = 'D';
        else
            grade = 'F';
    }

    void displayReportCard() const {
        cout << "\n--- Report Card ---\n";
        cout << "Name     : " << name << endl;
        cout << "Roll No  : " << rollNo << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Subject " << i + 1 << " Marks: " << marks[i] << endl;
        }
        cout << "Total    : " << total << endl;
        cout << "Average  : " << average << endl;
        cout << "Grade    : " << grade << endl;
        cout << "--------------------\n";
    }

    int getRollNo() const {
        return rollNo;
    }
};

int main() {
    const int MAX = 100;
    Student students[MAX];
    int count = 0;
    int choice;

    do {
        cout << "\n===== Student Report Card Menu =====\n";
        cout << "1. Add Student\n";
        cout << "2. View All Report Cards\n";
        cout << "3. Edit Student Record\n";
        cout << "4. Delete Student Record\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (count < MAX) {
                cout << "\nEnter details for Student " << count + 1 << ":\n";
                students[count].input();
                count++;
            } else {
                cout << "Student limit reached!\n";
            }
        } else if (choice == 2) {
            if (count == 0) {
                cout << "No records to display.\n";
            } else {
                for (int i = 0; i < count; i++) {
                    students[i].displayReportCard();
                }
            }
        } else if (choice == 3) {
            int roll, found = 0;
            cout << "Enter roll number to edit: ";
            cin >> roll;
            for (int i = 0; i < count; i++) {
                if (students[i].getRollNo() == roll) {
                    cout << "Enter new details:\n";
                    students[i].input();
                    found = 1;
                    break;
                }
            }
            if (!found)
                cout << "Record not found!\n";
        } else if (choice == 4) {
            int roll, found = 0;
            cout << "Enter roll number to delete: ";
            cin >> roll;
            for (int i = 0; i < count; i++) {
                if (students[i].getRollNo() == roll) {
                    // Shift all elements left to delete
                    for (int j = i; j < count - 1; j++) {
                        students[j] = students[j + 1];
                    }
                    count--;
                    found = 1;
                    cout << "Record deleted.\n";
                    break;
                }
            }
            if (!found)
                cout << "Record not found!\n";
        } else if (choice == 0) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
