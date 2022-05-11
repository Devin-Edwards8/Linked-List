#include "linked_list.h"
#include <iostream>

void delete_student(Node *list_head) {
    string line;
    int student_ID;
    bool student_found = false;
    cout << "Enter student's ID : ";
    cin >> line;
    student_ID = stoi(line);

    Node *prevPtr = list_head;
    Node *traversePtr = prevPtr->next;
    while(traversePtr != NULL) {
        if(traversePtr->student.ID == student_ID) {
            student_found = true;
            line = traversePtr->student.name;
            prevPtr->next = traversePtr->next;
            free(traversePtr);
            break;
        }
        prevPtr = traversePtr;
        traversePtr = traversePtr->next;
    }
    if(student_found) {
        cout << "Deleted records for " << line << "\n";
    } else {
        cout << "No student for that ID\n";
    }
}
