#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the average
float calculateAverage(float grade1, float grade2, float grade3) {
    return (grade1 + grade2 + grade3) / 3;
}

// Function to check the student's status
string checkStatus(float average, float attendance) {
    if (average >= 7.0 && attendance >= 75.0) {
        return "Approved";
    } else if (average >= 7.0 && attendance < 75.0) {
        return "Approved with insufficient attendance";
    } else if (average < 7.0 && attendance >= 75.0) {
        return "Failed due to average";
    } else {
        return "Failed due to average and attendance";
    }
}

int main() {
    int numStudents;

    // Ask for the number of students
    cout << "Enter the number of students: ";
    cin >> numStudents;

    // Vectors to store student data: names, grades, attendance, and status
    vector<string> names(numStudents);
    vector<float> grade1(numStudents), grade2(numStudents), grade3(numStudents), attendance(numStudents);
    vector<float> averages(numStudents);
    vector<string> statuses(numStudents);

    // Input data for each student
    for (int i = 0; i < numStudents; i++) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "Name: ";
        cin.ignore();  // Clears the input buffer
        getline(cin, names[i]);

        cout << "Grade 1: ";
        cin >> grade1[i];

        cout << "Grade 2: ";
        cin >> grade2[i];

        cout << "Grade 3: ";
        cin >> grade3[i];

        cout << "Attendance (%): ";
        cin >> attendance[i];

        // Calculate the average for the student
        averages[i] = calculateAverage(grade1[i], grade2[i], grade3[i]);

        // Check the student's status
        statuses[i] = checkStatus(averages[i], attendance[i]);
    }

    // Display the results
    cout << "\n\nStudent Status Report:\n";
    for (int i = 0; i < numStudents; i++) {
        cout << "\nStudent: " << names[i] << endl;
        cout << "Average: " << averages[i] << endl;
        cout << "Attendance: " << attendance[i] << "%" << endl;
        cout << "Status: " << statuses[i] << endl;
    }

    return 0;
}

