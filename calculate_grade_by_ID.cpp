#include "linked_list.h"
#include <iostream>
#include <string>

void calculate_grade_by_ID(Node *list_head) {
    Node *traversePtr = list_head;
    float weights[4] = {.25, .25, .25, .25};
    string line;
    int student_ID;
    cout << "Are grades weighted? ";
    cin >> line;
    if(line == "yes") {
        cout << "Enter weight of quizzes : ";
        cin >> line;
        weights[0] = stof(line);
        cout << "Enter weight of midterms : ";
        cin >> line;
        weights[1] = stof(line);
        cout << "Enter weight of homeworks : ";
        cin >> line;
        weights[2] = stof(line);
        cout << "Enter weight of finals : ";
        cin >> line;
        weights[3] = stof(line);
    }
    bool ignore;
    cout << "Ignore Incomplete Grades? ";
    cin >> line;
    if(line == "yes") {
        ignore = true;
    } else {
        ignore = false;
    }
    
    cout << "Enter student's ID : ";
    cin >> line;
    student_ID = stoi(line);

    bool student_found = false;
    while(traversePtr != NULL) {
        if(traversePtr->student.ID == student_ID) {
            student_found = true;
            break;
        }
        traversePtr = traversePtr->next;
    }
    if(student_found) {
        float grade = calc_total(traversePtr->student.grades, weights, ignore);
        cout << "Final Grade for " << traversePtr->student.name << ": " << grade << "\n";
    } else {
        cout << "Student not found with ID : " << student_ID << "\n";
    }
}
