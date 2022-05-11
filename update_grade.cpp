#include "linked_list.h"
#include <iostream>

void update_grade(Node *list_head) {
    string line;
    int student_ID;
    cout << "Enter student ID : ";
    cin >> line;
    student_ID = stoi(line);

    Node *traversePtr = list_head;
    bool student_found = false;
    while(traversePtr != NULL) {
        if(traversePtr->student.ID == student_ID) {
            student_found = true;
            break;
        }
        traversePtr = traversePtr->next;
    }
    cout << "Which grade would you like to change? (1-12) : ";
    cin >> line;
        bool is_int = true;
        for(int i = 0; i < line.length(); i++) {
            if(isdigit(line[i]) == 0) {
                is_int = false;
            }
        }
        int action;
        if(is_int) {
            action = stoi(line);
        } else {
            action = 0;
        }
        if(action < 1 || action > 11) {
            cout << "invalid input\n";
        } else {
            cout << "Enter new grade : ";
            cin >> line;
            traversePtr->student.grades[action - 1] = stof(line);
        }
}
